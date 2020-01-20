//=============================================================================
// Release information
// Design version: sifive_sesame_rel3_190711
// Document version: OMC-V1.4-UG-R2.11, OMC-V1.4-IG-R1.00-SESAME
// Release generated at Thu Jul 11 15:30:19 2019
//=============================================================================

module omc_wrapper #(
  parameter ID = 0
) (
  // Clocks and Resets
  input  logic            aclk,             // OMC 1:2 clock
  input  logic            aresetn,
  input  logic            pclk,
  input  logic            presetn,
  input  logic            rclk,
  input  logic            rresetn,

  input  logic            p0_axi_clk,
  input  logic            p0_axi_resetn,

  input  logic            TEST_MODE,

  // AXI address channel signals
  input  logic [  7 -1:0] p0_awid,
  input  logic [ 36 -1:0] p0_awaddr,
  input  logic [  8 -1:0] p0_awlen,
  input  logic [  3 -1:0] p0_awsize,
  input  logic [  2 -1:0] p0_awburst,
  input  logic [  1 -1:0] p0_awlock,
  input  logic [  3 -1:0] p0_awprot,
  input  logic [  4 -1:0] p0_awqos,
  input  logic [  1 -1:0] p0_awvalid,
  output logic [  1 -1:0] p0_awready,

  input  logic [  7 -1:0] p0_arid,
  input  logic [ 36 -1:0] p0_araddr,
  input  logic [  8 -1:0] p0_arlen,
  input  logic [  3 -1:0] p0_arsize,
  input  logic [  2 -1:0] p0_arburst,
  input  logic [  1 -1:0] p0_arlock,
  input  logic [  3 -1:0] p0_arprot,
  input  logic [  4 -1:0] p0_arqos,
  input  logic [  1 -1:0] p0_arvalid,
  output logic [  1 -1:0] p0_arready,

  // AXI write data channel signals
  input  logic [256 -1:0] p0_wdata,
  input  logic [ 32 -1:0] p0_wstrb,
  input  logic [  1 -1:0] p0_wlast,
  input  logic [  1 -1:0] p0_wvalid,
  output logic [  1 -1:0] p0_wready,

  // AXI write response channel signals
  output logic [  7 -1:0] p0_bid,
  output logic [  2 -1:0] p0_bresp,
  output logic [  1 -1:0] p0_bvalid,
  input  logic [  1 -1:0] p0_bready,

  // AXI read data channel signals
  output logic [  7 -1:0] p0_rid,
  output logic [256 -1:0] p0_rdata,
  output logic [  2 -1:0] p0_rresp,
  output logic [  1 -1:0] p0_rlast,
  output logic [  1 -1:0] p0_rvalid,
  input  logic [  1 -1:0] p0_rready,

  // APB Interface
  input  logic            psel,
  input  logic            penable,
  input  logic [ 16 -1:0] paddr,
  input  logic [ 3  -1:0] pprot,
  input  logic [ 4  -1:0] pstrb,

  input  logic            pwrite,
  input  logic [ 32 -1:0] pwdata,

  output logic            pready,
  output logic            pslverr,
  output logic [ 32 -1:0] prdata,

  // P-Channel Interface
  input  logic            preq,
  input  logic [  3 -1:0] pstate,
  output logic            paccept,
  output logic            pdeny,
  output logic            pactive,

  // Interrupt
  output logic            asp_int,
  output logic            overtemp_int,
  output logic            hightemp_int,
  output logic            cooldown_int,

  //---------------------------------------------
  // DDR PHY Interface (DFI 4.0)
  //---------------------------------------------
  // Control Interface
  output logic [  2 -1:0] dfi_cke_p0,
  output logic [  2 -1:0] dfi_cs_p0,
  output logic [  2 -1:0] dfi_odt_p0,
  output logic            dfi_act_p0,
  output logic            dfi_ras_p0,
  output logic            dfi_cas_p0,
  output logic            dfi_we_p0,
  output logic [  2 -1:0] dfi_bg_p0,
  output logic [  3 -1:0] dfi_bank_p0,
  output logic [ 20 -1:0] dfi_address_p0,
  output logic            dfi_parity_in_p0,
  output logic [  2 -1:0] dfi_reset_n_p0,

  output logic [  2 -1:0] dfi_cke_p1,
  output logic [  2 -1:0] dfi_cs_p1,
  output logic [  2 -1:0] dfi_odt_p1,
  output logic            dfi_act_p1,
  output logic            dfi_ras_p1,
  output logic            dfi_cas_p1,
  output logic            dfi_we_p1,
  output logic [  2 -1:0] dfi_bg_p1,
  output logic [  3 -1:0] dfi_bank_p1,
  output logic [ 20 -1:0] dfi_address_p1,
  output logic            dfi_parity_in_p1,
  output logic [  2 -1:0] dfi_reset_n_p1,

  // Write Data Interface
  output logic [  4 -1:0] dfi_wrdata_en_p0,
  output logic [  8 -1:0] dfi_wrdata_cs_p0,
  output logic [ 64 -1:0] dfi_wrdata_p0,
  output logic [  8 -1:0] dfi_wrdata_mask_p0,

  output logic [  4 -1:0] dfi_wrdata_en_p1,
  output logic [  8 -1:0] dfi_wrdata_cs_p1,
  output logic [ 64 -1:0] dfi_wrdata_p1,
  output logic [  8 -1:0] dfi_wrdata_mask_p1,

  // Read Data Interface
  output logic [  4 -1:0] dfi_rddata_en_p0,
  output logic [  8 -1:0] dfi_rddata_cs_p0,
  input  logic [ 64 -1:0] dfi_rddata_w0,
  input  logic [  8 -1:0] dfi_rddata_dbi_w0,
  input  logic [  4 -1:0] dfi_rddata_valid_w0,

  output logic [  4 -1:0] dfi_rddata_en_p1,
  output logic [  8 -1:0] dfi_rddata_cs_p1,
  input  logic [ 64 -1:0] dfi_rddata_w1,
  input  logic [  8 -1:0] dfi_rddata_dbi_w1,
  input  logic [  4 -1:0] dfi_rddata_valid_w1,

  // Update Interface
  output logic            dfi_ctrlupd_req,
  input  logic            dfi_ctrlupd_ack,

  input  logic            dfi_phyupd_req,
  input  logic [  2 -1:0] dfi_phyupd_type,
  output logic            dfi_phyupd_ack,

  // Status Interface
  output logic [  2 -1:0] dfi_dram_clk_disable,
  output logic [  2 -1:0] dfi_freq_ratio,

  output logic            dfi_init_start,
  output logic [  5 -1:0] dfi_frequency,
  input  logic            dfi_init_complete,

  output logic            dfi_geardown_en,

  input  logic [  2 -1:0] dfi_alert_a0,
  input  logic [  2 -1:0] dfi_alert_a1,

  // Read Training Interface
  input  logic [  8 -1:0] dfi_rdlvl_resp,
  output logic [  4 -1:0] dfi_rdlvl_en,
  output logic [  4 -1:0] dfi_rdlvl_gate_en,
  output logic [  4 -1:0] dfi_rdlvl_done,

  // Write DQ Training Interface
  input  logic [  8 -1:0] dfi_wdqlvl_resp,
  input  logic [  4 -1:0] dfi_wdqlvl_result,
  output logic [  4 -1:0] dfi_wdqlvl_en,
  output logic [  4 -1:0] dfi_wdqlvl_done,

  // Write Leveling
  input  logic [  4 -1:0] dfi_wrlvl_resp,
  output logic [  4 -1:0] dfi_wrlvl_en,
  output logic [  4 -1:0] dfi_wrlvl_strobe_p0,
  output logic [  4 -1:0] dfi_wrlvl_strobe_p1,

  // Training Interface
  output logic [ 16 -1:0] dfi_lvl_pattern,
  output logic            dfi_lvl_periodic,

  // PHY Master Interface
  output logic            dfi_phymstr_ack,
  input  logic            dfi_phymstr_req,
  input  logic [  2 -1:0] dfi_phymstr_cs_state,
  input  logic            dfi_phymstr_state_sel,
  input  logic [  2 -1:0] dfi_phymstr_type,

  // Low Power Control Interface
  output logic            dfi_lp_ctrl_req,
  output logic            dfi_lp_data_req,
  output logic [  4 -1:0] dfi_lp_wakeup,
  input  logic            dfi_lp_ack
);

  omc #(.ID(ID)) u_omc (
    .*
  );

endmodule
