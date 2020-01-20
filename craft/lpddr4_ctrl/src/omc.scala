// USER editable file


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

import samsung.com.blocks.omc.regmap.CSR.csrAddressBlock._

class NomcTopIO(
                   
) extends Bundle {
  val TEST_MODE = Input(Bool())
  val preq = Input(Bool())
  val pstate = Input(UInt((3).W))
  val paccept = Output(Bool())
  val pdeny = Output(Bool())
  val pactive = Output(Bool())
}

class Lomc(c: omcParams)(implicit p: Parameters) extends LomcBase(c)(p)
{

// User code here

}

class NomcTop(c: NomcTopParams)(implicit p: Parameters) extends NomcTopBase(c)(p)
{

// User code here
  // route the ports of the black box to this sink
  val ioBridgeSink = BundleBridgeSink[omcBlackBoxIO]()
  ioBridgeSink := imp.ioBridgeSource

  val omc_params = samsung.com.blocks.omc.regmap.omcParams()

  // create a new ports for regmap
  val regmap = LazyModule(new csrAddressBlockTLRegMap(p(CacheBlockBytes), 0x40000L, omc_params))
  val registerIO = BundleBridgeSink[csrAddressBlockAddressBlockBundle]()
  registerIO := regmap.ioNode

  // create a new ports for vip
  val ioBridgeSource = BundleBridgeSource(() => new NomcTopIO())

  // logic to connect ioBridgeSink/Source nodes
  override lazy val module = new LazyModuleImp(this) {
    ioBridgeSink.bundle.p0_axi_clk    := clock.asUInt
    ioBridgeSink.bundle.p0_axi_resetn := !(reset.toBool)
    ioBridgeSink.bundle.pclk          := clock.asUInt
    ioBridgeSink.bundle.presetn       := !(reset.toBool)
    ioBridgeSink.bundle.aclk          := clock.asUInt
    ioBridgeSink.bundle.aresetn       := !(reset.toBool)
    ioBridgeSink.bundle.rclk          := clock.asUInt
    ioBridgeSink.bundle.rresetn       := !(reset.toBool)

    // source/sink assignment for io will be connected to regmapper 
    ioBridgeSink.bundle.TEST_MODE             := registerIO.bundle.REG_00.data(0)
    ioBridgeSink.bundle.preq                  := registerIO.bundle.REG_00.data(1)
    ioBridgeSink.bundle.pstate                := registerIO.bundle.REG_00.data(4, 2)
    registerIO.bundle.REG_16.data             := Cat(ioBridgeSink.bundle.paccept, ioBridgeSink.bundle.pdeny, ioBridgeSink.bundle.pactive)
  }

}

object NomcTop {
  def attach(c: NomcTopParams)(bap: BlockAttachParams): NomcTop = {
    val omc = NomcTopBase.attach(c)(bap)

    // User code here

    omc
  }
}

class WithomcTop extends Config(
  new WithomcTopBase(
    c1_apb_base = 0x50000L,
    c2_axi_base = 0x1000000000L
  )

    // User code here
)
