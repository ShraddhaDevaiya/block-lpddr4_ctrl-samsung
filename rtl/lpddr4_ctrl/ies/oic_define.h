//=============================================================================
// Release information
// Design version: sifive_sesame_rel3_190711
// Document version: OMC-V1.4-UG-R2.11, OMC-V1.4-IG-R1.00-SESAME
// Release generated at Thu Jul 11 15:30:19 2019
//=============================================================================

// ============================================================================
// Description:    define file
// =============================================================================

`ifndef ORBIT_IC_DEFINE
`define ORBIT_IC_DEFINE

`define ORBIT_IC_VER 1.0
//`timescale 1ns/10ps

// type def or const
`define THIRST_MODE_OFF        3'd0
`define THIRST_MODE_MO_ONLY    3'd1
`define THIRST_MODE_LAT_ONLY   3'd2
`define THIRST_MODE_MO_OR_LAT  3'd3
`define THIRST_MODE_MO_AND_LAT 3'd4

`define RS_FULL   2'b11
`define RS_FWD    2'b01
`define RS_REV    2'b10
`define RS_BYPASS 2'b00
                            //=================================================================|
                            //  relation   | clk:clk2                    | tx_clk:rx_clk       |
                            //-------------|-----------------------------|---------------------|
`define IS_ASYNC   2'b11    //             | async(currently meaningless)| async               |
`define IS_SYNC2x1 2'b10    //  usage      | 2:1(currently meaningless)  | 2:1(don't use)      |
`define IS_SYNC1x2 2'b01    //             | 1:2                         | 1:2(don't use)      |
`define IS_SYNC1x1 2'b00    //             | 1:1                         | 1:1                 |
                            //-----------------------------------------------------------------|
                            // recommanded | "CLOCK_RATIO"               | "TX_RX_CLOCK_RATIO" |
                            // param name  |                             |                     |
                            //=================================================================|

// Error code define.
`define ERR_NO          4'h0    // default value.
`define ERR_FROM_SLAVE  4'h1    // C/S-node
`define ERR_DECODE      4'h2    // S-node
`define ERR_UNREACHABLE 4'h3
`define ERR_TIMEOUT     4'h4    // S-node
`define ERR_FIRE_DOOR   4'h5
`define ERR_NO_RESPONSE 4'h6
`define ERR_PARITY      4'h7
`define ERR_TZP         4'h8    // S-node
`define ERR_CHOP        4'h9    // C/S-node
`define ERR_BAR_TERM    4'ha    // C-node

`define E2E_TEST_MODE_AXI_S  2'b01
`define E2E_TEST_MODE_OMC_S  2'b10

// AXI protocol related
`define NO_ERR     2'b00
`define DECODE_ERR 2'b11
`define SLAVE_ERR  2'b10

`define BURST_FIXED 2'b00
`define BURST_INCR  2'b01
`define BURST_WRAP  2'b10

// AHB protocol related
`define AHB_TRANS_IDLE     2'b00
`define AHB_TRANS_BUSY     2'b01
`define AHB_TRANS_NONSEQ   2'b10
`define AHB_TRANS_SEQ      2'b11
`define AHB_HBURST_SINGLE  3'b000
`define AHB_HBURST_INCR    3'b001
`define AHB_HBURST_WRAP4   3'b010
`define AHB_HBURST_INCR4   3'b011
`define AHB_HBURST_WRAP8   3'b100
`define AHB_HBURST_INCR8   3'b101
`define AHB_HBURST_WRAP16  3'b110
`define AHB_HBURST_INCR16  3'b111
`define HRESP_OK           2'b00
`define HRESP_ERROR        2'b01
`define HRESP_RETRY        2'b10
`define HRESP_SPLIT        2'b11

// W channel position defines
`define POS_WLAST 0

// A channel position defines
`define POS_AWRITE A_PAYLD_WIDTH -1
`define POS_AQOS A_PAYLD_WIDTH -1 -DECODE_WIDTH -1 -: 4
`define POS_ADECODEINFO A_PAYLD_WIDTH -1 -1 -: DECODE_WIDTH
`define POS_AROUTEINFO ROUTE_WIDTH -1:0
`define POS_AID A_PAYLD_WIDTH -1 -DECODE_WIDTH -4 -4 -1 -: ID_WIDTH
`define POS_AADDR ADDR_WIDTH + 13 + 2 + 2 + USER_WIDTH + ROUTE_WIDTH -1 -: ADDR_WIDTH
`define POS_ALEN A_PAYLD_WIDTH -1 -DECODE_WIDTH -4 -1 -:4


// R channel position defines
`define POS_RROUTEINFO ROUTE_WIDTH - 1:0
`define POS_RLAST USER_WIDTH + ROUTE_WIDTH
`define POS_RID R_PAYLD_WIDTH -1 -: ID_WIDTH
`define POS_RRESP R_PAYLD_WIDTH - ID_WIDTH -1 -: 2

// B channel position defines
`define POS_BROUTEINFO ROUTE_WIDTH - 1:0
`define POS_BID B_PAYLD_WIDTH -1 -: ID_WIDTH
`define POS_BRESP B_PAYLD_WIDTH - ID_WIDTH -1 -: 2

// function macros
`define calc_ceil_of_log2_of_depth(result, source) \
  result = source ==   1  ?  0 : \
           source <=   2  ?  1 : \
           source <=   4  ?  2 : \
           source <=   8  ?  3 : \
           source <=  16  ?  4 : \
           source <=  32  ?  5 : \
           source <=  64  ?  6 : \
           source <=  128 ?  7 : \
           source <=  256 ?  8 : \
           source <=  512 ?  9 : \
           source <= 1024 ? 10 : \
           source <= 2048 ? 11 : \
           source <= 4096 ? 12 : \
           source <= 8192 ? 13 : 14

`define calc_cnt_bit_width(result, source) \
  result = source <   1  ?  0 : \
           source <   2  ?  1 : \
           source <   4  ?  2 : \
           source <   8  ?  3 : \
           source <  16  ?  4 : \
           source <  32  ?  5 : \
           source <  64  ?  6 : \
           source <  128 ?  7 : \
           source <  256 ?  8 : \
           source <  512 ?  9 : \
           source < 1024 ? 10 : \
           source < 2048 ? 11 : \
           source < 4096 ? 12 : \
           source < 8192 ? 13 : 14

`define get_upper_power_of_2(result, source) \
  result = source <=     2 ?     2 : \
           source <=     4 ?     4 : \
           source <=     8 ?     8 : \
           source <=    16 ?    16 : \
           source <=    32 ?    32 : \
           source <=    64 ?    64 : \
           source <=   128 ?   128 : \
           source <=   256 ?   256 : \
           source <=   512 ?   512 : \
           source <=  1024 ?  1024 : \
           source <=  2048 ?  2048 : \
           source <=  4096 ?  4096 : \
           source <=  8192 ?  8192 : \
           source <= 16384 ? 16384 : 16384

`define calc_cr_word_sel(result, source) \
  result = source <= (32* 1) ? 1 : \
           source <= (32* 2) ? 1 : \
           source <= (32* 4) ? 2 : \
           source <= (32* 8) ? 3 : \
           source <= (32*16) ? 4 : 5

//`define calc_sum_of_width(result, w, cnt) \
//  result = cnt ==  1 ? w[0] : \
//           cnt ==  2 ? w[0] + w[1] : \
//           cnt ==  3 ? w[0] + w[1] + w[2] : \
//           cnt ==  4 ? w[0] + w[1] + w[2] + w[3] : \
//           cnt ==  5 ? w[0] + w[1] + w[2] + w[3] + w[4] : \
//           cnt ==  6 ? w[0] + w[1] + w[2] + w[3] + w[4] + w[5] : \
//           cnt ==  7 ? w[0] + w[1] + w[2] + w[3] + w[4] + w[5] + w[6] : \
//           cnt ==  8 ? w[0] + w[1] + w[2] + w[3] + w[4] + w[5] + w[6] + w[7] : \
//           cnt ==  9 ? w[0] + w[1] + w[2] + w[3] + w[4] + w[5] + w[6] + w[7] + w[8] : \
//           cnt == 10 ? w[0] + w[1] + w[2] + w[3] + w[4] + w[5] + w[6] + w[7] + w[8] + w[9] : \
//           cnt == 11 ? w[0] + w[1] + w[2] + w[3] + w[4] + w[5] + w[6] + w[7] + w[8] + w[9] + w[10] : \
//           cnt == 12 ? w[0] + w[1] + w[2] + w[3] + w[4] + w[5] + w[6] + w[7] + w[8] + w[9] + w[10] + w[11] : \
//           cnt == 13 ? w[0] + w[1] + w[2] + w[3] + w[4] + w[5] + w[6] + w[7] + w[8] + w[9] + w[10] + w[11] + w[12] : \
//           cnt == 14 ? w[0] + w[1] + w[2] + w[3] + w[4] + w[5] + w[6] + w[7] + w[8] + w[9] + w[10] + w[11] + w[12] + w[13] : \
//           cnt == 15 ? w[0] + w[1] + w[2] + w[3] + w[4] + w[5] + w[6] + w[7] + w[8] + w[9] + w[10] + w[11] + w[12] + w[13] + w[14] : \
//           cnt == 16 ? w[0] + w[1] + w[2] + w[3] + w[4] + w[5] + w[6] + w[7] + w[8] + w[9] + w[10] + w[11] + w[12] + w[13] + w[14] + w[15] : \
//           cnt == 17 ? w[0] + w[1] + w[2] + w[3] + w[4] + w[5] + w[6] + w[7] + w[8] + w[9] + w[10] + w[11] + w[12] + w[13] + w[14] + w[15] + w[16] : \
//           cnt == 18 ? w[0] + w[1] + w[2] + w[3] + w[4] + w[5] + w[6] + w[7] + w[8] + w[9] + w[10] + w[11] + w[12] + w[13] + w[14] + w[15] + w[16] + w[17] : \
//           cnt == 19 ? w[0] + w[1] + w[2] + w[3] + w[4] + w[5] + w[6] + w[7] + w[8] + w[9] + w[10] + w[11] + w[12] + w[13] + w[14] + w[15] + w[16] + w[17] + w[18] : \
//           cnt == 20 ? w[0] + w[1] + w[2] + w[3] + w[4] + w[5] + w[6] + w[7] + w[8] + w[9] + w[10] + w[11] + w[12] + w[13] + w[14] + w[15] + w[16] + w[17] + w[18] + w[19] : \
//           cnt == 21 ? w[0] + w[1] + w[2] + w[3] + w[4] + w[5] + w[6] + w[7] + w[8] + w[9] + w[10] + w[11] + w[12] + w[13] + w[14] + w[15] + w[16] + w[17] + w[18] + w[19] + w[20] : \
//           cnt == 22 ? w[0] + w[1] + w[2] + w[3] + w[4] + w[5] + w[6] + w[7] + w[8] + w[9] + w[10] + w[11] + w[12] + w[13] + w[14] + w[15] + w[16] + w[17] + w[18] + w[19] + w[20] + w[21] : \
//           cnt == 23 ? w[0] + w[1] + w[2] + w[3] + w[4] + w[5] + w[6] + w[7] + w[8] + w[9] + w[10] + w[11] + w[12] + w[13] + w[14] + w[15] + w[16] + w[17] + w[18] + w[19] + w[20] + w[21] + w[22] : \
//           cnt == 24 ? w[0] + w[1] + w[2] + w[3] + w[4] + w[5] + w[6] + w[7] + w[8] + w[9] + w[10] + w[11] + w[12] + w[13] + w[14] + w[15] + w[16] + w[17] + w[18] + w[19] + w[20] + w[21] + w[22] + w[23] : \
//           cnt == 25 ? w[0] + w[1] + w[2] + w[3] + w[4] + w[5] + w[6] + w[7] + w[8] + w[9] + w[10] + w[11] + w[12] + w[13] + w[14] + w[15] + w[16] + w[17] + w[18] + w[19] + w[20] + w[21] + w[22] + w[23] + w[24] : \
//           cnt == 26 ? w[0] + w[1] + w[2] + w[3] + w[4] + w[5] + w[6] + w[7] + w[8] + w[9] + w[10] + w[11] + w[12] + w[13] + w[14] + w[15] + w[16] + w[17] + w[18] + w[19] + w[20] + w[21] + w[22] + w[23] + w[24] + w[25] : \
//           cnt == 27 ? w[0] + w[1] + w[2] + w[3] + w[4] + w[5] + w[6] + w[7] + w[8] + w[9] + w[10] + w[11] + w[12] + w[13] + w[14] + w[15] + w[16] + w[17] + w[18] + w[19] + w[20] + w[21] + w[22] + w[23] + w[24] + w[25] + w[26] : \
//           cnt == 28 ? w[0] + w[1] + w[2] + w[3] + w[4] + w[5] + w[6] + w[7] + w[8] + w[9] + w[10] + w[11] + w[12] + w[13] + w[14] + w[15] + w[16] + w[17] + w[18] + w[19] + w[20] + w[21] + w[22] + w[23] + w[24] + w[25] + w[26] + w[27] : \
//           cnt == 29 ? w[0] + w[1] + w[2] + w[3] + w[4] + w[5] + w[6] + w[7] + w[8] + w[9] + w[10] + w[11] + w[12] + w[13] + w[14] + w[15] + w[16] + w[17] + w[18] + w[19] + w[20] + w[21] + w[22] + w[23] + w[24] + w[25] + w[26] + w[27] + w[28] : \
//           cnt == 20 ? w[0] + w[1] + w[2] + w[3] + w[4] + w[5] + w[6] + w[7] + w[8] + w[9] + w[10] + w[11] + w[12] + w[13] + w[14] + w[15] + w[16] + w[17] + w[18] + w[19] + w[20] + w[21] + w[22] + w[23] + w[24] + w[25] + w[26] + w[27] + w[28] + w[29] : \
//           cnt == 31 ? w[0] + w[1] + w[2] + w[3] + w[4] + w[5] + w[6] + w[7] + w[8] + w[9] + w[10] + w[11] + w[12] + w[13] + w[14] + w[15] + w[16] + w[17] + w[18] + w[19] + w[20] + w[21] + w[22] + w[23] + w[24] + w[25] + w[26] + w[27] + w[28] + w[29] + w[30] : \
//           cnt == 32 ? w[0] + w[1] + w[2] + w[3] + w[4] + w[5] + w[6] + w[7] + w[8] + w[9] + w[10] + w[11] + w[12] + w[13] + w[14] + w[15] + w[16] + w[17] + w[18] + w[19] + w[20] + w[21] + w[22] + w[23] + w[24] + w[25] + w[26] + w[27] + w[28] + w[29] + w[30] + w[31] : 0

`define calc_word_cnt(result, source) \
  result = source <= 32* 1 ?  1 : \
           source <= 32* 2 ?  2 : \
           source <= 32* 3 ?  3 : \
           source <= 32* 4 ?  4 : \
           source <= 32* 5 ?  5 : \
           source <= 32* 6 ?  6 : \
           source <= 32* 7 ?  7 : \
           source <= 32* 8 ?  8 : \
           source <= 32* 9 ?  9 : \
           source <= 32*10 ? 10 : \
           source <= 32*11 ? 11 : \
           source <= 32*12 ? 12 : \
           source <= 32*13 ? 13 : \
           source <= 32*14 ? 14 : \
           source <= 32*15 ? 15 : \
           source <= 32*16 ? 16 : \
           source <= 32*17 ? 17 : \
           source <= 32*18 ? 18 : \
           source <= 32*19 ? 19 : \
           source <= 32*20 ? 20 : \
           source <= 32*21 ? 21 : \
           source <= 32*22 ? 22 : \
           source <= 32*23 ? 23 : \
           source <= 32*24 ? 24 : \
           source <= 32*25 ? 25 : \
           source <= 32*26 ? 26 : \
           source <= 32*27 ? 27 : \
           source <= 32*28 ? 28 : \
           source <= 32*29 ? 29 : \
           source <= 32*20 ? 20 : \
           source <= 32*31 ? 31 : \
           source <= 32*32 ? 32 : 0

`define calc_secded_code_width(result, source) \
    result = source <=    4 ?  3 : \
             source <=   11 ?  4 : \
             source <=   26 ?  5 : \
             source <=   57 ?  6 : \
             source <=  120 ?  7 : \
             source <=  247 ?  8 : \
             source <=  502 ?  9 : \
             source <= 1013 ? 10 : \
             source <= 2036 ? 11 : \
             source <= 4083 ? 12 : 0

`define calc_secded_max_data_width(result, source) \
    result = source <=    4 ?    4 : \
             source <=   11 ?   11 : \
             source <=   26 ?   26 : \
             source <=   57 ?   57 : \
             source <=  120 ?  120 : \
             source <=  247 ?  247 : \
             source <=  502 ?  502 : \
             source <= 1013 ? 1013 : \
             source <= 2036 ? 2036 : \
             source <= 4083 ? 4083 : 0


`endif


/*================================================================================================
     reference codes
==================================================================================================
//---------------------------------------------------
assign bin_next = count_bin == NUM_OF_ENT -1 ? (1 << GRAY_WIDTH) -NUM_OF_ENT : count_bin + 1; 

//---------------------------------------------------
// gray 2 bin
for(genvar i=0; i<GRAY_WIDTH; i=i+1) begin
  assign count_bin[i] = ^gray_out[GRAY_WIDTH -1:i];
end

//---------------------------------------------------
assign gray_next = bin_next ^ (bin_next >> 1);	// bin 2 gray

//---------------------------------------------------
assign FIFO_mem_wp = wptrB[GRAY_WIDTH -1] ? wptrB[GRAY_WIDTH -2:0] - ((1 << BIN_WIDTH) -FIFO_DEPTH) : wptrB[GRAY_WIDTH -2:0];

//---------------------------------------------------
assign FIFO_full = (wptrG[GRAY_WIDTH -1] != rptrG_tx[GRAY_WIDTH -1]) & FIFO_mem_wp == FIFO_mem_rp_tx;

//---------------------------------------------------
assign fifo_occupancy = (wptrB[GRAY_WIDTH-1] & !rptrB[GRAY_WIDTH-1]) ? 
                            wptrB + (~rptrB) + 1 - ((1 << GRAY_WIDTH) - (FIFO_DEPTH << 1)) : 
                            wptrB + (~rptrB) + 1;

//---------------------------------------------------
    // axi signal list reference code
  _if_.ARVALID_postfix_ , output input                    _prefix_ARVALID_postfix_ ,                   arvalid_si0, 
  _if_.ARREADY_postfix_ , input  output                   _prefix_ARREADY_postfix_ ,                   arready_si0, 
  _if_.ARQOS_postfix_   , output input  [3:0]             _prefix_ARQOS_postfix_   , [3:0]               arqos_si0, 
  _if_.ARLEN_postfix_   , output input  [7:0]             _prefix_ARLEN_postfix_   , [7:0]               arlen_si0, 
  _if_.ARID_postfix_    , output input  [ID_WIDTH-1:0]    _prefix_ARID_postfix_    , [ID_WIDTH-1:0]       arid_si0, 
  _if_.ARADDR_postfix_  , output input  [ADDR_WIDTH-1:0]  _prefix_ARADDR_postfix_  , [ADDR_WIDTH-1:0]   araddr_si0, 
  _if_.ARSIZE_postfix_  , output input  [2:0]             _prefix_ARSIZE_postfix_  , [2:0]              arsize_si0, 
  _if_.ARBURST_postfix_ , output input  [1:0]             _prefix_ARBURST_postfix_ , [1:0]             arburst_si0, 
  _if_.ARCACHE_postfix_ , output input  [3:0]             _prefix_ARCACHE_postfix_ , [3:0]             arcache_si0, 
  _if_.ARPROT_postfix_  , output input  [2:0]             _prefix_ARPROT_postfix_  , [2:0]              arprot_si0, 
  _if_.ARLOCK_postfix_  , output input  [1:0]             _prefix_ARLOCK_postfix_  , [1:0]              arlock_si0, 
  _if_.ARSNOOP_postfix_ , output input  [3:0]             _prefix_ARSNOOP_postfix_ , [3:0]             arsnoop_si0, 
  _if_.ARDOMAIN_postfix_, output input  [1:0]             _prefix_ARDOMAIN_postfix_, [1:0]            ardomain_si0, 
  _if_.ARBAR_postfix_   , output input  [1:0]             _prefix_ARBAR_postfix_   , [1:0]               arbar_si0, 
  _if_.ARUSER_postfix_  , output input  [USER_WIDTH-1:0]  _prefix_ARUSER_postfix_  , [USER_WIDTH-1:0]   aruser_si0, 
                                                                                                                    
  _if_.AWVALID_postfix_ , output input                    _prefix_AWVALID_postfix_ ,                   awvalid_si0, 
  _if_.AWREADY_postfix_ , input  output                   _prefix_AWREADY_postfix_ ,                   awready_si0, 
  _if_.AWQOS_postfix_   , output input  [3:0]             _prefix_AWQOS_postfix_   , [3:0]               awqos_si0, 
  _if_.AWLEN_postfix_   , output input  [7:0]             _prefix_AWLEN_postfix_   , [7:0]               awlen_si0, 
  _if_.AWID_postfix_    , output input  [ID_WIDTH-1:0]    _prefix_AWID_postfix_    , [ID_WIDTH-1:0]       awid_si0, 
  _if_.AWADDR_postfix_  , output input  [ADDR_WIDTH-1:0]  _prefix_AWADDR_postfix_  , [ADDR_WIDTH-1:0]   awaddr_si0, 
  _if_.AWSIZE_postfix_  , output input  [2:0]             _prefix_AWSIZE_postfix_  , [2:0]              awsize_si0, 
  _if_.AWBURST_postfix_ , output input  [1:0]             _prefix_AWBURST_postfix_ , [1:0]             awburst_si0, 
  _if_.AWCACHE_postfix_ , output input  [3:0]             _prefix_AWCACHE_postfix_ , [3:0]             awcache_si0, 
  _if_.AWPROT_postfix_  , output input  [2:0]             _prefix_AWPROT_postfix_  , [2:0]              awprot_si0, 
  _if_.AWLOCK_postfix_  , output input  [1:0]             _prefix_AWLOCK_postfix_  , [1:0]              awlock_si0, 
  _if_.AWSNOOP_postfix_ , output input  [2:0]             _prefix_AWSNOOP_postfix_ , [2:0]             awsnoop_si0, 
  _if_.AWDOMAIN_postfix_, output input  [1:0]             _prefix_AWDOMAIN_postfix_, [1:0]            awdomain_si0, 
  _if_.AWBAR_postfix_   , output input  [1:0]             _prefix_AWBAR_postfix_   , [1:0]               awbar_si0, 
  _if_.AWUSER_postfix_  , output input  [USER_WIDTH-1:0]  _prefix_AWUSER_postfix_  , [USER_WIDTH-1:0]   awuser_si0, 
                                                                                                                    
  _if_.WVALID_postfix_  , output input                    _prefix_WVALID_postfix_  ,                    wvalid_si0, 
  _if_.WREADY_postfix_  , input  output                   _prefix_WREADY_postfix_  ,                    wready_si0, 
  _if_.WID_postfix_     , output input  [ID_WIDTH-1:0]    _prefix_WID_postfix_     , [ID_WIDTH-1:0]        wid_si0, 
  _if_.WSTRB_postfix_   , output input  [WSTRB_WIDTH-1:0] _prefix_WSTRB_postfix_   , [WSTRB_WIDTH-1:0]   wstrb_si0, 
  _if_.WDATA_postfix_   , output input  [DATA_WIDTH-1:0]  _prefix_WDATA_postfix_   , [DATA_WIDTH-1:0]    wdata_si0, 
  _if_.WLAST_postfix_   , output input                    _prefix_WLAST_postfix_   ,                     wlast_si0, 
                                                                                                                    
  _if_.RVALID_postfix_  , input  output                   _prefix_RVALID_postfix_  ,                    rvalid_si0, 
  _if_.RREADY_postfix_  , output input                    _prefix_RREADY_postfix_  ,                    rready_si0, 
  _if_.RID_postfix_     , input  output [ID_WIDTH-1:0]    _prefix_RID_postfix_     , [ID_WIDTH-1:0]        rid_si0, 
  _if_.RRESP_postfix_   , input  output [1:0]             _prefix_RRESP_postfix_   , [1:0]               rresp_si0, 
  _if_.RDATA_postfix_   , input  output [DATA_WIDTH-1:0]  _prefix_RDATA_postfix_   , [DATA_WIDTH-1:0]    rdata_si0, 
  _if_.RLAST_postfix_   , input  output                   _prefix_RLAST_postfix_   ,                     rlast_si0, 
  _if_.RUSER_postfix_   , input  output [USER_WIDTH-1:0]  _prefix_RUSER_postfix_   , [USER_WIDTH-1:0]    ruser_si0, 
                                                                                                                    
  _if_.BVALID_postfix_  , input  output                   _prefix_BVALID_postfix_  ,                    bvalid_si0, 
  _if_.BREADY_postfix_  , output input                    _prefix_BREADY_postfix_  ,                    bready_si0, 
  _if_.BID_postfix_     , input  output [ID_WIDTH-1:0]    _prefix_BID_postfix_     , [ID_WIDTH-1:0]        bid_si0, 
  _if_.BRESP_postfix_   , input  output [1:0]             _prefix_BRESP_postfix_   , [1:0]               bresp_si0, 
  _if_.BUSER_postfix_   , input  output [USER_WIDTH-1:0]  _prefix_BUSER_postfix_   , [USER_WIDTH-1:0]    buser_si0, 

//---------------------------------------------------
// HXI signal assign reference code
      assign mi.AV = si.AV; assign si.AR = mi.AR; assign mi.AP = si.AP;
      assign mi.WV = si.WV; assign si.WR = mi.WR; assign mi.WP = si.WP;
      assign si.RV = mi.RV; assign mi.RR = si.RR; assign si.RP = mi.RP;
      assign si.BV = mi.BV; assign mi.BR = si.BR; assign si.BP = mi.BP;

  parameter DECODE_WIDTH      = 10  ,
  parameter ROUTE_WIDTH       = 4  ,
  parameter ID_WIDTH          = 4  ,
  parameter ADDR_WIDTH        = 32 ,
  parameter USER_WIDTH        = 1  ,
  parameter DATA_WIDTH        = 128,
  parameter MAX_AWWL_DISTANCE = 32 ,
  parameter CLOCK_RATIO       = `IS_SYNC1x1,
  parameter NUM_OF_C          = 4,
  parameter NUM_OF_S          = 4,
  parameter NUM_OF_DL         = 4  ,

  parameter R_DECODE_WIDTH = 2,
  parameter R_ID_WIDTH     = 4,
  parameter R_ADDR_WIDTH   = 32,
  parameter R_USER_WIDTH   = 1,
  parameter R_ROUTE_WIDTH  = 2,
  parameter R_DATA_WIDTH   = 32,

  // auto calculated
  parameter WSTRB_WIDTH = DATA_WIDTH/8,
  parameter A_PAYLD_WIDTH = 1 + DECODE_WIDTH + 4 + 4 + ID_WIDTH + ADDR_WIDTH + 13 + 2 + 2 + USER_WIDTH + ROUTE_WIDTH,
  parameter W_PAYLD_WIDTH = WSTRB_WIDTH + DATA_WIDTH + 1,
  parameter R_PAYLD_WIDTH = ID_WIDTH + 2 + DATA_WIDTH + 1 + USER_WIDTH + ROUTE_WIDTH,
  parameter B_PAYLD_WIDTH = ID_WIDTH + 2 + USER_WIDTH + ROUTE_WIDTH,

  parameter R_WSTRB_WIDTH  = R_DATA_WIDTH / 8,
  parameter R_A_PAYLD_WIDTH = 1 + R_DECODE_WIDTH + 4 + 4 + R_ID_WIDTH + R_ADDR_WIDTH + 13 + 2 + 2 + R_USER_WIDTH + R_ROUTE_WIDTH,
  parameter R_W_PAYLD_WIDTH = R_WSTRB_WIDTH + R_DATA_WIDTH + 1,
  parameter R_R_PAYLD_WIDTH = R_ID_WIDTH + 2 + R_DATA_WIDTH + 1 + R_USER_WIDTH + R_ROUTE_WIDTH,
  parameter R_B_PAYLD_WIDTH = R_ID_WIDTH + 2 + R_USER_WIDTH + R_ROUTE_WIDTH,

  parameter DL_A_PAYLD_WIDTH = A_PAYLD_WIDTH >= R_R_PAYLD_WIDTH ? A_PAYLD_WIDTH +1+2: R_R_PAYLD_WIDTH +1+2,
  parameter DL_W_PAYLD_WIDTH = W_PAYLD_WIDTH +1,
  parameter DL_R_PAYLD_WIDTH = R_PAYLD_WIDTH +1,
  parameter DL_B_PAYLD_WIDTH = B_PAYLD_WIDTH >= R_W_PAYLD_WIDTH && B_PAYLD_WIDTH >= R_A_PAYLD_WIDTH   ? B_PAYLD_WIDTH +1+2:
                               R_W_PAYLD_WIDTH >= B_PAYLD_WIDTH && R_W_PAYLD_WIDTH >= R_A_PAYLD_WIDTH ? R_W_PAYLD_WIDTH +1+2 : R_A_PAYLD_WIDTH +1+2

//---------------------------------------------------
// hierarchical reference to simulation top at any sub instance
  // @ top
  integer global_lda_index = 0;
  localparam string si[0:3] = '{"si0", "si1", "si2", "si3"};
  localparam string mi[0:3] = '{"mi0", "mi1", "mi2", "mi3"};
  // @ sub instance
  initial begin
    if($root.axi_top_tb.global_lda_index < 4) begin
      $display($stime, " %m initial_info %s", $root.axi_top_tb.si[$root.axi_top_tb.global_lda_index] );
    end
    $display($stime, " %m initial_info %d", $root.axi_top_tb.global_lda_index++ );
  end


==================================================================================================*/

// vim: tabstop=2 expandtab softtabstop=2 shiftwidth=2 smarttab
