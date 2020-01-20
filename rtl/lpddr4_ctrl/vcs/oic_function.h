//=============================================================================
// Release information
// Design version: sifive_sesame_rel3_190711
// Document version: OMC-V1.4-UG-R2.11, OMC-V1.4-IG-R1.00-SESAME
// Release generated at Thu Jul 11 15:30:19 2019
//=============================================================================

// ============================================================================
// Engineer:       peter.bc.jeong@openedges.com
//                 connor.jg.yun@openedges.com
//
// Design Name:    
// Module Name:    
// Project Name:   ORBIT_IC v1.0
// Language:       SystemVerilog
//
// Description:    function define file
//
// Copyright 2016 openedges.com
// =============================================================================

// ACE-lite signal encoding/decoding
function [3:0] ARSNOOP_decomp (input [1:0] ARSNOOP);
  // pragma coverage off
  ARSNOOP_decomp = ARSNOOP == 2'b01 ? 4'b1000 :
                   ARSNOOP == 2'b10 ? 4'b1001 :
                   ARSNOOP == 2'b11 ? 4'b1101 : 4'b0000;
  // pragma coverage on
endfunction

function [1:0] ARSNOOP_comp (input [3:0] ARSNOOP);
  // pragma coverage off
  ARSNOOP_comp = ARSNOOP == 4'b1000 ? 2'b01 :
                 ARSNOOP == 4'b1001 ? 2'b10 :
                 ARSNOOP == 4'b1101 ? 2'b11 : 2'b00;
  // pragma coverage on
endfunction

function [2:0] AWSNOOP_decomp (input [1:0] AWSNOOP);
  // pragma coverage off
  AWSNOOP_decomp = AWSNOOP == 2'b01 ? 3'b001 : 3'b000;
  // pragma coverage on
endfunction

function [1:0] AWSNOOP_comp (input [2:0] AWSNOOP);
  // pragma coverage off
  AWSNOOP_comp = AWSNOOP == 3'b001 ? 2'b01 : 2'b00;
  // pragma coverage on
endfunction

function [11:0] get_cur_addr_lsb12(
  input integer i, 
  input [1:0] aburst, 
  input [7:0] alen,
  input [2:0] asize,
  input [11:0] aaddr
);
  // pragma coverage off
  integer beat_byte, first_beat_skip_byte;
  integer len_plus;
  integer aligned_addr;
  integer cur_byte;
  beat_byte            = (1<<asize);
  aligned_addr         = aaddr & (12'hfff << asize);
  first_beat_skip_byte = (aaddr - aligned_addr);  // spyglass disable W116
  len_plus             = alen + 1;

  if         (aburst == `BURST_WRAP)  begin
    cur_byte = (len_plus * beat_byte);
    if( ((aaddr % cur_byte) + i * beat_byte) >= cur_byte ) begin  // spyglass disable W116
      get_cur_addr_lsb12 = aaddr + i * beat_byte - cur_byte;
    end else begin
      get_cur_addr_lsb12 = aaddr + i * beat_byte;
    end
  end else if(aburst == `BURST_FIXED) begin
    cur_byte = (len_plus * (beat_byte - first_beat_skip_byte));
    get_cur_addr_lsb12 = aaddr;
  end else if(aburst == `BURST_INCR)  begin
    cur_byte = (len_plus * beat_byte -first_beat_skip_byte);
    if(i==0) get_cur_addr_lsb12 = aaddr;
    else     get_cur_addr_lsb12 = aligned_addr + i * beat_byte;
  end
  // pragma coverage on
endfunction

// vim: tabstop=2 expandtab softtabstop=2 shiftwidth=2 smarttab
