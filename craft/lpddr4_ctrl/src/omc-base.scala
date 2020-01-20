// Generated Code
// Please DO NOT EDIT


package samsung.com.blocks.omc

import chisel3._
// import chisel3.{withClockAndReset, _}
import chisel3.util._
import chisel3.experimental._

import freechips.rocketchip.config._
import freechips.rocketchip.diplomacy._
import freechips.rocketchip.diplomaticobjectmodel.{DiplomaticObjectModelAddressing, HasLogicalTreeNode}
import freechips.rocketchip.diplomaticobjectmodel.logicaltree.{LogicalTreeNode, LogicalModuleTree}
import freechips.rocketchip.diplomaticobjectmodel.model._
import freechips.rocketchip.amba.axi4._
import freechips.rocketchip.amba.apb._
import freechips.rocketchip.amba.ahb._
import freechips.rocketchip.interrupts._
import freechips.rocketchip.util.{ElaborationArtefacts}
import freechips.rocketchip.tilelink._
import freechips.rocketchip.subsystem._
import freechips.rocketchip.regmapper._

import sifive.skeleton._
import sifive.blocks.util.{NonBlockingEnqueue, NonBlockingDequeue}



class omcBlackBoxIO(

) extends Bundle {
  val pclk = Input(Bool())
  val presetn = Input(Bool())
  val paddr = Input(UInt((16).W))
  val psel = Input(Bool())
  val penable = Input(Bool())
  val pwrite = Input(Bool())
  val prdata = Output(UInt((32).W))
  val pwdata = Input(UInt((32).W))
  val pprot = Input(UInt((3).W))
  val pstrb = Input(UInt((4).W))
  val pready = Output(Bool())
  val pslverr = Output(Bool())
  val p0_axi_clk = Input(Bool())
  val p0_axi_resetn = Input(Bool())
  val p0_awid = Input(UInt((7).W))
  val p0_awaddr = Input(UInt((36).W))
  val p0_awlen = Input(UInt((8).W))
  val p0_awsize = Input(UInt((3).W))
  val p0_awburst = Input(UInt((2).W))
  val p0_awlock = Input(Bool())
  val p0_awprot = Input(UInt((3).W))
  val p0_awqos = Input(UInt((4).W))
  val p0_awvalid = Input(Bool())
  val p0_awready = Output(Bool())
  val p0_arid = Input(UInt((7).W))
  val p0_araddr = Input(UInt((36).W))
  val p0_arlen = Input(UInt((8).W))
  val p0_arsize = Input(UInt((3).W))
  val p0_arburst = Input(UInt((2).W))
  val p0_arlock = Input(Bool())
  val p0_arprot = Input(UInt((3).W))
  val p0_arqos = Input(UInt((4).W))
  val p0_arvalid = Input(Bool())
  val p0_arready = Output(Bool())
  val p0_wdata = Input(UInt((256).W))
  val p0_wstrb = Input(UInt((32).W))
  val p0_wlast = Input(Bool())
  val p0_wvalid = Input(Bool())
  val p0_wready = Output(Bool())
  val p0_bid = Output(UInt((7).W))
  val p0_bresp = Output(UInt((2).W))
  val p0_bvalid = Output(Bool())
  val p0_bready = Input(Bool())
  val p0_rid = Output(UInt((7).W))
  val p0_rdata = Output(UInt((256).W))
  val p0_rresp = Output(UInt((2).W))
  val p0_rlast = Output(Bool())
  val p0_rvalid = Output(Bool())
  val p0_rready = Input(Bool())
  val aclk = Input(Bool())
  val aresetn = Input(Bool())
  val rclk = Input(Bool())
  val rresetn = Input(Bool())
  val asp_int = Output(Bool())
  val cooldown_int = Output(Bool())
  val hightemp_int = Output(Bool())
  val overtemp_int = Output(Bool())
  val TEST_MODE = Input(Bool())
  val preq = Input(Bool())
  val pstate = Input(UInt((3).W))
  val dfi_rddata_w0 = Input(UInt((64).W))
  val dfi_rddata_dbi_w0 = Input(UInt((8).W))
  val dfi_rddata_valid_w0 = Input(UInt((4).W))
  val dfi_rddata_w1 = Input(UInt((64).W))
  val dfi_rddata_dbi_w1 = Input(UInt((8).W))
  val dfi_rddata_valid_w1 = Input(UInt((4).W))
  val dfi_ctrlupd_ack = Input(Bool())
  val dfi_phyupd_req = Input(Bool())
  val dfi_phyupd_type = Input(UInt((2).W))
  val dfi_init_complete = Input(Bool())
  val dfi_geardown_en = Output(Bool())
  val dfi_alert_a0 = Input(UInt((2).W))
  val dfi_alert_a1 = Input(UInt((2).W))
  val dfi_rdlvl_resp = Input(UInt((8).W))
  val dfi_wdqlvl_resp = Input(UInt((8).W))
  val dfi_wdqlvl_result = Input(UInt((4).W))
  val dfi_wrlvl_resp = Input(UInt((4).W))
  val dfi_phymstr_req = Input(Bool())
  val dfi_phymstr_cs_state = Input(UInt((2).W))
  val dfi_phymstr_state_sel = Input(Bool())
  val dfi_phymstr_type = Input(UInt((2).W))
  val dfi_lp_ack = Input(Bool())
  val paccept = Output(Bool())
  val pdeny = Output(Bool())
  val pactive = Output(Bool())
  val dfi_cke_p0 = Output(UInt((2).W))
  val dfi_cs_p0 = Output(UInt((2).W))
  val dfi_odt_p0 = Output(UInt((2).W))
  val dfi_act_p0 = Output(Bool())
  val dfi_ras_p0 = Output(Bool())
  val dfi_cas_p0 = Output(Bool())
  val dfi_we_p0 = Output(Bool())
  val dfi_bg_p0 = Output(UInt((2).W))
  val dfi_bank_p0 = Output(UInt((3).W))
  val dfi_address_p0 = Output(UInt((20).W))
  val dfi_parity_in_p0 = Output(Bool())
  val dfi_reset_n_p0 = Output(UInt((2).W))
  val dfi_cke_p1 = Output(UInt((2).W))
  val dfi_cs_p1 = Output(UInt((2).W))
  val dfi_odt_p1 = Output(UInt((2).W))
  val dfi_act_p1 = Output(Bool())
  val dfi_ras_p1 = Output(Bool())
  val dfi_cas_p1 = Output(Bool())
  val dfi_we_p1 = Output(Bool())
  val dfi_bg_p1 = Output(UInt((2).W))
  val dfi_bank_p1 = Output(UInt((3).W))
  val dfi_address_p1 = Output(UInt((20).W))
  val dfi_parity_in_p1 = Output(Bool())
  val dfi_reset_n_p1 = Output(UInt((2).W))
  val dfi_wrdata_en_p0 = Output(UInt((4).W))
  val dfi_wrdata_cs_p0 = Output(UInt((8).W))
  val dfi_wrdata_p0 = Output(UInt((64).W))
  val dfi_wrdata_mask_p0 = Output(UInt((8).W))
  val dfi_wrdata_en_p1 = Output(UInt((4).W))
  val dfi_wrdata_cs_p1 = Output(UInt((8).W))
  val dfi_wrdata_p1 = Output(UInt((64).W))
  val dfi_wrdata_mask_p1 = Output(UInt((8).W))
  val dfi_rddata_en_p0 = Output(UInt((4).W))
  val dfi_rddata_cs_p0 = Output(UInt((8).W))
  val dfi_rddata_en_p1 = Output(UInt((4).W))
  val dfi_rddata_cs_p1 = Output(UInt((8).W))
  val dfi_ctrlupd_req = Output(Bool())
  val dfi_phyupd_ack = Output(Bool())
  val dfi_dram_clk_disable = Output(UInt((2).W))
  val dfi_freq_ratio = Output(UInt((2).W))
  val dfi_init_start = Output(Bool())
  val dfi_frequency = Output(UInt((5).W))
  val dfi_rdlvl_en = Output(UInt((4).W))
  val dfi_rdlvl_gate_en = Output(UInt((4).W))
  val dfi_rdlvl_done = Output(UInt((4).W))
  val dfi_wdqlvl_en = Output(UInt((4).W))
  val dfi_wdqlvl_done = Output(UInt((4).W))
  val dfi_wrlvl_en = Output(UInt((4).W))
  val dfi_wrlvl_strobe_p0 = Output(UInt((4).W))
  val dfi_wrlvl_strobe_p1 = Output(UInt((4).W))
  val dfi_lvl_pattern = Output(UInt((16).W))
  val dfi_lvl_periodic = Output(Bool())
  val dfi_phymstr_ack = Output(Bool())
  val dfi_lp_ctrl_req = Output(Bool())
  val dfi_lp_data_req = Output(Bool())
  val dfi_lp_wakeup = Output(UInt((4).W))
}

class omc(

) extends BlackBox(Map(

)) with HasBlackBoxResource {
  val io = IO(new omcBlackBoxIO(

  ))
// setResource("top.v")
}

case class omcParams(
  c1_apbParams: Pc1_apbParams,
  c2_axiParams: Pc2_axiParams,
  irqParams: PirqParams,
  cacheBlockBytes: Int
)

// busType: APB4, mode: slave
// busType: AXI4, mode: slave
// busType: interrupts, mode: master

class LomcBase(c: omcParams)(implicit p: Parameters) extends LazyModule {

  def extraResources(resources: ResourceBindings) = Map[String, Seq[ResourceValue]]()

  val device = new SimpleDevice("omc", Seq("samsung.com,omc-0.1.0")) {
    override def describe(resources: ResourceBindings): Description = {
      val Description(name, mapping) = super.describe(resources)
      Description(name, mapping ++ extraResources(resources))
    }
  }



  val c1_apbNode = APBSlaveNode(Seq(
    APBSlavePortParameters(
      slaves = Seq(APBSlaveParameters(
        address = List(AddressSet(c.c1_apbParams.base, ((1L << 16) - 1))),
        // resources
        // regionType
        executable = false,
        // nodePath
        supportsWrite = true,
        supportsRead  = true
        // device
      )),
      beatBytes = 32 / 8
    )
  ))

  val c2_axiNode = AXI4SlaveNode(Seq(
    AXI4SlavePortParameters(
      slaves = Seq(
        AXI4SlaveParameters(
          address       = List(AddressSet(c.c2_axiParams.base, ((1L << 36) - 1))),
          executable    = c.c2_axiParams.executable,
          supportsWrite = TransferSizes(1, (256 * 16 / 8)),
          supportsRead  = TransferSizes(1, (256 * 16 / 8)),
          interleavedId = Some(0),
          resources     = device.reg
        )
      ),
      beatBytes = 256 / 8
    )
  ))

  val irqNode = IntSourceNode(IntSourcePortSimple(
    num = 4,
    resources = device.int
  ))

  val ioBridgeSource = BundleBridgeSource(() => new omcBlackBoxIO(

  ))

  class LomcBaseImp extends LazyRawModuleImp(this) {
    val blackbox = Module(new omc(

    ))
    // interface wiring 2
    // busType: APB4, mode: slave


    // port wiring
    blackbox.io.pclk := ioBridgeSource.bundle.pclk
    blackbox.io.presetn := ioBridgeSource.bundle.presetn
    blackbox.io.paddr := ioBridgeSource.bundle.paddr
    blackbox.io.psel := ioBridgeSource.bundle.psel
    blackbox.io.penable := ioBridgeSource.bundle.penable
    blackbox.io.pwrite := ioBridgeSource.bundle.pwrite
    ioBridgeSource.bundle.prdata := blackbox.io.prdata
    blackbox.io.pwdata := ioBridgeSource.bundle.pwdata
    blackbox.io.pprot := ioBridgeSource.bundle.pprot
    blackbox.io.pstrb := ioBridgeSource.bundle.pstrb
    ioBridgeSource.bundle.pready := blackbox.io.pready
    ioBridgeSource.bundle.pslverr := blackbox.io.pslverr
    blackbox.io.p0_axi_clk := ioBridgeSource.bundle.p0_axi_clk
    blackbox.io.p0_axi_resetn := ioBridgeSource.bundle.p0_axi_resetn
    blackbox.io.p0_awid := ioBridgeSource.bundle.p0_awid
    blackbox.io.p0_awaddr := ioBridgeSource.bundle.p0_awaddr
    blackbox.io.p0_awlen := ioBridgeSource.bundle.p0_awlen
    blackbox.io.p0_awsize := ioBridgeSource.bundle.p0_awsize
    blackbox.io.p0_awburst := ioBridgeSource.bundle.p0_awburst
    blackbox.io.p0_awlock := ioBridgeSource.bundle.p0_awlock
    blackbox.io.p0_awprot := ioBridgeSource.bundle.p0_awprot
    blackbox.io.p0_awqos := ioBridgeSource.bundle.p0_awqos
    blackbox.io.p0_awvalid := ioBridgeSource.bundle.p0_awvalid
    ioBridgeSource.bundle.p0_awready := blackbox.io.p0_awready
    blackbox.io.p0_arid := ioBridgeSource.bundle.p0_arid
    blackbox.io.p0_araddr := ioBridgeSource.bundle.p0_araddr
    blackbox.io.p0_arlen := ioBridgeSource.bundle.p0_arlen
    blackbox.io.p0_arsize := ioBridgeSource.bundle.p0_arsize
    blackbox.io.p0_arburst := ioBridgeSource.bundle.p0_arburst
    blackbox.io.p0_arlock := ioBridgeSource.bundle.p0_arlock
    blackbox.io.p0_arprot := ioBridgeSource.bundle.p0_arprot
    blackbox.io.p0_arqos := ioBridgeSource.bundle.p0_arqos
    blackbox.io.p0_arvalid := ioBridgeSource.bundle.p0_arvalid
    ioBridgeSource.bundle.p0_arready := blackbox.io.p0_arready
    blackbox.io.p0_wdata := ioBridgeSource.bundle.p0_wdata
    blackbox.io.p0_wstrb := ioBridgeSource.bundle.p0_wstrb
    blackbox.io.p0_wlast := ioBridgeSource.bundle.p0_wlast
    blackbox.io.p0_wvalid := ioBridgeSource.bundle.p0_wvalid
    ioBridgeSource.bundle.p0_wready := blackbox.io.p0_wready
    ioBridgeSource.bundle.p0_bid := blackbox.io.p0_bid
    ioBridgeSource.bundle.p0_bresp := blackbox.io.p0_bresp
    ioBridgeSource.bundle.p0_bvalid := blackbox.io.p0_bvalid
    blackbox.io.p0_bready := ioBridgeSource.bundle.p0_bready
    ioBridgeSource.bundle.p0_rid := blackbox.io.p0_rid
    ioBridgeSource.bundle.p0_rdata := blackbox.io.p0_rdata
    ioBridgeSource.bundle.p0_rresp := blackbox.io.p0_rresp
    ioBridgeSource.bundle.p0_rlast := blackbox.io.p0_rlast
    ioBridgeSource.bundle.p0_rvalid := blackbox.io.p0_rvalid
    blackbox.io.p0_rready := ioBridgeSource.bundle.p0_rready
    blackbox.io.aclk := ioBridgeSource.bundle.aclk
    blackbox.io.aresetn := ioBridgeSource.bundle.aresetn
    blackbox.io.rclk := ioBridgeSource.bundle.rclk
    blackbox.io.rresetn := ioBridgeSource.bundle.rresetn
    ioBridgeSource.bundle.asp_int := blackbox.io.asp_int
    ioBridgeSource.bundle.cooldown_int := blackbox.io.cooldown_int
    ioBridgeSource.bundle.hightemp_int := blackbox.io.hightemp_int
    ioBridgeSource.bundle.overtemp_int := blackbox.io.overtemp_int
    blackbox.io.TEST_MODE := ioBridgeSource.bundle.TEST_MODE
    blackbox.io.preq := ioBridgeSource.bundle.preq
    blackbox.io.pstate := ioBridgeSource.bundle.pstate
    blackbox.io.dfi_rddata_w0 := ioBridgeSource.bundle.dfi_rddata_w0
    blackbox.io.dfi_rddata_dbi_w0 := ioBridgeSource.bundle.dfi_rddata_dbi_w0
    blackbox.io.dfi_rddata_valid_w0 := ioBridgeSource.bundle.dfi_rddata_valid_w0
    blackbox.io.dfi_rddata_w1 := ioBridgeSource.bundle.dfi_rddata_w1
    blackbox.io.dfi_rddata_dbi_w1 := ioBridgeSource.bundle.dfi_rddata_dbi_w1
    blackbox.io.dfi_rddata_valid_w1 := ioBridgeSource.bundle.dfi_rddata_valid_w1
    blackbox.io.dfi_ctrlupd_ack := ioBridgeSource.bundle.dfi_ctrlupd_ack
    blackbox.io.dfi_phyupd_req := ioBridgeSource.bundle.dfi_phyupd_req
    blackbox.io.dfi_phyupd_type := ioBridgeSource.bundle.dfi_phyupd_type
    blackbox.io.dfi_init_complete := ioBridgeSource.bundle.dfi_init_complete
    ioBridgeSource.bundle.dfi_geardown_en := blackbox.io.dfi_geardown_en
    blackbox.io.dfi_alert_a0 := ioBridgeSource.bundle.dfi_alert_a0
    blackbox.io.dfi_alert_a1 := ioBridgeSource.bundle.dfi_alert_a1
    blackbox.io.dfi_rdlvl_resp := ioBridgeSource.bundle.dfi_rdlvl_resp
    blackbox.io.dfi_wdqlvl_resp := ioBridgeSource.bundle.dfi_wdqlvl_resp
    blackbox.io.dfi_wdqlvl_result := ioBridgeSource.bundle.dfi_wdqlvl_result
    blackbox.io.dfi_wrlvl_resp := ioBridgeSource.bundle.dfi_wrlvl_resp
    blackbox.io.dfi_phymstr_req := ioBridgeSource.bundle.dfi_phymstr_req
    blackbox.io.dfi_phymstr_cs_state := ioBridgeSource.bundle.dfi_phymstr_cs_state
    blackbox.io.dfi_phymstr_state_sel := ioBridgeSource.bundle.dfi_phymstr_state_sel
    blackbox.io.dfi_phymstr_type := ioBridgeSource.bundle.dfi_phymstr_type
    blackbox.io.dfi_lp_ack := ioBridgeSource.bundle.dfi_lp_ack
    ioBridgeSource.bundle.paccept := blackbox.io.paccept
    ioBridgeSource.bundle.pdeny := blackbox.io.pdeny
    ioBridgeSource.bundle.pactive := blackbox.io.pactive
    ioBridgeSource.bundle.dfi_cke_p0 := blackbox.io.dfi_cke_p0
    ioBridgeSource.bundle.dfi_cs_p0 := blackbox.io.dfi_cs_p0
    ioBridgeSource.bundle.dfi_odt_p0 := blackbox.io.dfi_odt_p0
    ioBridgeSource.bundle.dfi_act_p0 := blackbox.io.dfi_act_p0
    ioBridgeSource.bundle.dfi_ras_p0 := blackbox.io.dfi_ras_p0
    ioBridgeSource.bundle.dfi_cas_p0 := blackbox.io.dfi_cas_p0
    ioBridgeSource.bundle.dfi_we_p0 := blackbox.io.dfi_we_p0
    ioBridgeSource.bundle.dfi_bg_p0 := blackbox.io.dfi_bg_p0
    ioBridgeSource.bundle.dfi_bank_p0 := blackbox.io.dfi_bank_p0
    ioBridgeSource.bundle.dfi_address_p0 := blackbox.io.dfi_address_p0
    ioBridgeSource.bundle.dfi_parity_in_p0 := blackbox.io.dfi_parity_in_p0
    ioBridgeSource.bundle.dfi_reset_n_p0 := blackbox.io.dfi_reset_n_p0
    ioBridgeSource.bundle.dfi_cke_p1 := blackbox.io.dfi_cke_p1
    ioBridgeSource.bundle.dfi_cs_p1 := blackbox.io.dfi_cs_p1
    ioBridgeSource.bundle.dfi_odt_p1 := blackbox.io.dfi_odt_p1
    ioBridgeSource.bundle.dfi_act_p1 := blackbox.io.dfi_act_p1
    ioBridgeSource.bundle.dfi_ras_p1 := blackbox.io.dfi_ras_p1
    ioBridgeSource.bundle.dfi_cas_p1 := blackbox.io.dfi_cas_p1
    ioBridgeSource.bundle.dfi_we_p1 := blackbox.io.dfi_we_p1
    ioBridgeSource.bundle.dfi_bg_p1 := blackbox.io.dfi_bg_p1
    ioBridgeSource.bundle.dfi_bank_p1 := blackbox.io.dfi_bank_p1
    ioBridgeSource.bundle.dfi_address_p1 := blackbox.io.dfi_address_p1
    ioBridgeSource.bundle.dfi_parity_in_p1 := blackbox.io.dfi_parity_in_p1
    ioBridgeSource.bundle.dfi_reset_n_p1 := blackbox.io.dfi_reset_n_p1
    ioBridgeSource.bundle.dfi_wrdata_en_p0 := blackbox.io.dfi_wrdata_en_p0
    ioBridgeSource.bundle.dfi_wrdata_cs_p0 := blackbox.io.dfi_wrdata_cs_p0
    ioBridgeSource.bundle.dfi_wrdata_p0 := blackbox.io.dfi_wrdata_p0
    ioBridgeSource.bundle.dfi_wrdata_mask_p0 := blackbox.io.dfi_wrdata_mask_p0
    ioBridgeSource.bundle.dfi_wrdata_en_p1 := blackbox.io.dfi_wrdata_en_p1
    ioBridgeSource.bundle.dfi_wrdata_cs_p1 := blackbox.io.dfi_wrdata_cs_p1
    ioBridgeSource.bundle.dfi_wrdata_p1 := blackbox.io.dfi_wrdata_p1
    ioBridgeSource.bundle.dfi_wrdata_mask_p1 := blackbox.io.dfi_wrdata_mask_p1
    ioBridgeSource.bundle.dfi_rddata_en_p0 := blackbox.io.dfi_rddata_en_p0
    ioBridgeSource.bundle.dfi_rddata_cs_p0 := blackbox.io.dfi_rddata_cs_p0
    ioBridgeSource.bundle.dfi_rddata_en_p1 := blackbox.io.dfi_rddata_en_p1
    ioBridgeSource.bundle.dfi_rddata_cs_p1 := blackbox.io.dfi_rddata_cs_p1
    ioBridgeSource.bundle.dfi_ctrlupd_req := blackbox.io.dfi_ctrlupd_req
    ioBridgeSource.bundle.dfi_phyupd_ack := blackbox.io.dfi_phyupd_ack
    ioBridgeSource.bundle.dfi_dram_clk_disable := blackbox.io.dfi_dram_clk_disable
    ioBridgeSource.bundle.dfi_freq_ratio := blackbox.io.dfi_freq_ratio
    ioBridgeSource.bundle.dfi_init_start := blackbox.io.dfi_init_start
    ioBridgeSource.bundle.dfi_frequency := blackbox.io.dfi_frequency
    ioBridgeSource.bundle.dfi_rdlvl_en := blackbox.io.dfi_rdlvl_en
    ioBridgeSource.bundle.dfi_rdlvl_gate_en := blackbox.io.dfi_rdlvl_gate_en
    ioBridgeSource.bundle.dfi_rdlvl_done := blackbox.io.dfi_rdlvl_done
    ioBridgeSource.bundle.dfi_wdqlvl_en := blackbox.io.dfi_wdqlvl_en
    ioBridgeSource.bundle.dfi_wdqlvl_done := blackbox.io.dfi_wdqlvl_done
    ioBridgeSource.bundle.dfi_wrlvl_en := blackbox.io.dfi_wrlvl_en
    ioBridgeSource.bundle.dfi_wrlvl_strobe_p0 := blackbox.io.dfi_wrlvl_strobe_p0
    ioBridgeSource.bundle.dfi_wrlvl_strobe_p1 := blackbox.io.dfi_wrlvl_strobe_p1
    ioBridgeSource.bundle.dfi_lvl_pattern := blackbox.io.dfi_lvl_pattern
    ioBridgeSource.bundle.dfi_lvl_periodic := blackbox.io.dfi_lvl_periodic
    ioBridgeSource.bundle.dfi_phymstr_ack := blackbox.io.dfi_phymstr_ack
    ioBridgeSource.bundle.dfi_lp_ctrl_req := blackbox.io.dfi_lp_ctrl_req
    ioBridgeSource.bundle.dfi_lp_data_req := blackbox.io.dfi_lp_data_req
    ioBridgeSource.bundle.dfi_lp_wakeup := blackbox.io.dfi_lp_wakeup
    // interface alias
    val c1_apb0 = c1_apbNode.in(0)._1
    val c2_axi0 = c2_axiNode.in(0)._1
    val irq0 = irqNode.out(0)._1
    // interface wiring
    // wiring for c1_apb of type APB4
    // -> {"prdata":"-dataWidth","pwrite":1,"penable":1,"psel":1,"pready":-1,"pslverr":-1,"paddr":"addrWidth","pwdata":"dataWidth","pprot":3}
    c1_apb0.prdata := blackbox.io.prdata
    blackbox.io.pwrite := c1_apb0.pwrite
    blackbox.io.penable := c1_apb0.penable
    blackbox.io.psel := c1_apb0.psel
    c1_apb0.pready := blackbox.io.pready
    c1_apb0.pslverr := blackbox.io.pslverr
    blackbox.io.paddr := c1_apb0.paddr
    blackbox.io.pwdata := c1_apb0.pwdata
    blackbox.io.pprot := c1_apb0.pprot

    // wiring for c2_axi of type AXI4
    // -> {"aw":{"valid":1,"ready":-1,"bits":{"id":"awIdWidth","addr":"awAddrWidth","len":8,"size":3,"burst":2,"lock":1,"cache":4,"prot":3,"qos":4,"region":4}},"w":{"valid":1,"ready":-1,"bits":{"data":"wDataWidth","strb":"wStrbWidth","last":1}},"b":{"valid":-1,"ready":1,"bits":{"id":"-bIdWidth","resp":-2}},"ar":{"valid":1,"ready":-1,"bits":{"id":"arIdWidth","addr":"addrWidth","len":8,"size":3,"burst":2,"lock":1,"cache":4,"prot":3,"qos":4,"region":4}},"r":{"valid":-1,"ready":1,"bits":{"id":"-rIdWidth","data":"-dataWidth","resp":-2,"last":-1}}}
    // aw
    blackbox.io.p0_awvalid := c2_axi0.aw.valid
    c2_axi0.aw.ready := blackbox.io.p0_awready
    // aw
    blackbox.io.p0_awid := c2_axi0.aw.bits.id
    blackbox.io.p0_awaddr := c2_axi0.aw.bits.addr
    blackbox.io.p0_awlen := c2_axi0.aw.bits.len
    blackbox.io.p0_awsize := c2_axi0.aw.bits.size
    blackbox.io.p0_awburst := c2_axi0.aw.bits.burst
    blackbox.io.p0_awlock := c2_axi0.aw.bits.lock
    // AWCACHE
    blackbox.io.p0_awprot := c2_axi0.aw.bits.prot
    blackbox.io.p0_awqos := c2_axi0.aw.bits.qos
    // AWREGION
    // w
    blackbox.io.p0_wvalid := c2_axi0.w.valid
    c2_axi0.w.ready := blackbox.io.p0_wready
    // w
    blackbox.io.p0_wdata := c2_axi0.w.bits.data
    blackbox.io.p0_wstrb := c2_axi0.w.bits.strb
    blackbox.io.p0_wlast := c2_axi0.w.bits.last
    // b
    c2_axi0.b.valid := blackbox.io.p0_bvalid
    blackbox.io.p0_bready := c2_axi0.b.ready
    // b
    c2_axi0.b.bits.id := blackbox.io.p0_bid
    c2_axi0.b.bits.resp := blackbox.io.p0_bresp
    // ar
    blackbox.io.p0_arvalid := c2_axi0.ar.valid
    c2_axi0.ar.ready := blackbox.io.p0_arready
    // ar
    blackbox.io.p0_arid := c2_axi0.ar.bits.id
    blackbox.io.p0_araddr := c2_axi0.ar.bits.addr
    blackbox.io.p0_arlen := c2_axi0.ar.bits.len
    blackbox.io.p0_arsize := c2_axi0.ar.bits.size
    blackbox.io.p0_arburst := c2_axi0.ar.bits.burst
    blackbox.io.p0_arlock := c2_axi0.ar.bits.lock
    // ARCACHE
    blackbox.io.p0_arprot := c2_axi0.ar.bits.prot
    blackbox.io.p0_arqos := c2_axi0.ar.bits.qos
    // ARREGION
    // r
    c2_axi0.r.valid := blackbox.io.p0_rvalid
    blackbox.io.p0_rready := c2_axi0.r.ready
    // r
    c2_axi0.r.bits.id := blackbox.io.p0_rid
    c2_axi0.r.bits.data := blackbox.io.p0_rdata
    c2_axi0.r.bits.resp := blackbox.io.p0_rresp
    c2_axi0.r.bits.last := blackbox.io.p0_rlast

    // wiring for irq of type interrupts
    // ["asp_int","cooldown_int","hightemp_int","overtemp_int"]
    irq0(0) := blackbox.io.asp_int
    irq0(1) := blackbox.io.cooldown_int
    irq0(2) := blackbox.io.hightemp_int
    irq0(3) := blackbox.io.overtemp_int
  }
  lazy val module = new LomcBaseImp
}


case class Pc1_apbParams(
  base: BigInt,
  executable: Boolean = false,
  maxFifoBits: Int = 2,
  maxTransactions: Int = 1,
  axi4BufferParams: AXI4BufferParams = AXI4BufferParams(),
  tlBufferParams: TLBufferParams = TLBufferParams()
)


case class Pc2_axiParams(
  base: BigInt,
  executable: Boolean = false,
  maxFifoBits: Int = 7,
  maxTransactions: Int = 1,
  axi4BufferParams: AXI4BufferParams = AXI4BufferParams(),
  tlBufferParams: TLBufferParams = TLBufferParams()
)


case class PirqParams()


case class NomcTopParams(
  blackbox: omcParams
) {
  def setBurstBytes(x: Int): NomcTopParams = this.copy()
}

object NomcTopParams {
  def defaults(
    c1_apb_base: BigInt,
    c2_axi_base: BigInt,
    cacheBlockBytes: Int
  ) = NomcTopParams(
    blackbox = omcParams(
      c1_apbParams = Pc1_apbParams(base = c1_apb_base),
      c2_axiParams = Pc2_axiParams(base = c2_axi_base),
      irqParams = PirqParams(),
      cacheBlockBytes = cacheBlockBytes
    )
  )
}


class NomcTopLogicalTreeNode(component: NomcTopBase) extends LogicalTreeNode(() => Some(component.imp.device)) {
  override def getOMComponents(resourceBindings: ResourceBindings, components: Seq[OMComponent]): Seq[OMComponent] = {
    val name = component.imp.device.describe(resourceBindings).name
    val omDevice = new scala.collection.mutable.LinkedHashMap[String, Any] with OMDevice {
      val memoryRegions = component.getOMMemoryRegions(resourceBindings)
      val interrupts = component.getOMInterrupts(resourceBindings)
      val _types: Seq[String] = Seq("OMomc", "OMDevice", "OMComponent", "OMCompoundType")
    }
    val userOM = component.userOM
    val values = userOM.productIterator
    if (values.nonEmpty) {
      val pairs = (userOM.getClass.getDeclaredFields.map { field =>
        assert(field.getName != "memoryRegions", "user Object Model must not define \"memoryRegions\"")
        assert(field.getName != "interrupts", "user Object Model must not define \"interrupts\"")
        assert(field.getName != "_types", "user Object Model must not define \"_types\"")

        field.getName -> values.next
      }).toSeq
      omDevice ++= pairs
    }
    omDevice("memoryRegions") = omDevice.memoryRegions
    omDevice("interrupts") = omDevice.interrupts
    omDevice("_types") = omDevice._types
    Seq(omDevice)
  }
}

class NomcTopBase(val c: NomcTopParams)(implicit p: Parameters)
 extends SimpleLazyModule
 with BindingScope
 with HasLogicalTreeNode {
  val imp = LazyModule(new Lomc(c.blackbox))

  ResourceBinding { Resource(imp.device, "exists").bind(ResourceString("yes")) }

  def userOM: Product with Serializable = Nil

  private def padFields(fields: (Int, RegField)*) = {
    var previousOffset = 0
    var previousField: Option[RegField] = None

    fields.flatMap { case (fieldOffset, field) =>
      val padWidth = fieldOffset - previousOffset
      require(padWidth >= 0,
        if (previousField.isDefined) {
          s"register fields at $previousOffset and $fieldOffset are overlapping"
        } else {
          s"register field $field has a negative offset"
        })

      previousOffset = fieldOffset
      previousField = Some(field)

      if (padWidth > 0) {
        Seq(RegField(padWidth), field)
      } else {
        Seq(field)
      }
    }
  }

  def omRegisterMaps = Seq(
    OMRegister.convert(
      0 -> RegFieldGroup("REG_00", None, padFields(
        0 -> RegField(32, Bool(), RegFieldDesc("data", "", reset = Some(0))))),
      4 -> RegFieldGroup("REG_01", None, padFields(
        0 -> RegField(32, Bool(), RegFieldDesc("data", "", reset = Some(0))))),
      8 -> RegFieldGroup("REG_02", None, padFields(
        0 -> RegField(32, Bool(), RegFieldDesc("data", "", reset = Some(0))))),
      12 -> RegFieldGroup("REG_03", None, padFields(
        0 -> RegField(32, Bool(), RegFieldDesc("data", "", reset = Some(0))))),
      16 -> RegFieldGroup("REG_04", None, padFields(
        0 -> RegField(32, Bool(), RegFieldDesc("data", "", reset = Some(0))))),
      20 -> RegFieldGroup("REG_05", None, padFields(
        0 -> RegField(32, Bool(), RegFieldDesc("data", "", reset = Some(0))))),
      24 -> RegFieldGroup("REG_06", None, padFields(
        0 -> RegField(32, Bool(), RegFieldDesc("data", "", reset = Some(0))))),
      28 -> RegFieldGroup("REG_07", None, padFields(
        0 -> RegField(32, Bool(), RegFieldDesc("data", "", reset = Some(0))))),
      32 -> RegFieldGroup("REG_08", None, padFields(
        0 -> RegField(32, Bool(), RegFieldDesc("data", "", reset = Some(0))))),
      36 -> RegFieldGroup("REG_09", None, padFields(
        0 -> RegField(32, Bool(), RegFieldDesc("data", "", reset = Some(0))))),
      40 -> RegFieldGroup("REG_10", None, padFields(
        0 -> RegField(32, Bool(), RegFieldDesc("data", "", reset = Some(0))))),
      44 -> RegFieldGroup("REG_11", None, padFields(
        0 -> RegField(32, Bool(), RegFieldDesc("data", "", reset = Some(0))))),
      48 -> RegFieldGroup("REG_12", None, padFields(
        0 -> RegField(32, Bool(), RegFieldDesc("data", "", reset = Some(0))))),
      52 -> RegFieldGroup("REG_13", None, padFields(
        0 -> RegField(32, Bool(), RegFieldDesc("data", "", reset = Some(0))))),
      56 -> RegFieldGroup("REG_14", None, padFields(
        0 -> RegField(32, Bool(), RegFieldDesc("data", "", reset = Some(0))))),
      60 -> RegFieldGroup("REG_15", None, padFields(
        0 -> RegField(32, Bool(), RegFieldDesc("data", "", reset = Some(0))))),
      64 -> RegFieldGroup("REG_16", None, padFields(
        0 -> RegField.r(32, Bool(), RegFieldDesc("data", "")))),
      68 -> RegFieldGroup("REG_17", None, padFields(
        0 -> RegField.r(32, Bool(), RegFieldDesc("data", "")))),
      72 -> RegFieldGroup("REG_18", None, padFields(
        0 -> RegField.r(32, Bool(), RegFieldDesc("data", "")))),
      76 -> RegFieldGroup("REG_19", None, padFields(
        0 -> RegField.r(32, Bool(), RegFieldDesc("data", "")))),
      80 -> RegFieldGroup("REG_20", None, padFields(
        0 -> RegField.r(32, Bool(), RegFieldDesc("data", "")))),
      84 -> RegFieldGroup("REG_21", None, padFields(
        0 -> RegField.r(32, Bool(), RegFieldDesc("data", "")))),
      88 -> RegFieldGroup("REG_22", None, padFields(
        0 -> RegField.r(32, Bool(), RegFieldDesc("data", "")))),
      92 -> RegFieldGroup("REG_23", None, padFields(
        0 -> RegField.r(32, Bool(), RegFieldDesc("data", "")))),
      96 -> RegFieldGroup("REG_24", None, padFields(
        0 -> RegField.r(32, Bool(), RegFieldDesc("data", "")))),
      100 -> RegFieldGroup("REG_25", None, padFields(
        0 -> RegField.r(32, Bool(), RegFieldDesc("data", "")))),
      104 -> RegFieldGroup("REG_26", None, padFields(
        0 -> RegField.r(32, Bool(), RegFieldDesc("data", "")))),
      108 -> RegFieldGroup("REG_27", None, padFields(
        0 -> RegField.r(32, Bool(), RegFieldDesc("data", "")))),
      112 -> RegFieldGroup("REG_28", None, padFields(
        0 -> RegField.r(32, Bool(), RegFieldDesc("data", "")))),
      116 -> RegFieldGroup("REG_29", None, padFields(
        0 -> RegField.r(32, Bool(), RegFieldDesc("data", "")))),
      120 -> RegFieldGroup("REG_30", None, padFields(
        0 -> RegField.r(32, Bool(), RegFieldDesc("data", "")))),
      124 -> RegFieldGroup("REG_31", None, padFields(
        0 -> RegField.r(32, Bool(), RegFieldDesc("data", ""))))))

  def getOMMemoryRegions(resourceBindings: ResourceBindings): Seq[OMMemoryRegion] = {
    val name = imp.device.describe(resourceBindings).name
    DiplomaticObjectModelAddressing.getOMMemoryRegions(name, resourceBindings, None)
  }

  def getOMInterrupts(resourceBindings: ResourceBindings): Seq[OMInterrupt] = {
    val name = imp.device.describe(resourceBindings).name
    DiplomaticObjectModelAddressing.describeGlobalInterrupts(name, resourceBindings)
  }

  def logicalTreeNode: LogicalTreeNode = new NomcTopLogicalTreeNode(this)


// no channel node

  val c1_apbNode: APBSlaveNode = imp.c1_apbNode

  def getc1_apbNodeTLAdapter(): TLInwardNode = {(
    c1_apbNode
      := TLToAPB(false)
      := TLBuffer()
      := TLFragmenter((32 / 8), c.blackbox.cacheBlockBytes, holdFirstDeny=true)
  )}


  val c2_axiNode: AXI4SlaveNode = imp.c2_axiNode

  def getc2_axiNodeTLAdapter(): TLInwardNode = {(
    c2_axiNode
      := AXI4Buffer(
        aw = c.blackbox.c2_axiParams.axi4BufferParams.aw,
        ar = c.blackbox.c2_axiParams.axi4BufferParams.ar,
        w = c.blackbox.c2_axiParams.axi4BufferParams.w,
        r = c.blackbox.c2_axiParams.axi4BufferParams.r,
        b = c.blackbox.c2_axiParams.axi4BufferParams.b
      )
      := AXI4UserYanker(capMaxFlight = Some(c.blackbox.c2_axiParams.maxTransactions))
      := AXI4Deinterleaver(c.blackbox.cacheBlockBytes)
           := AXI4IdIndexer(idBits = c.blackbox.c2_axiParams.maxFifoBits)    := TLToAXI4()


      := TLBuffer(
        a = c.blackbox.c2_axiParams.tlBufferParams.a,
        b = c.blackbox.c2_axiParams.tlBufferParams.b,
        c = c.blackbox.c2_axiParams.tlBufferParams.c,
        d = c.blackbox.c2_axiParams.tlBufferParams.d,
        e = c.blackbox.c2_axiParams.tlBufferParams.e
      )
  )}


  val irqNode: IntSourceNode = imp.irqNode
}

object NomcTopBase {
  def attach(c: NomcTopParams)(bap: BlockAttachParams): NomcTop = {
    implicit val p: Parameters = bap.p
    val omc_top = LazyModule(new NomcTop(c))
    // no channel attachment
    bap.pbus.coupleTo("omc_apb") { omc_top.getc1_apbNodeTLAdapter() := TLWidthWidget(bap.pbus) := _ }
    bap.pbus.coupleTo("axi") { omc_top.getc2_axiNodeTLAdapter() := TLWidthWidget(bap.pbus) := _ }
    bap.ibus := omc_top.irqNode
    LogicalModuleTree.add(bap.parentNode, omc_top.logicalTreeNode)
    omc_top
  }
}

class WithomcTopBase (
  c1_apb_base: BigInt,
  c2_axi_base: BigInt
) extends Config((site, here, up) => {
  case BlockDescriptorKey =>
    BlockDescriptor(
      name = "omc",
      place = NomcTop.attach(NomcTopParams.defaults(
        c1_apb_base = c1_apb_base,
        c2_axi_base = c2_axi_base,
        cacheBlockBytes = site(CacheBlockBytes)
      ))
    ) +: up(BlockDescriptorKey, site)
})
