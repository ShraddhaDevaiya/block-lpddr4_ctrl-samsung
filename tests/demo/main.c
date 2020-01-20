#include <stdio.h>
#include <stdlib.h>
#include <metal/compiler.h>
#include <metal/io.h>

/*
   test item
*/
#define LPDDR4_CTRL_REG_ACCESS
//#define LPDDR4_CTRL_BUNDLE_ACCESS

/*
   base address of each bus interface
*/
#define CTRL_TL_BASE  0x40000
#define CTRL_APB_BASE 0x50000
#define CTRL_AXI_BASE 0x1000000000
#define CTRL_TL(x)  *((unsigned *)(CTRL_TL_BASE  + x)) 
#define CTRL_APB(x) *((unsigned *)(CTRL_APB_BASE + x)) 
#define CTRL_AXI(x) *((unsigned *)(CTRL_AXI_BASE  + x)) 

/*
   lpddr4 phy register offset and initial value
*/
#define CTRL_REG_00 0x00000000

int main()
{
  uint32_t write_value;
  uint32_t read_value;
  int i;
  int fail = 0;

// #ifdef LPDDR4_PHY_REG_ACCESS
// /*
//    Limited a number of target registers becuase there are too many registers. (totally, there are 2737 registers...)
//    test target registers: first 36 reigsters and the lastest register.
// */
// 
// // (1) Initial value check
//      read_value = CTRL_APB(CTRL_REG_00);  if(read_value != CTRL_REG_00)  fail = 1;   
// 
// // (2) Write & read value check
//      write_value = 0xFFFFFFFF;
//      CTRL_APB(CTRL_REG_00) = write_value;  read_value = CTRL_APB(CTRL_REG_00);  if(write_value != read_value) fail = 1;   
// 
//      write_value = 0xCCAA3355;
//      CTRL_APB(CTRL_REG_00) = write_value;  read_value = CTRL_APB(CTRL_REG_00);  if(write_value != read_value) fail = 1;   
// 
//      write_value = 0x3355CCAA;
//      CTRL_APB(CTRL_REG_00) = write_value;  read_value = CTRL_APB(CTRL_REG_00);  if(write_value != read_value) fail = 1;   
// 
//      write_value = 0x00000000;
//      CTRL_APB(CTRL_REG_00) = write_value;  read_value = CTRL_APB(CTRL_REG_00);  if(write_value != read_value) fail = 1;   
// #endif
// 
// #ifdef LPDDR4_CTRL_BUNDLE_ACCESS
// /*
//    user can control the input pins of lpddr4 top module by register control 
//    this registers are placed within the generated chisel wrapper and connedted via tilelink bus interface.
// */
// // offset: 0x0C
//    write_value = 0xFFFFFFFF;  CTRL_TL(12) = write_value;  read_value = PHY_CTRL(12);   if(write_value != read_value) fail = 1;
//    write_value = 0xCCAA3355;  CTRL_TL(12) = write_value;  read_value = PHY_CTRL(12);   if(write_value != read_value) fail = 1;
//    write_value = 0x3355CCAA;  CTRL_TL(12) = write_value;  read_value = PHY_CTRL(12);   if(write_value != read_value) fail = 1;
//    write_value = 0x00000000;  CTRL_TL(12) = write_value;  read_value = PHY_CTRL(12);   if(write_value != read_value) fail = 1;
// #endif

  return fail;
}
