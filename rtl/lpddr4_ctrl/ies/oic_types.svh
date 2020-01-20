//=============================================================================
// Release information
// Design version: sifive_sesame_rel3_190711
// Document version: OMC-V1.4-UG-R2.11, OMC-V1.4-IG-R1.00-SESAME
// Release generated at Thu Jul 11 15:30:19 2019
//=============================================================================

//=============================================================================
// Description :
//=============================================================================
`ifndef OIC_TYPES
`define OIC_TYPES


// synopsys translate_off

typedef struct {
  // req info
  logic [15:0]  length;
  logic [31:0]  new_id;
  logic [31:0]  org_id;
  logic         data_q_reserve;

  // response info
  logic [63:0]    rb_addr[$];
  logic [1024:0]  rdata[$];
  logic [1:0]     rresp[$];
  logic           rlast[$];
  logic [31:0]    ruser[$];
} rd_rb_burst_t;

typedef struct {
  logic                 data_q_reserve;
  logic [15:0]          length;
  logic [63:0]          rb_addr[$];
  logic [1024+32-1:0]   rb_data[$];
} burst_info_per_id_t;

typedef struct {
  logic [31:0]        new_id[$];
  burst_info_per_id_t burst[integer];
} rb_info_t;

typedef struct {
  logic [31:0]  id;
  logic [1:0]   resp[$];
} b_resp_merge_t;

typedef struct {
  logic             chop_err;
  logic             first_req;
  logic             last_req;
  integer unsigned  saved_index;
} chop_info_t;

typedef struct {
  chop_info_t   chop_info[$];
} chop_info_q_t;


typedef struct {
  logic [31:0]  id;
  logic         rd_wr;
  logic [63:0]  lat_cnt;
} lat_mon_info_t;

typedef struct {
  lat_mon_info_t  lat_mon_info[$];
} lat_mon_info_per_id_t;

// synopsys translate_on

`endif

// vim: tabstop=2 softtabstop=2 shiftwidth=2 expandtab autoindent smartindent
