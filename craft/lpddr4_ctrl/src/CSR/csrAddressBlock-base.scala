// Generated Code
// Please DO NOT EDIT
package samsung.com.blocks.omc.regmap.CSR.csrAddressBlock

import chisel3._

import freechips.rocketchip.amba.axi4.HasAXI4ControlRegMap
import freechips.rocketchip.config.Parameters
import freechips.rocketchip.diplomacy.LazyModuleImp
import freechips.rocketchip.regmapper._
import freechips.rocketchip.tilelink.HasTLControlRegMap

import samsung.com.blocks.omc.regmap.omcParams

class REG_00RegisterBundle(
  
) extends Bundle {
  val data = Output(UInt(32.W))
}

class REG_01RegisterBundle(
  
) extends Bundle {
  val data = Output(UInt(32.W))
}

class REG_02RegisterBundle(
  
) extends Bundle {
  val data = Output(UInt(32.W))
}

class REG_03RegisterBundle(
  
) extends Bundle {
  val data = Output(UInt(32.W))
}

class REG_04RegisterBundle(
  
) extends Bundle {
  val data = Output(UInt(32.W))
}

class REG_05RegisterBundle(
  
) extends Bundle {
  val data = Output(UInt(32.W))
}

class REG_06RegisterBundle(
  
) extends Bundle {
  val data = Output(UInt(32.W))
}

class REG_07RegisterBundle(
  
) extends Bundle {
  val data = Output(UInt(32.W))
}

class REG_08RegisterBundle(
  
) extends Bundle {
  val data = Output(UInt(32.W))
}

class REG_09RegisterBundle(
  
) extends Bundle {
  val data = Output(UInt(32.W))
}

class REG_10RegisterBundle(
  
) extends Bundle {
  val data = Output(UInt(32.W))
}

class REG_11RegisterBundle(
  
) extends Bundle {
  val data = Output(UInt(32.W))
}

class REG_12RegisterBundle(
  
) extends Bundle {
  val data = Output(UInt(32.W))
}

class REG_13RegisterBundle(
  
) extends Bundle {
  val data = Output(UInt(32.W))
}

class REG_14RegisterBundle(
  
) extends Bundle {
  val data = Output(UInt(32.W))
}

class REG_15RegisterBundle(
  
) extends Bundle {
  val data = Output(UInt(32.W))
}

class REG_16RegisterBundle(
  
) extends Bundle {
  val data = Input(UInt(32.W))
}

class REG_17RegisterBundle(
  
) extends Bundle {
  val data = Input(UInt(32.W))
}

class REG_18RegisterBundle(
  
) extends Bundle {
  val data = Input(UInt(32.W))
}

class REG_19RegisterBundle(
  
) extends Bundle {
  val data = Input(UInt(32.W))
}

class REG_20RegisterBundle(
  
) extends Bundle {
  val data = Input(UInt(32.W))
}

class REG_21RegisterBundle(
  
) extends Bundle {
  val data = Input(UInt(32.W))
}

class REG_22RegisterBundle(
  
) extends Bundle {
  val data = Input(UInt(32.W))
}

class REG_23RegisterBundle(
  
) extends Bundle {
  val data = Input(UInt(32.W))
}

class REG_24RegisterBundle(
  
) extends Bundle {
  val data = Input(UInt(32.W))
}

class REG_25RegisterBundle(
  
) extends Bundle {
  val data = Input(UInt(32.W))
}

class REG_26RegisterBundle(
  
) extends Bundle {
  val data = Input(UInt(32.W))
}

class REG_27RegisterBundle(
  
) extends Bundle {
  val data = Input(UInt(32.W))
}

class REG_28RegisterBundle(
  
) extends Bundle {
  val data = Input(UInt(32.W))
}

class REG_29RegisterBundle(
  
) extends Bundle {
  val data = Input(UInt(32.W))
}

class REG_30RegisterBundle(
  
) extends Bundle {
  val data = Input(UInt(32.W))
}

class REG_31RegisterBundle(
  
) extends Bundle {
  val data = Input(UInt(32.W))
}

class csrAddressBlockAddressBlockBundle(val params: omcParams) extends Bundle {
  val REG_00 = new REG_00RegisterBundle(
    
  )
  val REG_01 = new REG_01RegisterBundle(
    
  )
  val REG_02 = new REG_02RegisterBundle(
    
  )
  val REG_03 = new REG_03RegisterBundle(
    
  )
  val REG_04 = new REG_04RegisterBundle(
    
  )
  val REG_05 = new REG_05RegisterBundle(
    
  )
  val REG_06 = new REG_06RegisterBundle(
    
  )
  val REG_07 = new REG_07RegisterBundle(
    
  )
  val REG_08 = new REG_08RegisterBundle(
    
  )
  val REG_09 = new REG_09RegisterBundle(
    
  )
  val REG_10 = new REG_10RegisterBundle(
    
  )
  val REG_11 = new REG_11RegisterBundle(
    
  )
  val REG_12 = new REG_12RegisterBundle(
    
  )
  val REG_13 = new REG_13RegisterBundle(
    
  )
  val REG_14 = new REG_14RegisterBundle(
    
  )
  val REG_15 = new REG_15RegisterBundle(
    
  )
  val REG_16 = new REG_16RegisterBundle(
    
  )
  val REG_17 = new REG_17RegisterBundle(
    
  )
  val REG_18 = new REG_18RegisterBundle(
    
  )
  val REG_19 = new REG_19RegisterBundle(
    
  )
  val REG_20 = new REG_20RegisterBundle(
    
  )
  val REG_21 = new REG_21RegisterBundle(
    
  )
  val REG_22 = new REG_22RegisterBundle(
    
  )
  val REG_23 = new REG_23RegisterBundle(
    
  )
  val REG_24 = new REG_24RegisterBundle(
    
  )
  val REG_25 = new REG_25RegisterBundle(
    
  )
  val REG_26 = new REG_26RegisterBundle(
    
  )
  val REG_27 = new REG_27RegisterBundle(
    
  )
  val REG_28 = new REG_28RegisterBundle(
    
  )
  val REG_29 = new REG_29RegisterBundle(
    
  )
  val REG_30 = new REG_30RegisterBundle(
    
  )
  val REG_31 = new REG_31RegisterBundle(
    
  )
}

object csrAddressBlockRegRouterBase {
  def deviceTreeName: String = "omc-csrAddressBlock"
  def deviceTreeCompat: Seq[String] = Seq("samsung.com,omc-0.1.0")

  object resetValues {
    object REG_00 {
      def data: UInt = 0.U
    }
    
    object REG_01 {
      def data: UInt = 0.U
    }
    
    object REG_02 {
      def data: UInt = 0.U
    }
    
    object REG_03 {
      def data: UInt = 0.U
    }
    
    object REG_04 {
      def data: UInt = 0.U
    }
    
    object REG_05 {
      def data: UInt = 0.U
    }
    
    object REG_06 {
      def data: UInt = 0.U
    }
    
    object REG_07 {
      def data: UInt = 0.U
    }
    
    object REG_08 {
      def data: UInt = 0.U
    }
    
    object REG_09 {
      def data: UInt = 0.U
    }
    
    object REG_10 {
      def data: UInt = 0.U
    }
    
    object REG_11 {
      def data: UInt = 0.U
    }
    
    object REG_12 {
      def data: UInt = 0.U
    }
    
    object REG_13 {
      def data: UInt = 0.U
    }
    
    object REG_14 {
      def data: UInt = 0.U
    }
    
    object REG_15 {
      def data: UInt = 0.U
    }
    
    object REG_16 {
      def data: UInt = 0.U
    }
    
    object REG_17 {
      def data: UInt = 0.U
    }
    
    object REG_18 {
      def data: UInt = 0.U
    }
    
    object REG_19 {
      def data: UInt = 0.U
    }
    
    object REG_20 {
      def data: UInt = 0.U
    }
    
    object REG_21 {
      def data: UInt = 0.U
    }
    
    object REG_22 {
      def data: UInt = 0.U
    }
    
    object REG_23 {
      def data: UInt = 0.U
    }
    
    object REG_24 {
      def data: UInt = 0.U
    }
    
    object REG_25 {
      def data: UInt = 0.U
    }
    
    object REG_26 {
      def data: UInt = 0.U
    }
    
    object REG_27 {
      def data: UInt = 0.U
    }
    
    object REG_28 {
      def data: UInt = 0.U
    }
    
    object REG_29 {
      def data: UInt = 0.U
    }
    
    object REG_30 {
      def data: UInt = 0.U
    }
    
    object REG_31 {
      def data: UInt = 0.U
    }
  }
}

abstract class csrAddressBlockRegRouter(
  busWidthBytes: Int,
  baseAddress: Long,
  componentParams: omcParams)(implicit p: Parameters)
  extends IORegisterRouter(
    RegisterRouterParams(
      name = csrAddressBlockRegRouterUser.deviceTreeName,
      compat = csrAddressBlockRegRouterUser.deviceTreeCompat,
      base = baseAddress,
      beatBytes = busWidthBytes),
    new csrAddressBlockAddressBlockBundle(componentParams)) {

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

  lazy val module = new LazyModuleImp(this) {
    val resetValue = Wire(Output(port.cloneType))
    resetValue.REG_00.data := csrAddressBlockRegRouterUser.resetValues.REG_00.data
    resetValue.REG_01.data := csrAddressBlockRegRouterUser.resetValues.REG_01.data
    resetValue.REG_02.data := csrAddressBlockRegRouterUser.resetValues.REG_02.data
    resetValue.REG_03.data := csrAddressBlockRegRouterUser.resetValues.REG_03.data
    resetValue.REG_04.data := csrAddressBlockRegRouterUser.resetValues.REG_04.data
    resetValue.REG_05.data := csrAddressBlockRegRouterUser.resetValues.REG_05.data
    resetValue.REG_06.data := csrAddressBlockRegRouterUser.resetValues.REG_06.data
    resetValue.REG_07.data := csrAddressBlockRegRouterUser.resetValues.REG_07.data
    resetValue.REG_08.data := csrAddressBlockRegRouterUser.resetValues.REG_08.data
    resetValue.REG_09.data := csrAddressBlockRegRouterUser.resetValues.REG_09.data
    resetValue.REG_10.data := csrAddressBlockRegRouterUser.resetValues.REG_10.data
    resetValue.REG_11.data := csrAddressBlockRegRouterUser.resetValues.REG_11.data
    resetValue.REG_12.data := csrAddressBlockRegRouterUser.resetValues.REG_12.data
    resetValue.REG_13.data := csrAddressBlockRegRouterUser.resetValues.REG_13.data
    resetValue.REG_14.data := csrAddressBlockRegRouterUser.resetValues.REG_14.data
    resetValue.REG_15.data := csrAddressBlockRegRouterUser.resetValues.REG_15.data
    resetValue.REG_16.data := csrAddressBlockRegRouterUser.resetValues.REG_16.data
    resetValue.REG_17.data := csrAddressBlockRegRouterUser.resetValues.REG_17.data
    resetValue.REG_18.data := csrAddressBlockRegRouterUser.resetValues.REG_18.data
    resetValue.REG_19.data := csrAddressBlockRegRouterUser.resetValues.REG_19.data
    resetValue.REG_20.data := csrAddressBlockRegRouterUser.resetValues.REG_20.data
    resetValue.REG_21.data := csrAddressBlockRegRouterUser.resetValues.REG_21.data
    resetValue.REG_22.data := csrAddressBlockRegRouterUser.resetValues.REG_22.data
    resetValue.REG_23.data := csrAddressBlockRegRouterUser.resetValues.REG_23.data
    resetValue.REG_24.data := csrAddressBlockRegRouterUser.resetValues.REG_24.data
    resetValue.REG_25.data := csrAddressBlockRegRouterUser.resetValues.REG_25.data
    resetValue.REG_26.data := csrAddressBlockRegRouterUser.resetValues.REG_26.data
    resetValue.REG_27.data := csrAddressBlockRegRouterUser.resetValues.REG_27.data
    resetValue.REG_28.data := csrAddressBlockRegRouterUser.resetValues.REG_28.data
    resetValue.REG_29.data := csrAddressBlockRegRouterUser.resetValues.REG_29.data
    resetValue.REG_30.data := csrAddressBlockRegRouterUser.resetValues.REG_30.data
    resetValue.REG_31.data := csrAddressBlockRegRouterUser.resetValues.REG_31.data

    val register = RegInit(resetValue)
    port.REG_00.data := register.REG_00.data
    port.REG_01.data := register.REG_01.data
    port.REG_02.data := register.REG_02.data
    port.REG_03.data := register.REG_03.data
    port.REG_04.data := register.REG_04.data
    port.REG_05.data := register.REG_05.data
    port.REG_06.data := register.REG_06.data
    port.REG_07.data := register.REG_07.data
    port.REG_08.data := register.REG_08.data
    port.REG_09.data := register.REG_09.data
    port.REG_10.data := register.REG_10.data
    port.REG_11.data := register.REG_11.data
    port.REG_12.data := register.REG_12.data
    port.REG_13.data := register.REG_13.data
    port.REG_14.data := register.REG_14.data
    port.REG_15.data := register.REG_15.data
    register.REG_16.data := port.REG_16.data
    register.REG_17.data := port.REG_17.data
    register.REG_18.data := port.REG_18.data
    register.REG_19.data := port.REG_19.data
    register.REG_20.data := port.REG_20.data
    register.REG_21.data := port.REG_21.data
    register.REG_22.data := port.REG_22.data
    register.REG_23.data := port.REG_23.data
    register.REG_24.data := port.REG_24.data
    register.REG_25.data := port.REG_25.data
    register.REG_26.data := port.REG_26.data
    register.REG_27.data := port.REG_27.data
    register.REG_28.data := port.REG_28.data
    register.REG_29.data := port.REG_29.data
    register.REG_30.data := port.REG_30.data
    register.REG_31.data := port.REG_31.data

    val mapping = {
      
      Seq(
        0 -> RegFieldGroup("REG_00", None, padFields(
          0 -> RegField(32, register.REG_00.data, RegFieldDesc("data", "")))),
        4 -> RegFieldGroup("REG_01", None, padFields(
          0 -> RegField(32, register.REG_01.data, RegFieldDesc("data", "")))),
        8 -> RegFieldGroup("REG_02", None, padFields(
          0 -> RegField(32, register.REG_02.data, RegFieldDesc("data", "")))),
        12 -> RegFieldGroup("REG_03", None, padFields(
          0 -> RegField(32, register.REG_03.data, RegFieldDesc("data", "")))),
        16 -> RegFieldGroup("REG_04", None, padFields(
          0 -> RegField(32, register.REG_04.data, RegFieldDesc("data", "")))),
        20 -> RegFieldGroup("REG_05", None, padFields(
          0 -> RegField(32, register.REG_05.data, RegFieldDesc("data", "")))),
        24 -> RegFieldGroup("REG_06", None, padFields(
          0 -> RegField(32, register.REG_06.data, RegFieldDesc("data", "")))),
        28 -> RegFieldGroup("REG_07", None, padFields(
          0 -> RegField(32, register.REG_07.data, RegFieldDesc("data", "")))),
        32 -> RegFieldGroup("REG_08", None, padFields(
          0 -> RegField(32, register.REG_08.data, RegFieldDesc("data", "")))),
        36 -> RegFieldGroup("REG_09", None, padFields(
          0 -> RegField(32, register.REG_09.data, RegFieldDesc("data", "")))),
        40 -> RegFieldGroup("REG_10", None, padFields(
          0 -> RegField(32, register.REG_10.data, RegFieldDesc("data", "")))),
        44 -> RegFieldGroup("REG_11", None, padFields(
          0 -> RegField(32, register.REG_11.data, RegFieldDesc("data", "")))),
        48 -> RegFieldGroup("REG_12", None, padFields(
          0 -> RegField(32, register.REG_12.data, RegFieldDesc("data", "")))),
        52 -> RegFieldGroup("REG_13", None, padFields(
          0 -> RegField(32, register.REG_13.data, RegFieldDesc("data", "")))),
        56 -> RegFieldGroup("REG_14", None, padFields(
          0 -> RegField(32, register.REG_14.data, RegFieldDesc("data", "")))),
        60 -> RegFieldGroup("REG_15", None, padFields(
          0 -> RegField(32, register.REG_15.data, RegFieldDesc("data", "")))),
        64 -> RegFieldGroup("REG_16", None, padFields(
          0 -> RegField.r(32, register.REG_16.data, RegFieldDesc("data", "")))),
        68 -> RegFieldGroup("REG_17", None, padFields(
          0 -> RegField.r(32, register.REG_17.data, RegFieldDesc("data", "")))),
        72 -> RegFieldGroup("REG_18", None, padFields(
          0 -> RegField.r(32, register.REG_18.data, RegFieldDesc("data", "")))),
        76 -> RegFieldGroup("REG_19", None, padFields(
          0 -> RegField.r(32, register.REG_19.data, RegFieldDesc("data", "")))),
        80 -> RegFieldGroup("REG_20", None, padFields(
          0 -> RegField.r(32, register.REG_20.data, RegFieldDesc("data", "")))),
        84 -> RegFieldGroup("REG_21", None, padFields(
          0 -> RegField.r(32, register.REG_21.data, RegFieldDesc("data", "")))),
        88 -> RegFieldGroup("REG_22", None, padFields(
          0 -> RegField.r(32, register.REG_22.data, RegFieldDesc("data", "")))),
        92 -> RegFieldGroup("REG_23", None, padFields(
          0 -> RegField.r(32, register.REG_23.data, RegFieldDesc("data", "")))),
        96 -> RegFieldGroup("REG_24", None, padFields(
          0 -> RegField.r(32, register.REG_24.data, RegFieldDesc("data", "")))),
        100 -> RegFieldGroup("REG_25", None, padFields(
          0 -> RegField.r(32, register.REG_25.data, RegFieldDesc("data", "")))),
        104 -> RegFieldGroup("REG_26", None, padFields(
          0 -> RegField.r(32, register.REG_26.data, RegFieldDesc("data", "")))),
        108 -> RegFieldGroup("REG_27", None, padFields(
          0 -> RegField.r(32, register.REG_27.data, RegFieldDesc("data", "")))),
        112 -> RegFieldGroup("REG_28", None, padFields(
          0 -> RegField.r(32, register.REG_28.data, RegFieldDesc("data", "")))),
        116 -> RegFieldGroup("REG_29", None, padFields(
          0 -> RegField.r(32, register.REG_29.data, RegFieldDesc("data", "")))),
        120 -> RegFieldGroup("REG_30", None, padFields(
          0 -> RegField.r(32, register.REG_30.data, RegFieldDesc("data", "")))),
        124 -> RegFieldGroup("REG_31", None, padFields(
          0 -> RegField.r(32, register.REG_31.data, RegFieldDesc("data", "")))))
    }

    regmap(mapping:_*)
  }
}

class csrAddressBlockTLRegMap(busWidthBytes: Int, baseAddress: Long, componentParams: omcParams)(implicit p: Parameters)
  extends csrAddressBlockRegRouter(busWidthBytes, baseAddress, componentParams) with HasTLControlRegMap

class csrAddressBlockAXI4RegMapAXI4RegMap(busWidthBytes: Int, baseAddress: Long, componentParams: omcParams)(implicit p: Parameters)
  extends csrAddressBlockRegRouter(busWidthBytes, baseAddress, componentParams) with HasAXI4ControlRegMap