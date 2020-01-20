//=============================================================================
// Release information
// Design version: sifive_sesame_rel3_190711
// Document version: OMC-V1.4-UG-R2.11, OMC-V1.4-IG-R1.00-SESAME
// Release generated at Thu Jul 11 15:30:19 2019
//=============================================================================

// ============================================================================
// Description:    define file
// =============================================================================

//`ifndef ORBIT_IC_DEFINE
`undef ORBIT_IC_DEFINE

`undef ORBIT_IC_VER
//`timescale 1ns/10ps

// type def or const
`undef THIRST_MODE_OFF        
`undef THIRST_MODE_MO_ONLY    
`undef THIRST_MODE_LAT_ONLY   
`undef THIRST_MODE_MO_OR_LAT  
`undef THIRST_MODE_MO_AND_LAT 

`undef RS_FULL   
`undef RS_FWD    
`undef RS_REV    
`undef RS_BYPASS 
                 
                 
                 
`undef IS_ASYNC  
`undef IS_SYNC2x1
`undef IS_SYNC1x2
`undef IS_SYNC1x1
                 
                 
                 
                 

// Error code define.
`undef ERR_NO          
`undef ERR_FROM_SLAVE  
`undef ERR_DECODE      
`undef ERR_UNREACHABLE 
`undef ERR_TIMEOUT     
`undef ERR_FIRE_DOOR   
`undef ERR_NO_RESPONSE 
`undef ERR_PARITY      
`undef ERR_TZP         
`undef ERR_CHOP        
`undef ERR_BAR_TERM    

`undef E2E_TEST_MODE_AXI_S  
`undef E2E_TEST_MODE_OMC_S  

// AXI protocol related
`undef NO_ERR     
`undef DECODE_ERR 
`undef SLAVE_ERR  

`undef BURST_FIXED 
`undef BURST_INCR  
`undef BURST_WRAP  

// AHB protocol related
`undef AHB_TRANS_IDLE     
`undef AHB_TRANS_BUSY     
`undef AHB_TRANS_NONSEQ   
`undef AHB_TRANS_SEQ      
`undef AHB_HBURST_SINGLE  
`undef AHB_HBURST_INCR    
`undef AHB_HBURST_WRAP4   
`undef AHB_HBURST_INCR4   
`undef AHB_HBURST_WRAP8   
`undef AHB_HBURST_INCR8   
`undef AHB_HBURST_WRAP16  
`undef AHB_HBURST_INCR16  
`undef HRESP_OK           
`undef HRESP_ERROR        
`undef HRESP_RETRY        
`undef HRESP_SPLIT        

// W channel position defines
`undef POS_WLAST 

// A channel position defines
`undef POS_AWRITE 
`undef POS_AQOS 
`undef POS_ADECODEINFO
`undef POS_AROUTEINFO
`undef POS_AID
`undef POS_AADDR
`undef POS_ALEN


// R channel position defines
`undef POS_RROUTEINFO
`undef POS_RLAST
`undef POS_RID
`undef POS_RRESP

// B channel position defines
`undef POS_BROUTEINFO
`undef POS_BID
`undef POS_BRESP

// function macros
`undef calc_ceil_of_log2_of_depth
//  result = source ==   1  ?  0 : \
//           source <=   2  ?  1 : \
//           source <=   4  ?  2 : \
//           source <=   8  ?  3 : \
//           source <=  16  ?  4 : \
//           source <=  32  ?  5 : \
//           source <=  64  ?  6 : \
//           source <=  128 ?  7 : \
//           source <=  256 ?  8 : \
//           source <=  512 ?  9 : \
//           source <= 1024 ? 10 : \
//           source <= 2048 ? 11 : \
//           source <= 4096 ? 12 : \
//           source <= 8192 ? 13 : 14

`undef calc_cnt_bit_width
//  result = source <   1  ?  0 : \
//           source <   2  ?  1 : \
//           source <   4  ?  2 : \
//           source <   8  ?  3 : \
//           source <  16  ?  4 : \
//           source <  32  ?  5 : \
//           source <  64  ?  6 : \
//           source <  128 ?  7 : \
//           source <  256 ?  8 : \
//           source <  512 ?  9 : \
//           source < 1024 ? 10 : \
//           source < 2048 ? 11 : \
//           source < 4096 ? 12 : \
//           source < 8192 ? 13 : 14

`undef get_upper_power_of_2
//  result = source <=     2 ?     2 : \
//           source <=     4 ?     4 : \
//           source <=     8 ?     8 : \
//           source <=    16 ?    16 : \
//           source <=    32 ?    32 : \
//           source <=    64 ?    64 : \
//           source <=   128 ?   128 : \
//           source <=   256 ?   256 : \
//           source <=   512 ?   512 : \
//           source <=  1024 ?  1024 : \
//           source <=  2048 ?  2048 : \
//           source <=  4096 ?  4096 : \
//           source <=  8192 ?  8192 : \
//           source <= 16384 ? 16384 : 16384

`undef calc_cr_word_sel
//  result = source <= (32* 1) ? 1 : \
//           source <= (32* 2) ? 1 : \
//           source <= (32* 4) ? 2 : \
//           source <= (32* 8) ? 3 : \
//           source <= (32*16) ? 4 : 5

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

`undef calc_word_cnt
//  result = source <= 32* 1 ?  1 : \
//           source <= 32* 2 ?  2 : \
//           source <= 32* 3 ?  3 : \
//           source <= 32* 4 ?  4 : \
//           source <= 32* 5 ?  5 : \
//           source <= 32* 6 ?  6 : \
//           source <= 32* 7 ?  7 : \
//           source <= 32* 8 ?  8 : \
//           source <= 32* 9 ?  9 : \
//           source <= 32*10 ? 10 : \
//           source <= 32*11 ? 11 : \
//           source <= 32*12 ? 12 : \
//           source <= 32*13 ? 13 : \
//           source <= 32*14 ? 14 : \
//           source <= 32*15 ? 15 : \
//           source <= 32*16 ? 16 : \
//           source <= 32*17 ? 17 : \
//           source <= 32*18 ? 18 : \
//           source <= 32*19 ? 19 : \
//           source <= 32*20 ? 20 : \
//           source <= 32*21 ? 21 : \
//           source <= 32*22 ? 22 : \
//           source <= 32*23 ? 23 : \
//           source <= 32*24 ? 24 : \
//           source <= 32*25 ? 25 : \
//           source <= 32*26 ? 26 : \
//           source <= 32*27 ? 27 : \
//           source <= 32*28 ? 28 : \
//           source <= 32*29 ? 29 : \
//           source <= 32*20 ? 20 : \
//           source <= 32*31 ? 31 : \
//           source <= 32*32 ? 32 : 0


//`endif


// vim: tabstop=2 expandtab softtabstop=2 shiftwidth=2 smarttab
