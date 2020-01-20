//=============================================================================
// Release information
// Design version: sifive_sesame_rel3_190711
// Document version: OMC-V1.4-UG-R2.11, OMC-V1.4-IG-R1.00-SESAME
// Release generated at Thu Jul 11 15:30:19 2019
//=============================================================================

`ifndef ORBIT_LIBRARY
`define ORBIT_LIBRARY

//============================================================
module orbit_lib_scan_clk_mux ( input i_clk, output o_clk, input SCAN_CLK, input TEST_MODE);

`ifdef __USE_SILICON_LIBRARY__
  // Edit from here ----------------------------------------------------------
`else
  assign o_clk = TEST_MODE ? SCAN_CLK : i_clk;
`endif

endmodule

//============================================================
module orbit_lib_inv_clk_buf ( input  A, output  Y);

`ifdef __USE_SILICON_LIBRARY__
  // Edit from here ----------------------------------------------------------
  //INV_X0P5B_A9TR (Y, A);
  INV_X8N_A9TR_C14 u_clk_inv_cell (.Y(Y), .A(A));
`else
  assign Y = ~A;
`endif

endmodule

//============================================================
module orbit_lib_clk_buf ( input  A, output  Y);

wire A_INV_INTERNAL;
`ifdef __USE_SILICON_LIBRARY__
  // Edit from here ----------------------------------------------------------
  //INV_X0P5B_A9TR (Y, A);
  INV_X8N_A9TR_C14 u_clk_inv_cell_f (.Y(A_INV_INTERNAL), .A(A));
  INV_X8N_A9TR_C14 u_clk_inv_cell (.Y(Y), .A(A_INV_INTERNAL));
`else
  assign A_INV_INTERNAL = ~A;
  assign Y = ~A_INV_INTERNAL;
`endif

endmodule

//============================================================
module orbit_lib_clock_gating (
  input  logic  i_clk,
  input  logic  i_clk_en,
  input  logic  i_scan_mode,         // scan_mode

  output logic  o_clk
);

`ifdef __USE_FPGA_MEMORY__
  assign o_clk = i_clk;
`elsif __USE_SILICON_LIBRARY__
  // Edit from here ----------------------------------------------------------
  //PREICG_X0P5B_A9TR    u_cg_lib_cell (o_clk, i_clk, i_clk_en, i_scan_mode);
  PREICG_X10N_A9TR_C14 u_cg_lib_cell (.ECK(o_clk), .CK(i_clk), .E(i_clk_en), .SE(i_scan_mode));
`else // functional verilog
  logic clk_en;
  always_latch begin
    if (~i_clk) clk_en <= (i_scan_mode) ? 1'b1 : i_clk_en;
  end

  assign o_clk = i_clk & clk_en;
`endif

endmodule


//============================================================
module orbit_lib_synchronizer
#(
  parameter BIT_WIDTH = 1,
  parameter INIT_VALUE = 'd0,
  parameter SYNC_DEPTH = 2,
  parameter IS_NORMAL = 1,
  parameter MIN_T_CK = 500,
  parameter NO_RANDOMIZE = 0 // Debugging purpose only.
)(
  input  logic clk,
  input  logic reset_n,
  input  logic [BIT_WIDTH - 1:0]	data_in,// spyglass disable W240
  output logic [BIT_WIDTH - 1:0]	data_out
);

  genvar gb;
generate
  if(IS_NORMAL == 1) begin : synchronizer_normal
  `ifdef __USE_SILICON_LIBRARY__
    // Edit from here ----------------------------------------------------------
    for (gb=0; gb<BIT_WIDTH; gb++) begin : SYNC_BIT
      if(INIT_VALUE[gb] == 1'b1) begin : INIT_VALUE_1
        SDFFYSQ2D_X1N_A9TR_C14 u_sync_ff_cell (.Q(data_out[gb]), .CK(clk), .D(data_in[gb]), .SE(1'b0), .SI(1'b0), .SN(reset_n));
      end else begin : INIT_VALUE_0
        SDFFYRPQ2D_X1N_A9TR_C14 u_sync_ff_cell (.Q(data_out[gb]), .CK(clk), .D(data_in[gb]), .R(~reset_n), .SE(1'b0), .SI(1'b0));
      end
    end
  `else
    wire [BIT_WIDTH - 1:0] data_delayed;
    logic [BIT_WIDTH - 1:0] sync_ff [0:SYNC_DEPTH-1];

    assign data_out = sync_ff[SYNC_DEPTH-1];

    if (NO_RANDOMIZE) begin
      assign data_delayed = data_in;
    end else begin
      `ifdef ORBIT_RAND_SYNCHRONIZER
        real delay [BIT_WIDTH -1:0];

        for (gb=0; gb<BIT_WIDTH; gb++) begin
          assign #(delay[gb]) data_delayed[gb] = data_in[gb];

          initial begin
            delay[gb] = MIN_T_CK*0.0001*$urandom_range(0, 99)*0.01;
          end
        end
      `else
        assign data_delayed = data_in;
      `endif
    end

    always @ (posedge clk or negedge reset_n) begin
      if(!reset_n) begin
        for (int i=0; i<SYNC_DEPTH; i++) begin
           sync_ff[i] <= INIT_VALUE;
        end
      end else begin
        sync_ff[0] <= data_delayed;
        for (int i=1; i<SYNC_DEPTH; i++) begin
          sync_ff[i] <= sync_ff[i-1];
        end
      end
    end
  `endif

  end else begin : synchronizer_reset
  `ifdef __USE_SILICON_LIBRARY__
    // Edit from here ----------------------------------------------------------
    SDFFYRPQ2D_X1N_A9TR_C14 u_sync_ff_cell (.Q(data_out[0]), .CK(clk), .D(1'b1), .R(~reset_n), .SE(1'b0), .SI(1'b0));
  `else
    logic [0:1] sync_ff;
    assign data_out[0] = sync_ff[1];
    always @ (posedge clk or negedge reset_n) begin
      if(!reset_n) sync_ff <= 'd0;
      else         sync_ff <= {sync_ff[0], 1'b1};
    end
  `endif
  end
endgenerate

endmodule

//============================================================
module orbit_lib_reset_synchronizer
(
  input  logic clk,
  input  logic reset_n,
  output logic sync_reset_n,
  input TEST_MODE
);

`ifdef __USE_SILICON_LIBRARY__
  // Edit from here ----------------------------------------------------------
  SDFFYRPQ2D_X1N_A9TR_C14 u_sync_ff_cell (.Q(sync_reset_n), .CK(clk), .D(1'b1), .R(~reset_n), .SE(TEST_MODE), .SI(1'b0));
`else
  logic [0:1] sync_ff;
  assign sync_reset_n = TEST_MODE ? reset_n : sync_ff[1];
  always @ (posedge clk or negedge reset_n) begin
    if(!reset_n) sync_ff <= 'd0;
    else         sync_ff <= {sync_ff[0], 1'b1};
  end
`endif

endmodule


//============================================================
//module omc_common_synchronizer (
//  input   clk,
//  input   reset_n,
//  input   in,
//  output  out
//);
//
//parameter RST_VAL = 1'b0;
//
//reg [omc_pkg::SYNC_DEPTH-1:0] synchronizer;
//wire [omc_pkg::SYNC_DEPTH-1:0] synchronizer_i;
//
//
////
//// Note: These synchronizer should be changed to synchronizer cells or be replaced nearby in place step.
////
//// in --> synchronizer[0] --> ... --> synchronizer[SYNC_DEPTH-1] --> out
////
//genvar i;
//for (i=0; i<omc_pkg::SYNC_DEPTH; i=i+1) begin
//    if (i==0) assign synchronizer_i[0] = in;
//    else      assign synchronizer_i[i] = synchronizer[i-1];
//end
//
//always_ff @(posedge clk or negedge reset_n) begin
//  if (~reset_n) synchronizer <= {omc_pkg::SYNC_DEPTH{RST_VAL}};
//  else          synchronizer <= synchronizer_i;
//end
//
//assign out = synchronizer[omc_pkg::SYNC_DEPTH-1];
//
//endmodule

`endif
