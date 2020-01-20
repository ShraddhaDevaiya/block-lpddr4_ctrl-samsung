//=============================================================================
// Release information
// Design version: sifive_sesame_rel3_190711
// Document version: OMC-V1.4-UG-R2.11, OMC-V1.4-IG-R1.00-SESAME
// Release generated at Thu Jul 11 15:30:19 2019
//=============================================================================

// ============================================================================
// Description:    
  //---------------------- mo control -----------------
  // 0: bypass, 1:armo==1, 2:awmo==1, 3:(armo+awmo)==1
  // awmo==1 include awwlmo==1 and WafterAW
  //---------------------- id_keep --------------------
  // save ID to fifo --> issue fixed zero ID --> restore response ID
  //---------------------- monitor --------------------
  // 1. is single id
  // 2. response id violation
  // 3. wlast checker
  // 4. rlast checker
  // 5. happen error response
  // 6. armo
  // 7. awmo
  // 8. awwlmo
  // 9. pending status(arv & !r) (awv & !r) (wv & !r) (rv & !r) (bv & !r)
  // 10. read valid/ready signal: arvalid, r, rvalid, r, rlast
  // 11. write valid/ready signal: awvalid, r, wvalid, r, wlast, bvalid, r
// =============================================================================

`ifndef __OIC_FPGA_DBG__
`define __OIC_FPGA_DBG__

`include "oic_define.h"

module oic_fpga_dbg_ctl #(
  parameter ID_WIDTH     = 4,
  parameter ADDR_WIDTH   = 32,
  parameter USER_WIDTH   = 1,
  parameter DATA_WIDTH   = 32,

  parameter MAX_AWMO     = 32,
  parameter MAX_ARMO     = 32,
  parameter MAX_AWWLMO   = 16,
  parameter DBG_ID       = 3'd0,
  parameter SW_STABLE_TH = 1000,
  // auto calculated
  parameter WSTRB_WIDTH  = DATA_WIDTH / 8,
  parameter `calc_ceil_of_log2_of_depth(MAX_SIZE, WSTRB_WIDTH),
  parameter `calc_ceil_of_log2_of_depth(AWMO_WIDTH, MAX_AWMO + 1),
  parameter `calc_ceil_of_log2_of_depth(ARMO_WIDTH, MAX_ARMO + 1),
  parameter `calc_ceil_of_log2_of_depth(AWWLMO_WIDTH, MAX_AWWLMO + 1)
)(
  input  clk, reset_n,
  orbit_if_AXI.si si,
  orbit_if_AXI.mi mi,
  input  [3:0] sw,
  output [7:0] led
);

  //---------------------- led_sel, dbg_sel, ctl_sel selection -------------------------------------
  logic [3:0] sw_sync;
  orbit_lib_synchronizer #(.BIT_WIDTH(4)) u_sync_sw (clk, reset_n, sw, sw_sync);

  logic set_reg;
  logic [15:0] stable_cnt;

  always @ (posedge clk, negedge reset_n) begin
    if(~reset_n) set_reg <= 0;
    else         set_reg <= sw_sync[0];
  end
  logic sw_0_rise, sw_0_fall;
  assign sw_0_rise = ~set_reg & sw_sync[0];
  assign sw_0_fall = set_reg & ~sw_sync[0];

  always @ (posedge clk, negedge reset_n) begin
    if(~reset_n) stable_cnt <= 0;
    else begin
      if(sw_0_rise | sw_0_fall) 
        stable_cnt <= 0;
      else if(stable_cnt <= SW_STABLE_TH) 
        stable_cnt <= stable_cnt + 1;
    end
  end

  logic enable_debugger;
  logic set_dbg_sel, set_ctl_sel;
  assign set_dbg_sel = set_reg && (stable_cnt == SW_STABLE_TH);
  assign set_ctl_sel = ~set_reg && (stable_cnt == SW_STABLE_TH) && enable_debugger;

  logic [2:0] led_sel, dbg_sel, ctl_sel;
  assign led_sel = sw_sync[3:1];
  always @ (posedge clk, negedge reset_n) begin
    if(~reset_n) dbg_sel <= 0;
    else if(set_dbg_sel) dbg_sel <= sw_sync[3:1];
  end
  always @ (posedge clk, negedge reset_n) begin
    if(~reset_n) ctl_sel <= 0;
    else if(set_ctl_sel) ctl_sel <= sw_sync[3:1];
  end

  assign enable_debugger = (dbg_sel == DBG_ID) ? 1'b1 : 1'b0;

  //---------------------- led output ------------------------------
  logic [7:0] mon[0:7];
  assign led = (enable_debugger) ? mon[led_sel] : 0;

  //---------------------- pass & pend ----------------------------
  logic aw_pass_s, w_pass_s, wl_pass_s, b_pass_s;
  logic ar_pass_s, r_pass_s, rl_pass_s;          
  logic aw_pend_s, w_pend_s, b_pend_s;
  logic ar_pend_s, r_pend_s;
  assign aw_pass_s = si.AWVALID & si.AWREADY;
  assign  w_pass_s = si.WVALID & si.WREADY;
  assign wl_pass_s = w_pass_s & si.WLAST;
  assign  b_pass_s = si.BVALID & si.BREADY;
  assign aw_pend_s = si.AWVALID & ~si.AWREADY;
  assign  w_pend_s = si.WVALID & ~si.WREADY;
  assign  b_pend_s = si.BVALID & ~si.BREADY;

  assign ar_pass_s = si.ARVALID & si.ARREADY;
  assign  r_pass_s = si.RVALID & si.RREADY;
  assign rl_pass_s = r_pass_s & si.RLAST;
  assign ar_pend_s = si.ARVALID & ~si.ARREADY;
  assign  r_pend_s = si.RVALID & ~si.RREADY;

  //-- awwl_fifo, w after aw -------
  logic awwl_fifo_full_n, awwl_fifo_empty_n, dummy_empty;
  logic [3:0] awlen_2_wl;
  AsyncFIFO #(4, MAX_AWWLMO, `IS_SYNC1x1) awwl_fifo (clk, reset_n, aw_pass_s, awwl_fifo_full_n, si.AWLEN, clk, reset_n, awwl_fifo_empty_n, wl_pass_s, awlen_2_wl, dummy_empty);
  
  //-- mo count --------------------
  logic [AWMO_WIDTH -1:0]   awmo  ; logic awmo_block  ;
  logic [ARMO_WIDTH -1:0]   armo  ; logic armo_block  ;
  logic [AWWLMO_WIDTH -1:0] awwlmo; logic awwlmo_block;
  always @ (posedge clk, negedge reset_n) begin
    if(!reset_n) awmo <= 0;
    else if(aw_pass_s & !b_pass_s)  awmo <= awmo +1;
    else if(!aw_pass_s & b_pass_s)  awmo <= awmo -1;
  end
  assign awmo_block = ~awwl_fifo_full_n || (awmo == MAX_AWMO) || ( ((ctl_sel[2:1] == 2) || (ctl_sel[2:1] == 3)) && (awmo > 0) );
  always @ (posedge clk, negedge reset_n) begin
    if(!reset_n) awwlmo <= 0;
    else if(aw_pass_s & !wl_pass_s)  awwlmo <= awwlmo +1;
    else if(!aw_pass_s & wl_pass_s)  awwlmo <= awwlmo -1;
  end
  assign awwlmo_block = ~awwl_fifo_empty_n;// || (awwlmo == MAX_AWWLMO) || ( ((ctl_sel[2:1] == 2) || (ctl_sel[2:1] == 3)) && (awwlmo > 0) );
  always @ (posedge clk, negedge reset_n) begin
    if(!reset_n) armo <= 0;
    else if(ar_pass_s & !rl_pass_s)  armo <= armo +1;
    else if(!ar_pass_s & rl_pass_s)  armo <= armo -1;
  end
  assign armo_block = (armo == MAX_ARMO) || ( ((ctl_sel[2:1] == 1) || (ctl_sel[2:1] == 3)) && (armo > 0) );
  
  //-- id_keep ------------------
  logic awid_fifo_full_n, awid_fifo_empty_n, dummy_empty2;
  logic arid_fifo_full_n, arid_fifo_empty_n, dummy_empty3;
  logic [ID_WIDTH -1:0] bid, rid;
  AsyncFIFO #(ID_WIDTH, MAX_AWMO, `IS_SYNC1x1) awid_fifo (clk, reset_n, aw_pass_s, awid_fifo_full_n, si.AWID, clk, reset_n, awid_fifo_empty_n,  b_pass_s, bid, dummy_empty2);
  AsyncFIFO #(ID_WIDTH, MAX_ARMO, `IS_SYNC1x1) arid_fifo (clk, reset_n, ar_pass_s, arid_fifo_full_n, si.ARID, clk, reset_n, arid_fifo_empty_n, rl_pass_s, rid, dummy_empty3);

  //-- flow control -------------------
  assign si.AWREADY  = mi.AWREADY & ~awmo_block  ;
  assign mi.AWVALID  = si.AWVALID & ~awmo_block  ;
  assign si.WREADY   = mi.WREADY  & ~awwlmo_block;
  assign mi.WVALID   = si.WVALID  & ~awwlmo_block;
  assign si.ARREADY  = mi.ARREADY & ~armo_block  ;
  assign mi.ARVALID  = si.ARVALID & ~armo_block  ;
  assign mi.RREADY   = si.RREADY                 ;
  assign si.RVALID   = mi.RVALID                 ;
  assign mi.BREADY   = si.BREADY                 ;
  assign si.BVALID   = mi.BVALID                 ;

  assign mi.ARQOS    = si.ARQOS                  ;
  assign mi.ARLEN    = si.ARLEN                  ;
  assign mi.ARID     = ctl_sel[0] ? 0 : si.ARID  ;
  assign mi.ARADDR   = si.ARADDR                 ;
  assign mi.ARSIZE   = si.ARSIZE                 ;
  assign mi.ARBURST  = si.ARBURST                ;
  assign mi.ARCACHE  = si.ARCACHE                ;
  assign mi.ARPROT   = si.ARPROT                 ;
  assign mi.ARLOCK   = si.ARLOCK                 ;
  assign mi.ARSNOOP  = si.ARSNOOP                ;
  assign mi.ARDOMAIN = si.ARDOMAIN               ;
  assign mi.ARBAR    = si.ARBAR                  ;
  assign mi.ARUSER   = si.ARUSER                 ;

  assign mi.AWQOS    = si.AWQOS                  ;
  assign mi.AWLEN    = si.AWLEN                  ;
  assign mi.AWID     = ctl_sel[0] ? 0 : si.AWID  ;
  assign mi.AWADDR   = si.AWADDR                 ;
  assign mi.AWSIZE   = si.AWSIZE                 ;
  assign mi.AWBURST  = si.AWBURST                ;
  assign mi.AWCACHE  = si.AWCACHE                ;
  assign mi.AWPROT   = si.AWPROT                 ;
  assign mi.AWLOCK   = si.AWLOCK                 ;
  assign mi.AWSNOOP  = si.AWSNOOP                ;
  assign mi.AWDOMAIN = si.AWDOMAIN               ;
  assign mi.AWBAR    = si.AWBAR                  ;
  assign mi.AWUSER   = si.AWUSER                 ;

  assign mi.WID      = ctl_sel[0] ? 0 : si.WID   ;
  assign mi.WSTRB    = si.WSTRB                  ;
  assign mi.WDATA    = si.WDATA                  ;
  assign mi.WLAST    = si.WLAST                  ;

  assign si.RID      = ctl_sel[0] ? rid : mi.RID ;
  assign si.RRESP    = mi.RRESP                  ;
  assign si.RDATA    = mi.RDATA                  ;
  assign si.RLAST    = mi.RLAST                  ;
  assign si.RUSER    = mi.RUSER                  ;

  assign si.BID      = ctl_sel[0] ? bid : mi.BID ;
  assign si.BRESP    = mi.BRESP                  ;
  assign si.BUSER    = mi.BUSER                  ;

  //-------------------------
  //-- monitor --------------
  //-------------------------
  // error response monitoryy
  logic err_resp;
  always @ (posedge clk, negedge reset_n) begin
    if(~reset_n) err_resp <= 0;
    else begin
      if(b_pass_s && (si.BRESP != 0)) err_resp <= 1'b1;
      else if(r_pass_s && (si.RRESP != 0)) err_resp <= 1'b1;
    end
  end

  // wlast checker
  logic [3:0] w_cnt;
  always @ (posedge clk, negedge reset_n) begin
    if(~reset_n) w_cnt <= 0;
    else begin
      if(wl_pass_s) w_cnt <= 0;
      else if(w_pass_s) w_cnt <= w_cnt + 1;
    end
  end
  logic wl_vio;
  always @ (posedge clk, negedge reset_n) begin
    if(~reset_n) wl_vio <= 0;
    else begin
      if(wl_pass_s && (w_cnt != awlen_2_wl)) wl_vio <= 1;
    end
  end
  
  // aw_cam, ar_cam
  logic aw_cam_match, ar_cam_match;
  logic dummy_payld;
  logic [3:0] rlen;
  logic is_new_awid, is_new_arid;
  oic_cam #(MAX_AWMO, 1, ID_WIDTH) aw_cam (clk, reset_n, aw_pass_s, si.AWID, 1'b0    ,  b_pass_s, si.BID, aw_cam_match, dummy_payld, 0       , 0     , is_new_awid);
  oic_cam #(MAX_ARMO, 4, ID_WIDTH) ar_cam (clk, reset_n, ar_pass_s, si.ARID, si.ARLEN, rl_pass_s, si.RID, ar_cam_match, rlen       , r_pass_s, rlen-1, is_new_arid);

  // resp id checker
  logic bid_vio, rid_vio;
  always @ (posedge clk, negedge reset_n) begin
    if(~reset_n) bid_vio <= 0;
    else begin
      if(si.BVALID && ~aw_cam_match) bid_vio <= 1;
    end
  end
  always @ (posedge clk, negedge reset_n) begin
    if(~reset_n) rid_vio <= 0;
    else begin
      if(si.RVALID && ~ar_cam_match) rid_vio <= 1;
    end
  end

  // rlast checker
  logic rl_vio;
  always @ (posedge clk, negedge reset_n) begin
    if(~reset_n) rl_vio <= 0;
    else begin
      if(si.RVALID && si.RLAST && (rlen != 0)) rl_vio <= 1;
    end
  end

  // single id checker
  logic is_single_awid, is_single_arid;
  always @ (posedge clk, negedge reset_n) begin
    if(~reset_n) is_single_awid <= 1;
    else begin
      if(awmo > 0 && aw_pass_s && is_new_awid) is_single_awid <= 0;
    end
  end
  always @ (posedge clk, negedge reset_n) begin
    if(~reset_n) is_single_arid <= 1;
    else begin
      if(armo > 0 && ar_pass_s && is_new_arid) is_single_arid <= 0;
    end
  end

  // uniq id checker
  logic is_uniq_awid, is_uniq_arid;
  always @ (posedge clk, negedge reset_n) begin
    if(~reset_n) is_uniq_awid <= 1;
    else begin
      if(aw_pass_s && ~is_new_awid) is_uniq_awid <= 0;
    end
  end
  always @ (posedge clk, negedge reset_n) begin
    if(~reset_n) is_uniq_arid <= 1;
    else begin
      if(ar_pass_s && ~is_new_arid) is_uniq_arid <= 0;
    end
  end

  // request cnt
  logic [31:0] ar_cnt, aw_cnt;
  always @ (posedge clk, negedge reset_n) begin
    if(~reset_n) aw_cnt <= 0;
    else begin
      if(aw_pass_s) aw_cnt <= aw_cnt + 1;
    end
  end
  always @ (posedge clk, negedge reset_n) begin
    if(~reset_n) ar_cnt <= 0;
    else begin
      if(ar_pass_s) ar_cnt <= ar_cnt + 1;
    end
  end

  // mo over
  logic armo_over, awmo_over;
  always @ (posedge clk, negedge reset_n) begin
    if(~reset_n) awmo_over <= 0;
    else begin
      if(si.AWVALID && (awmo == MAX_AWMO)) awmo_over <= 1;
    end
  end
  always @ (posedge clk, negedge reset_n) begin
    if(~reset_n) armo_over <= 0;
    else begin
      if(si.ARVALID && (armo == MAX_ARMO)) armo_over <= 1;
    end
  end


  // mon signal assign
  assign mon[0] = {aw_cnt[8], DBG_ID[2:0], ar_cnt[8], ctl_sel};
  assign mon[1] = {is_uniq_awid, is_uniq_arid, is_single_awid & is_single_arid, bid_vio, rid_vio, wl_vio, rl_vio, err_resp};
  assign mon[2] = armo;
  assign mon[3] = awmo;
  assign mon[4][7:6] = {awmo_over, armo_over};
  assign mon[4][5:0] = awwlmo;
  assign mon[5] = {aw_cnt[9], ar_cnt[10:9], ar_pend_s, aw_pend_s, w_pend_s, r_pend_s, b_pend_s};
  assign mon[6] = aw_cnt[7:0];
  assign mon[7] = ar_cnt[7:0];
endmodule

module oic_fpga_dbg #(
  parameter ID_WIDTH     = 4,
  parameter ADDR_WIDTH   = 32,
  parameter USER_WIDTH   = 1,
  parameter DATA_WIDTH   = 32,

  parameter MAX_AWMO     = 128,
  parameter MAX_ARMO     = 128,
  parameter MAX_AWWLMO   = 128,
  //parameter DBG_ID       = 3'd0,
  //parameter SW_STABLE_TH = 1000,
  // auto calculated
  parameter WSTRB_WIDTH  = DATA_WIDTH / 8,
  parameter `calc_ceil_of_log2_of_depth(MAX_SIZE, WSTRB_WIDTH),
  parameter `calc_ceil_of_log2_of_depth(AWMO_WIDTH, MAX_AWMO + 1),
  parameter `calc_ceil_of_log2_of_depth(ARMO_WIDTH, MAX_ARMO + 1),
  parameter `calc_ceil_of_log2_of_depth(AWWLMO_WIDTH, MAX_AWWLMO + 1)
)(
  input  clk, reset_n,
  orbit_if_AXI.si si,
  orbit_if_AXI.mi mi,
  input  [7:0] sw,
  output [15:0] led
);

  //---------------------- switch input -------------------------------------
  logic [7:0] sw_sync;
  orbit_lib_synchronizer #(.BIT_WIDTH(8)) u_sync_sw (clk, reset_n, sw, sw_sync);
  logic [2:0] led_sel;
  assign led_sel = sw_sync[2:0];

  //---------------------- led output ------------------------------
  logic [15:0] mon[0:7];
  logic [15:0] led_reg;
  always @(posedge clk or negedge reset_n) begin
    if(~reset_n) led_reg <= 'hffff;
    else         led_reg <= mon[led_sel];
  end
  
  assign led = led_reg;

  //---------------------- cycle_cnt ------------------------------
  reg [63:0]  cycle_cnt;
  always @(posedge clk or negedge reset_n) begin
    if(~reset_n) cycle_cnt <= 'h0;
    else         cycle_cnt <= cycle_cnt + 1;
  end

  //---------------------- pass & pend ----------------------------
  logic aw_pass_s, w_pass_s, wl_pass_s, b_pass_s;
  logic ar_pass_s, r_pass_s, rl_pass_s;          
  logic aw_pend_s, w_pend_s, b_pend_s;
  logic ar_pend_s, r_pend_s;
  assign aw_pass_s = si.AWVALID & si.AWREADY;
  assign  w_pass_s = si.WVALID & si.WREADY;
  assign wl_pass_s = w_pass_s & si.WLAST;
  assign  b_pass_s = si.BVALID & si.BREADY;
  assign aw_pend_s = si.AWVALID & ~si.AWREADY;
  assign  w_pend_s = si.WVALID & ~si.WREADY;
  assign  b_pend_s = si.BVALID & ~si.BREADY;

  assign ar_pass_s = si.ARVALID & si.ARREADY;
  assign  r_pass_s = si.RVALID & si.RREADY;
  assign rl_pass_s = r_pass_s & si.RLAST;
  assign ar_pend_s = si.ARVALID & ~si.ARREADY;
  assign  r_pend_s = si.RVALID & ~si.RREADY;

  //-- awwl_fifo, w after aw -------
  logic awwl_fifo_full_n, awwl_fifo_empty_n, dummy_empty;
  logic [7:0] awlen_2_wl;
  AsyncFIFO #(8, MAX_AWWLMO, `IS_SYNC1x1) awwl_fifo (clk, reset_n, aw_pass_s, awwl_fifo_full_n, si.AWLEN, clk, reset_n, awwl_fifo_empty_n, wl_pass_s, awlen_2_wl, dummy_empty);
  
  //-- mo count --------------------
  logic [AWMO_WIDTH -1:0]   awmo  ;
  logic [ARMO_WIDTH -1:0]   armo  ;
  logic [AWWLMO_WIDTH -1:0] awwlmo;
  always @ (posedge clk, negedge reset_n) begin
    if(!reset_n) awmo <= 0;
    else if(aw_pass_s & !b_pass_s)  awmo <= awmo +1;
    else if(!aw_pass_s & b_pass_s)  awmo <= awmo -1;
  end
  always @ (posedge clk, negedge reset_n) begin
    if(!reset_n) awwlmo <= 0;
    else if(aw_pass_s & !wl_pass_s)  awwlmo <= awwlmo +1;
    else if(!aw_pass_s & wl_pass_s)  awwlmo <= awwlmo -1;
  end
  always @ (posedge clk, negedge reset_n) begin
    if(!reset_n) armo <= 0;
    else if(ar_pass_s & !rl_pass_s)  armo <= armo +1;
    else if(!ar_pass_s & rl_pass_s)  armo <= armo -1;
  end
  
  //-- flow control -------------------
  assign si.AWREADY  = mi.AWREADY                ;
  assign mi.AWVALID  = si.AWVALID                ;
  assign si.WREADY   = mi.WREADY                 ;
  assign mi.WVALID   = si.WVALID                 ;
  assign si.ARREADY  = mi.ARREADY                ;
  assign mi.ARVALID  = si.ARVALID                ;
  assign mi.RREADY   = si.RREADY                 ;
  assign si.RVALID   = mi.RVALID                 ;
  assign mi.BREADY   = si.BREADY                 ;
  assign si.BVALID   = mi.BVALID                 ;

  assign mi.ARQOS    = si.ARQOS                  ;
  assign mi.ARLEN    = si.ARLEN                  ;
  assign mi.ARID     = si.ARID  ;
  assign mi.ARADDR   = si.ARADDR                 ;
  assign mi.ARSIZE   = si.ARSIZE                 ;
  assign mi.ARBURST  = si.ARBURST                ;
  assign mi.ARCACHE  = si.ARCACHE                ;
  assign mi.ARPROT   = si.ARPROT                 ;
  assign mi.ARLOCK   = si.ARLOCK                 ;
  assign mi.ARSNOOP  = si.ARSNOOP                ;
  assign mi.ARDOMAIN = si.ARDOMAIN               ;
  assign mi.ARBAR    = si.ARBAR                  ;
  assign mi.ARUSER   = si.ARUSER                 ;

  assign mi.AWQOS    = si.AWQOS                  ;
  assign mi.AWLEN    = si.AWLEN                  ;
  assign mi.AWID     = si.AWID  ;
  assign mi.AWADDR   = si.AWADDR                 ;
  assign mi.AWSIZE   = si.AWSIZE                 ;
  assign mi.AWBURST  = si.AWBURST                ;
  assign mi.AWCACHE  = si.AWCACHE                ;
  assign mi.AWPROT   = si.AWPROT                 ;
  assign mi.AWLOCK   = si.AWLOCK                 ;
  assign mi.AWSNOOP  = si.AWSNOOP                ;
  assign mi.AWDOMAIN = si.AWDOMAIN               ;
  assign mi.AWBAR    = si.AWBAR                  ;
  assign mi.AWUSER   = si.AWUSER                 ;

  assign mi.WID      = si.WID   ;
  assign mi.WSTRB    = si.WSTRB                  ;
  assign mi.WDATA    = si.WDATA                  ;
  assign mi.WLAST    = si.WLAST                  ;

  assign si.RID      = mi.RID ;
  assign si.RRESP    = mi.RRESP                  ;
  assign si.RDATA    = mi.RDATA                  ;
  assign si.RLAST    = mi.RLAST                  ;
  assign si.RUSER    = mi.RUSER                  ;

  assign si.BID      = mi.BID ;
  assign si.BRESP    = mi.BRESP                  ;
  assign si.BUSER    = mi.BUSER                  ;

  //-------------------------
  //-- monitor --------------
  //-------------------------
  // error response monitoryy
  logic err_resp;
  always @ (posedge clk, negedge reset_n) begin
    if(~reset_n) err_resp <= 0;
    else begin
      if(b_pass_s && (si.BRESP != 0)) err_resp <= 1'b1;
      else if(r_pass_s && (si.RRESP != 0)) err_resp <= 1'b1;
    end
  end

  // wlast checker
  logic [7:0] wl_cnt;
  always @ (posedge clk, negedge reset_n) begin
    if(~reset_n) wl_cnt <= 0;
    else begin
      if(wl_pass_s) wl_cnt <= 0;
      else if(w_pass_s) wl_cnt <= wl_cnt + 1;
    end
  end
  logic wl_vio;
  always @ (posedge clk, negedge reset_n) begin
    if(~reset_n) wl_vio <= 0;
    else begin
      if(wl_pass_s && (wl_cnt != awlen_2_wl)) wl_vio <= 1;
    end
  end
  
  // aw_cam, ar_cam
  logic aw_cam_match, ar_cam_match;
  logic dummy_payld;
  logic [7:0] rlen;
  logic is_new_awid, is_new_arid;
  oic_cam #(MAX_AWMO, 1, ID_WIDTH) aw_cam (clk, reset_n, aw_pass_s, si.AWID, 1'b0    ,  b_pass_s, si.BID, aw_cam_match, dummy_payld, 0       , 0     , is_new_awid);
  oic_cam #(MAX_ARMO, 8, ID_WIDTH) ar_cam (clk, reset_n, ar_pass_s, si.ARID, si.ARLEN, rl_pass_s, si.RID, ar_cam_match, rlen       , r_pass_s, rlen-1, is_new_arid);

  // resp id checker
  logic bid_vio, rid_vio;
  always @ (posedge clk, negedge reset_n) begin
    if(~reset_n) bid_vio <= 0;
    else begin
      if(si.BVALID && ~aw_cam_match) bid_vio <= 1;
    end
  end
  always @ (posedge clk, negedge reset_n) begin
    if(~reset_n) rid_vio <= 0;
    else begin
      if(si.RVALID && ~ar_cam_match) rid_vio <= 1;
    end
  end

  // rlast checker
  logic rl_vio;
  always @ (posedge clk, negedge reset_n) begin
    if(~reset_n) rl_vio <= 0;
    else begin
      if(si.RVALID && si.RLAST && (rlen != 0)) rl_vio <= 1;
    end
  end

  // single id checker
  logic is_single_awid, is_single_arid;
  always @ (posedge clk, negedge reset_n) begin
    if(~reset_n) is_single_awid <= 1;
    else begin
      if(awmo > 0 && aw_pass_s && is_new_awid) is_single_awid <= 0;
    end
  end
  always @ (posedge clk, negedge reset_n) begin
    if(~reset_n) is_single_arid <= 1;
    else begin
      if(armo > 0 && ar_pass_s && is_new_arid) is_single_arid <= 0;
    end
  end

  // uniq id checker
  logic is_uniq_awid, is_uniq_arid;
  always @ (posedge clk, negedge reset_n) begin
    if(~reset_n) is_uniq_awid <= 1;
    else begin
      if(aw_pass_s && ~is_new_awid) is_uniq_awid <= 0;
    end
  end
  always @ (posedge clk, negedge reset_n) begin
    if(~reset_n) is_uniq_arid <= 1;
    else begin
      if(ar_pass_s && ~is_new_arid) is_uniq_arid <= 0;
    end
  end

  // request cnt
  logic [31:0] ar_cnt, aw_cnt;
  always @ (posedge clk, negedge reset_n) begin
    if(~reset_n) aw_cnt <= 0;
    else begin
      if(aw_pass_s) aw_cnt <= aw_cnt + 1;
    end
  end
  always @ (posedge clk, negedge reset_n) begin
    if(~reset_n) ar_cnt <= 0;
    else begin
      if(ar_pass_s) ar_cnt <= ar_cnt + 1;
    end
  end
  logic [31:0] r_cnt, w_cnt;
  always @ (posedge clk, negedge reset_n) begin
    if(~reset_n) w_cnt <= 0;
    else begin
      if(w_pass_s) w_cnt <= w_cnt + 1;
    end
  end
  always @ (posedge clk, negedge reset_n) begin
    if(~reset_n) r_cnt <= 0;
    else begin
      if(r_pass_s) r_cnt <= r_cnt + 1;
    end
  end

  // mo over
  logic armo_over, awmo_over;
  always @ (posedge clk, negedge reset_n) begin
    if(~reset_n) awmo_over <= 0;
    else begin
      if(si.AWVALID && (awmo == MAX_AWMO)) awmo_over <= 1;
    end
  end
  always @ (posedge clk, negedge reset_n) begin
    if(~reset_n) armo_over <= 0;
    else begin
      if(si.ARVALID && (armo == MAX_ARMO)) armo_over <= 1;
    end
  end


  // mon signal assign
  assign mon[0] = {cycle_cnt[23:16], sw_sync};
  assign mon[1] = {aw_cnt[15:0]};
  assign mon[2] = {ar_cnt[15:0]};
  assign mon[3] = {aw_cnt[15:8], ar_cnt[15:8]};
  assign mon[4] = {aw_cnt[15:8], w_cnt[15:8]};
  assign mon[5] = {ar_cnt[15:8], r_cnt[15:8]};
  assign mon[6] = {cycle_cnt[19:16], awmo[3:0], armo[3:0], awwlmo[3:0]};
  assign mon[7] = {ar_pend_s, 
                   aw_pend_s, 
                    w_pend_s, 
                    r_pend_s, 
                    b_pend_s, 
                   awmo_over, 
                   armo_over, 
                is_uniq_awid, 
                is_uniq_arid, 
              is_single_awid, 
              is_single_arid, 
                     bid_vio, 
                     rid_vio, 
                      wl_vio, 
                      rl_vio, 
                    err_resp};
endmodule

`include "oic_undef.h"
`endif

