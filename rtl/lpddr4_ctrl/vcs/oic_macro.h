//=============================================================================
// Release information
// Design version: sifive_sesame_rel3_190711
// Document version: OMC-V1.4-UG-R2.11, OMC-V1.4-IG-R1.00-SESAME
// Release generated at Thu Jul 11 15:30:19 2019
//=============================================================================

//=============================================================================
// Description :
//=============================================================================

`define axi_to_axi_payld(axi_postfix, axi_payld_if) \
  assign arv_``axi_payld_if`` = arvalid_``axi_postfix``; assign arready_``axi_postfix`` = arr_``axi_payld_if``; \
  assign awv_``axi_payld_if`` = awvalid_``axi_postfix``; assign awready_``axi_postfix`` = awr_``axi_payld_if``; \
  assign wv_``axi_payld_if``  =  wvalid_``axi_postfix``; assign  wready_``axi_postfix`` = wr_``axi_payld_if`` ; \
  assign rvalid_``axi_postfix`` = rv_``axi_payld_if``  ; assign rr_``axi_payld_if`` = rready_``axi_postfix``  ; \
  assign bvalid_``axi_postfix`` = bv_``axi_payld_if``  ; assign br_``axi_payld_if`` = bready_``axi_postfix``  ; \
  generate \
    if(USER_WIDTH > 0) begin : BLK_with_user \
      assign arp_``axi_payld_if`` = {      arqos_``axi_postfix``, \
                                        arlen_``axi_postfix``[3:0], \
                                         arid_``axi_postfix``, \
                                       araddr_``axi_postfix``, \
                                       arsize_``axi_postfix``, \
                                      arburst_``axi_postfix``, \
                                      arcache_``axi_postfix``, \
                                       arprot_``axi_postfix``, \
                                       arlock_``axi_postfix``[0], \
                                       aruser_``axi_postfix``}; \
      assign awp_``axi_payld_if`` = {      awqos_``axi_postfix``, \
                                        awlen_``axi_postfix``[3:0], \
                                         awid_``axi_postfix``, \
                                       awaddr_``axi_postfix``, \
                                       awsize_``axi_postfix``, \
                                      awburst_``axi_postfix``, \
                                      awcache_``axi_postfix``, \
                                       awprot_``axi_postfix``, \
                                       awlock_``axi_postfix``[0], \
                                       awuser_``axi_postfix``}; \
      assign wp_``axi_payld_if``  = {      wstrb_``axi_postfix``, \
                                        wdata_``axi_postfix``, \
                                        wlast_``axi_postfix``}; \
      assign {rid_``axi_postfix``, rresp_``axi_postfix``, rdata_``axi_postfix``, rlast_``axi_postfix``, ruser_``axi_postfix``} = {rp_``axi_payld_if``}; \
      assign {bid_``axi_postfix``, bresp_``axi_postfix``, buser_``axi_postfix``}                     = {bp_``axi_payld_if``}; \
    end else begin : BLK_without_user \
      assign arp_``axi_payld_if`` = {      arqos_``axi_postfix``, \
                                        arlen_``axi_postfix``[3:0], \
                                         arid_``axi_postfix``, \
                                       araddr_``axi_postfix``, \
                                       arsize_``axi_postfix``, \
                                      arburst_``axi_postfix``, \
                                      arcache_``axi_postfix``, \
                                       arprot_``axi_postfix``, \
                                       arlock_``axi_postfix``[0]}; \
      assign awp_``axi_payld_if`` = {      awqos_``axi_postfix``, \
                                        awlen_``axi_postfix``[3:0], \
                                         awid_``axi_postfix``, \
                                       awaddr_``axi_postfix``, \
                                       awsize_``axi_postfix``, \
                                      awburst_``axi_postfix``, \
                                      awcache_``axi_postfix``, \
                                       awprot_``axi_postfix``, \
                                       awlock_``axi_postfix``[0]}; \
      assign wp_``axi_payld_if``  = {      wstrb_``axi_postfix``, \
                                        wdata_``axi_postfix``, \
                                        wlast_``axi_postfix``}; \
      assign {rid_``axi_postfix``, rresp_``axi_postfix``, rdata_``axi_postfix``, rlast_``axi_postfix``} = {rp_``axi_payld_if``}; \
      assign {bid_``axi_postfix``, bresp_``axi_postfix``}                     = {bp_``axi_payld_if``}; \
    end \
  endgenerate
  


`define ace_lite_to_ace_lite_payld(axi_postfix, axi_payld_if) \
  assign arv_``axi_payld_if`` = arvalid_``axi_postfix``; assign arready_``axi_postfix`` = arr_``axi_payld_if``; \
  assign awv_``axi_payld_if`` = awvalid_``axi_postfix``; assign awready_``axi_postfix`` = awr_``axi_payld_if``; \
  assign wv_``axi_payld_if``  =  wvalid_``axi_postfix``; assign  wready_``axi_postfix`` = wr_``axi_payld_if`` ; \
  assign rvalid_``axi_postfix`` = rv_``axi_payld_if``  ; assign rr_``axi_payld_if`` = rready_``axi_postfix``  ; \
  assign bvalid_``axi_postfix`` = bv_``axi_payld_if``  ; assign br_``axi_payld_if`` = bready_``axi_postfix``  ; \
  generate \
    if((USER_WIDTH > 0) && (ROUTE_WIDTH > 0)) begin : BLK_with_route_user \
      assign arp_``axi_payld_if`` = {      arqos_``axi_postfix``, \
                                        arlen_``axi_postfix``[3:0], \
                                         arid_``axi_postfix``[NEW_ID_WIDTH+ROUTE_WIDTH-1:ROUTE_WIDTH], \
                                       araddr_``axi_postfix``, \
                                       arsize_``axi_postfix``, \
                                      arburst_``axi_postfix``, \
                                      arcache_``axi_postfix``, \
                                       arprot_``axi_postfix``, \
                                       arlock_``axi_postfix``[0], \
                         ARSNOOP_comp(arsnoop_``axi_postfix``), \
                                     ardomain_``axi_postfix``, \
                                        arbar_``axi_postfix``[0], \
                                       aruser_``axi_postfix``, \
                                         arid_``axi_postfix``[ROUTE_WIDTH-1:0]}; \
      assign awp_``axi_payld_if`` = {      awqos_``axi_postfix``, \
                                        awlen_``axi_postfix``[3:0], \
                                         awid_``axi_postfix``[NEW_ID_WIDTH+ROUTE_WIDTH-1:ROUTE_WIDTH], \
                                       awaddr_``axi_postfix``, \
                                       awsize_``axi_postfix``, \
                                      awburst_``axi_postfix``, \
                                      awcache_``axi_postfix``, \
                                       awprot_``axi_postfix``, \
                                       awlock_``axi_postfix``[0], \
                         AWSNOOP_comp(awsnoop_``axi_postfix``), \
                                     awdomain_``axi_postfix``, \
                                        awbar_``axi_postfix``[0], \
                                       awuser_``axi_postfix``, \
                                         awid_``axi_postfix``[ROUTE_WIDTH-1:0]}; \
      assign wp_``axi_payld_if``  = {      wstrb_``axi_postfix``, \
                                        wdata_``axi_postfix``, \
                                        wlast_``axi_postfix``}; \
      assign {    rid_``axi_postfix``[NEW_ID_WIDTH+ROUTE_WIDTH-1:ROUTE_WIDTH], \
                rresp_``axi_postfix``, \
                rdata_``axi_postfix``, \
                rlast_``axi_postfix``, \
                ruser_``axi_postfix``, \
                  rid_``axi_postfix``[ROUTE_WIDTH-1:0]} = {rp_``axi_payld_if``}; \
      assign {    bid_``axi_postfix``[NEW_ID_WIDTH+ROUTE_WIDTH-1:ROUTE_WIDTH], \
                bresp_``axi_postfix``, \
                buser_``axi_postfix``, \
                  bid_``axi_postfix``[ROUTE_WIDTH-1:0]} = {bp_``axi_payld_if``}; \
    end \
    else if(USER_WIDTH > 0) begin : BLK_with_user \
      assign arp_``axi_payld_if`` = {      arqos_``axi_postfix``, \
                                        arlen_``axi_postfix``[3:0], \
                                         arid_``axi_postfix``, \
                                       araddr_``axi_postfix``, \
                                       arsize_``axi_postfix``, \
                                      arburst_``axi_postfix``, \
                                      arcache_``axi_postfix``, \
                                       arprot_``axi_postfix``, \
                                       arlock_``axi_postfix``[0], \
                         ARSNOOP_comp(arsnoop_``axi_postfix``), \
                                     ardomain_``axi_postfix``, \
                                        arbar_``axi_postfix``[0], \
                                       aruser_``axi_postfix``}; \
      assign awp_``axi_payld_if`` = {      awqos_``axi_postfix``, \
                                        awlen_``axi_postfix``[3:0], \
                                         awid_``axi_postfix``, \
                                       awaddr_``axi_postfix``, \
                                       awsize_``axi_postfix``, \
                                      awburst_``axi_postfix``, \
                                      awcache_``axi_postfix``, \
                                       awprot_``axi_postfix``, \
                                       awlock_``axi_postfix``[0], \
                         AWSNOOP_comp(awsnoop_``axi_postfix``), \
                                     awdomain_``axi_postfix``, \
                                        awbar_``axi_postfix``[0], \
                                       awuser_``axi_postfix``}; \
      assign wp_``axi_payld_if``  = {      wstrb_``axi_postfix``, \
                                        wdata_``axi_postfix``, \
                                        wlast_``axi_postfix``}; \
      assign {rid_``axi_postfix``, rresp_``axi_postfix``, rdata_``axi_postfix``, rlast_``axi_postfix``, ruser_``axi_postfix``} = {rp_``axi_payld_if``}; \
      assign {bid_``axi_postfix``, bresp_``axi_postfix``, buser_``axi_postfix``}                     = {bp_``axi_payld_if``}; \
    end \
    else if(ROUTE_WIDTH > 0) begin : BLK_with_route \
      assign arp_``axi_payld_if`` = {      arqos_``axi_postfix``, \
                                        arlen_``axi_postfix``[3:0], \
                                         arid_``axi_postfix``[NEW_ID_WIDTH+ROUTE_WIDTH-1:ROUTE_WIDTH], \
                                       araddr_``axi_postfix``, \
                                       arsize_``axi_postfix``, \
                                      arburst_``axi_postfix``, \
                                      arcache_``axi_postfix``, \
                                       arprot_``axi_postfix``, \
                                       arlock_``axi_postfix``[0], \
                         ARSNOOP_comp(arsnoop_``axi_postfix``), \
                                     ardomain_``axi_postfix``, \
                                        arbar_``axi_postfix``[0], \
                                         arid_``axi_postfix``[ROUTE_WIDTH-1:0]}; \
      assign awp_``axi_payld_if`` = {      awqos_``axi_postfix``, \
                                        awlen_``axi_postfix``[3:0], \
                                         awid_``axi_postfix``[NEW_ID_WIDTH+ROUTE_WIDTH-1:ROUTE_WIDTH], \
                                       awaddr_``axi_postfix``, \
                                       awsize_``axi_postfix``, \
                                      awburst_``axi_postfix``, \
                                      awcache_``axi_postfix``, \
                                       awprot_``axi_postfix``, \
                                       awlock_``axi_postfix``[0], \
                         AWSNOOP_comp(awsnoop_``axi_postfix``), \
                                     awdomain_``axi_postfix``, \
                                        awbar_``axi_postfix``[0], \
                                         awid_``axi_postfix``[ROUTE_WIDTH-1:0]}; \
      assign wp_``axi_payld_if``  = {      wstrb_``axi_postfix``, \
                                        wdata_``axi_postfix``, \
                                        wlast_``axi_postfix``}; \
      assign {    rid_``axi_postfix``[NEW_ID_WIDTH+ROUTE_WIDTH-1:ROUTE_WIDTH], \
                rresp_``axi_postfix``, \
                rdata_``axi_postfix``, \
                rlast_``axi_postfix``, \
                  rid_``axi_postfix``[ROUTE_WIDTH-1:0]} = {rp_``axi_payld_if``}; \
      assign {    bid_``axi_postfix``[NEW_ID_WIDTH+ROUTE_WIDTH-1:ROUTE_WIDTH], \
                bresp_``axi_postfix``, \
                  bid_``axi_postfix``[ROUTE_WIDTH-1:0]} = {bp_``axi_payld_if``}; \
    end \
    else begin : BLK_without_user \
      assign arp_``axi_payld_if`` = {      arqos_``axi_postfix``, \
                                        arlen_``axi_postfix``[3:0], \
                                         arid_``axi_postfix``, \
                                       araddr_``axi_postfix``, \
                                       arsize_``axi_postfix``, \
                                      arburst_``axi_postfix``, \
                                      arcache_``axi_postfix``, \
                                       arprot_``axi_postfix``, \
                                       arlock_``axi_postfix``[0], \
                         ARSNOOP_comp(arsnoop_``axi_postfix``), \
                                     ardomain_``axi_postfix``, \
                                        arbar_``axi_postfix``[0]}; \
      assign awp_``axi_payld_if`` = {      awqos_``axi_postfix``, \
                                        awlen_``axi_postfix``[3:0], \
                                         awid_``axi_postfix``, \
                                       awaddr_``axi_postfix``, \
                                       awsize_``axi_postfix``, \
                                      awburst_``axi_postfix``, \
                                      awcache_``axi_postfix``, \
                                       awprot_``axi_postfix``, \
                                       awlock_``axi_postfix``[0], \
                         AWSNOOP_comp(awsnoop_``axi_postfix``), \
                                     awdomain_``axi_postfix``, \
                                        awbar_``axi_postfix``[0]}; \
      assign wp_``axi_payld_if``  = {      wstrb_``axi_postfix``, \
                                        wdata_``axi_postfix``, \
                                        wlast_``axi_postfix``}; \
      assign {rid_``axi_postfix``, rresp_``axi_postfix``, rdata_``axi_postfix``, rlast_``axi_postfix``} = {rp_``axi_payld_if``}; \
      assign {bid_``axi_postfix``, bresp_``axi_postfix``}                     = {bp_``axi_payld_if``}; \
    end \
  endgenerate
  


`define ace_lite_to_hxi_payld(axi_postfix, axi_payld_if) \
  assign arv_``axi_payld_if`` = arvalid_``axi_postfix``; assign arready_``axi_postfix`` = arr_``axi_payld_if``; \
  assign awv_``axi_payld_if`` = awvalid_``axi_postfix``; assign awready_``axi_postfix`` = awr_``axi_payld_if``; \
  assign wv_``axi_payld_if``  =  wvalid_``axi_postfix``; assign  wready_``axi_postfix`` = wr_``axi_payld_if`` ; \
  assign rvalid_``axi_postfix`` = rv_``axi_payld_if``  ; assign rr_``axi_payld_if`` = rready_``axi_postfix``  ; \
  assign bvalid_``axi_postfix`` = bv_``axi_payld_if``  ; assign br_``axi_payld_if`` = bready_``axi_postfix``  ; \
  generate \
    if(USER_WIDTH > 0) begin : BLK_with_user \
      assign arp_``axi_payld_if`` = {      arqos_``axi_postfix``, \
                                        arlen_``axi_postfix``[3:0], \
                                         arid_``axi_postfix``, \
                                       araddr_``axi_postfix``, \
                                       arsize_``axi_postfix``, \
                                      arburst_``axi_postfix``, \
                                      arcache_``axi_postfix``, \
                                       arprot_``axi_postfix``, \
                                       arlock_``axi_postfix``[0], \
                         ARSNOOP_comp(arsnoop_``axi_postfix``), \
                                     ardomain_``axi_postfix``, \
                                       aruser_``axi_postfix``}; \
      assign awp_``axi_payld_if`` = {      awqos_``axi_postfix``, \
                                        awlen_``axi_postfix``[3:0], \
                                         awid_``axi_postfix``, \
                                       awaddr_``axi_postfix``, \
                                       awsize_``axi_postfix``, \
                                      awburst_``axi_postfix``, \
                                      awcache_``axi_postfix``, \
                                       awprot_``axi_postfix``, \
                                       awlock_``axi_postfix``[0], \
                         AWSNOOP_comp(awsnoop_``axi_postfix``), \
                                     awdomain_``axi_postfix``, \
                                       awuser_``axi_postfix``}; \
      assign wp_``axi_payld_if``  = {      wstrb_``axi_postfix``, \
                                        wdata_``axi_postfix``, \
                                        wlast_``axi_postfix``}; \
      assign {rid_``axi_postfix``, rresp_``axi_postfix``, rdata_``axi_postfix``, rlast_``axi_postfix``, ruser_``axi_postfix``} = {rp_``axi_payld_if``}; \
      assign {bid_``axi_postfix``, bresp_``axi_postfix``, buser_``axi_postfix``}                     = {bp_``axi_payld_if``}; \
    end else begin : BLK_without_user \
      assign arp_``axi_payld_if`` = {      arqos_``axi_postfix``, \
                                        arlen_``axi_postfix``[3:0], \
                                         arid_``axi_postfix``, \
                                       araddr_``axi_postfix``, \
                                       arsize_``axi_postfix``, \
                                      arburst_``axi_postfix``, \
                                      arcache_``axi_postfix``, \
                                       arprot_``axi_postfix``, \
                                       arlock_``axi_postfix``[0], \
                         ARSNOOP_comp(arsnoop_``axi_postfix``), \
                                     ardomain_``axi_postfix``}; \
      assign awp_``axi_payld_if`` = {      awqos_``axi_postfix``, \
                                        awlen_``axi_postfix``[3:0], \
                                         awid_``axi_postfix``, \
                                       awaddr_``axi_postfix``, \
                                       awsize_``axi_postfix``, \
                                      awburst_``axi_postfix``, \
                                      awcache_``axi_postfix``, \
                                       awprot_``axi_postfix``, \
                                       awlock_``axi_postfix``[0], \
                         AWSNOOP_comp(awsnoop_``axi_postfix``), \
                                     awdomain_``axi_postfix``}; \
      assign wp_``axi_payld_if``  = {      wstrb_``axi_postfix``, \
                                        wdata_``axi_postfix``, \
                                        wlast_``axi_postfix``}; \
      assign {rid_``axi_postfix``, rresp_``axi_postfix``, rdata_``axi_postfix``, rlast_``axi_postfix``} = {rp_``axi_payld_if``}; \
      assign {bid_``axi_postfix``, bresp_``axi_postfix``}                     = {bp_``axi_payld_if``}; \
    end \
  endgenerate
  


`define ace_lite_payld_to_ace_lite(axi_postfix, axi_payld_if) \
  wire [1:0]  arsnoop_conv, awsnoop_conv; \
  assign arvalid_``axi_postfix`` = arv_``axi_payld_if``; assign arr_``axi_payld_if`` = arready_``axi_postfix``; \
  assign awvalid_``axi_postfix`` = awv_``axi_payld_if``; assign awr_``axi_payld_if`` = awready_``axi_postfix``; \
  assign  wvalid_``axi_postfix`` = wv_``axi_payld_if`` ; assign  wr_``axi_payld_if``  = wready_``axi_postfix``; \
  assign rv_``axi_payld_if``   = rvalid_``axi_postfix``; assign rready_``axi_postfix``   = rr_``axi_payld_if``; \
  assign bv_``axi_payld_if``   = bvalid_``axi_postfix``; assign bready_``axi_postfix``   = br_``axi_payld_if``; \
  generate \
    if((USER_WIDTH > 0) && (ROUTE_WIDTH > 0)) begin : BLK_with_user_route \
      assign  {   arqos_``axi_postfix``, \
                  arlen_``axi_postfix``[3:0], \
                   arid_``axi_postfix``[NEW_ID_WIDTH+ROUTE_WIDTH-1:ROUTE_WIDTH], \
                 araddr_``axi_postfix``, \
                 arsize_``axi_postfix``, \
                arburst_``axi_postfix``, \
                arcache_``axi_postfix``, \
                 arprot_``axi_postfix``, \
                 arlock_``axi_postfix``[0], \
                arsnoop_conv, \
               ardomain_``axi_postfix``, \
                 aruser_``axi_postfix``, \
                   arid_``axi_postfix``[ROUTE_WIDTH-1:0]} = arp_``axi_payld_if``; \
      assign  {   awqos_``axi_postfix``, \
                  awlen_``axi_postfix``[3:0], \
                   awid_``axi_postfix``[NEW_ID_WIDTH+ROUTE_WIDTH-1:ROUTE_WIDTH], \
                 awaddr_``axi_postfix``, \
                 awsize_``axi_postfix``, \
                awburst_``axi_postfix``, \
                awcache_``axi_postfix``, \
                 awprot_``axi_postfix``, \
                 awlock_``axi_postfix``[0], \
                awsnoop_conv, \
               awdomain_``axi_postfix``, \
                 awuser_``axi_postfix``, \
                   awid_``axi_postfix``[ROUTE_WIDTH-1:0]} = awp_``axi_payld_if``; \
      assign  {     wid_``axi_postfix``[NEW_ID_WIDTH+ROUTE_WIDTH-1:ROUTE_WIDTH], \
                  wstrb_``axi_postfix``, \
                  wdata_``axi_postfix``, \
                  wlast_``axi_postfix``, \
                    wid_``axi_postfix``[ROUTE_WIDTH-1:0]} = wp_``axi_payld_if``; \
      assign {rp_``axi_payld_if``} = {  rid_``axi_postfix``[NEW_ID_WIDTH+ROUTE_WIDTH-1:ROUTE_WIDTH], \
                                      rresp_``axi_postfix``, \
                                      rdata_``axi_postfix``, \
                                      rlast_``axi_postfix``, \
                                      ruser_``axi_postfix``, \
                                        rid_``axi_postfix``[ROUTE_WIDTH-1:0]}; \
      assign {bp_``axi_payld_if``} = {  bid_``axi_postfix``[NEW_ID_WIDTH+ROUTE_WIDTH-1:ROUTE_WIDTH], \
                                      bresp_``axi_postfix``, \
                                      buser_``axi_postfix``, \
                                        bid_``axi_postfix``[ROUTE_WIDTH-1:0]}; \
    end \
    else if(USER_WIDTH > 0) begin : BLK_with_user \
      assign  {   arqos_``axi_postfix``, \
                  arlen_``axi_postfix``[3:0], \
                   arid_``axi_postfix``, \
                 araddr_``axi_postfix``, \
                 arsize_``axi_postfix``, \
                arburst_``axi_postfix``, \
                arcache_``axi_postfix``, \
                 arprot_``axi_postfix``, \
                 arlock_``axi_postfix``[0], \
                arsnoop_conv, \
               ardomain_``axi_postfix``, \
                 aruser_``axi_postfix``} = arp_``axi_payld_if``; \
      assign  {   awqos_``axi_postfix``, \
                  awlen_``axi_postfix``[3:0], \
                   awid_``axi_postfix``, \
                 awaddr_``axi_postfix``, \
                 awsize_``axi_postfix``, \
                awburst_``axi_postfix``, \
                awcache_``axi_postfix``, \
                 awprot_``axi_postfix``, \
                 awlock_``axi_postfix``[0], \
                awsnoop_conv, \
               awdomain_``axi_postfix``, \
                 awuser_``axi_postfix``} = awp_``axi_payld_if``; \
      assign  {   wstrb_``axi_postfix``, \
                  wdata_``axi_postfix``, \
                  wlast_``axi_postfix``} = wp_``axi_payld_if``; \
      assign {rp_``axi_payld_if``} = {rid_``axi_postfix``, rresp_``axi_postfix``, rdata_``axi_postfix``, rlast_``axi_postfix``, ruser_``axi_postfix``}; \
      assign {bp_``axi_payld_if``} = {bid_``axi_postfix``, bresp_``axi_postfix``, buser_``axi_postfix``}; \
    end \
    else if(ROUTE_WIDTH > 0) begin : BLK_with_route \
      assign  {   arqos_``axi_postfix``, \
                  arlen_``axi_postfix``[3:0], \
                   arid_``axi_postfix``[NEW_ID_WIDTH+ROUTE_WIDTH-1:ROUTE_WIDTH], \
                 araddr_``axi_postfix``, \
                 arsize_``axi_postfix``, \
                arburst_``axi_postfix``, \
                arcache_``axi_postfix``, \
                 arprot_``axi_postfix``, \
                 arlock_``axi_postfix``[0], \
                arsnoop_conv, \
               ardomain_``axi_postfix``, \
                   arid_``axi_postfix``[ROUTE_WIDTH-1:0]} = arp_``axi_payld_if``; \
      assign  {   awqos_``axi_postfix``, \
                  awlen_``axi_postfix``[3:0], \
                   awid_``axi_postfix``[NEW_ID_WIDTH+ROUTE_WIDTH-1:ROUTE_WIDTH], \
                 awaddr_``axi_postfix``, \
                 awsize_``axi_postfix``, \
                awburst_``axi_postfix``, \
                awcache_``axi_postfix``, \
                 awprot_``axi_postfix``, \
                 awlock_``axi_postfix``[0], \
                awsnoop_conv, \
               awdomain_``axi_postfix``, \
                   awid_``axi_postfix``[ROUTE_WIDTH-1:0]} = awp_``axi_payld_if``; \
      assign  {     wid_``axi_postfix``[NEW_ID_WIDTH+ROUTE_WIDTH-1:ROUTE_WIDTH], \
                  wstrb_``axi_postfix``, \
                  wdata_``axi_postfix``, \
                  wlast_``axi_postfix``, \
                    wid_``axi_postfix``[ROUTE_WIDTH-1:0]} = wp_``axi_payld_if``; \
      assign {rp_``axi_payld_if``} = {  rid_``axi_postfix``[NEW_ID_WIDTH+ROUTE_WIDTH-1:ROUTE_WIDTH], \
                                      rresp_``axi_postfix``, \
                                      rdata_``axi_postfix``, \
                                      rlast_``axi_postfix``, \
                                        rid_``axi_postfix``[ROUTE_WIDTH-1:0]}; \
      assign {bp_``axi_payld_if``} = {  bid_``axi_postfix``[NEW_ID_WIDTH+ROUTE_WIDTH-1:ROUTE_WIDTH], \
                                      bresp_``axi_postfix``, \
                                        bid_``axi_postfix``[ROUTE_WIDTH-1:0]}; \
    end \
    else begin : BLK_without_user \
      assign  {   arqos_``axi_postfix``, \
                  arlen_``axi_postfix``[3:0], \
                   arid_``axi_postfix``, \
                 araddr_``axi_postfix``, \
                 arsize_``axi_postfix``, \
                arburst_``axi_postfix``, \
                arcache_``axi_postfix``, \
                 arprot_``axi_postfix``, \
                 arlock_``axi_postfix``[0], \
                arsnoop_conv, \
               ardomain_``axi_postfix``} = arp_``axi_payld_if``; \
      assign  {   awqos_``axi_postfix``, \
                  awlen_``axi_postfix``[3:0], \
                   awid_``axi_postfix``, \
                 awaddr_``axi_postfix``, \
                 awsize_``axi_postfix``, \
                awburst_``axi_postfix``, \
                awcache_``axi_postfix``, \
                 awprot_``axi_postfix``, \
                 awlock_``axi_postfix``[0], \
                awsnoop_conv, \
               awdomain_``axi_postfix``} = awp_``axi_payld_if``; \
      assign  {   wstrb_``axi_postfix``, \
                  wdata_``axi_postfix``, \
                  wlast_``axi_postfix``} = wp_``axi_payld_if``; \
      assign {rp_``axi_payld_if``} = {rid_``axi_postfix``, rresp_``axi_postfix``, rdata_``axi_postfix``, rlast_``axi_postfix``}; \
      assign {bp_``axi_payld_if``} = {bid_``axi_postfix``, bresp_``axi_postfix``}; \
    end \
  endgenerate \
  assign   arlen_``axi_postfix``[7:4] = 'h0; \
  assign   awlen_``axi_postfix``[7:4] = 'h0; \
  assign  arlock_``axi_postfix``[1] = 'b0; \
  assign  awlock_``axi_postfix``[1] = 'b0; \
  assign   arbar_``axi_postfix`` = 'b0; \
  assign   awbar_``axi_postfix`` = 'b0; \
  assign arsnoop_``axi_postfix`` = ARSNOOP_decomp(arsnoop_conv); \
  assign awsnoop_``axi_postfix`` = AWSNOOP_decomp(awsnoop_conv);



`define ace_lite_payld_to_axi(axi_postfix, axi_payld_if) \
  wire [1:0]  arsnoop_conv, awsnoop_conv; \
  assign arvalid_``axi_postfix`` = arv_``axi_payld_if``; assign arr_``axi_payld_if`` = arready_``axi_postfix``; \
  assign awvalid_``axi_postfix`` = awv_``axi_payld_if``; assign awr_``axi_payld_if`` = awready_``axi_postfix``; \
  assign  wvalid_``axi_postfix`` = wv_``axi_payld_if`` ; assign  wr_``axi_payld_if``  = wready_``axi_postfix``; \
  assign rv_``axi_payld_if``   = rvalid_``axi_postfix``; assign rready_``axi_postfix``   = rr_``axi_payld_if``; \
  assign bv_``axi_payld_if``   = bvalid_``axi_postfix``; assign bready_``axi_postfix``   = br_``axi_payld_if``; \
  generate \
    if(ROUTE_WIDTH > 0) begin \
      if(USER_WIDTH > 0) begin : BLK_with_user \
        assign  {   arqos_``axi_postfix``, \
                    arlen_``axi_postfix``[3:0], \
                     arid_``axi_postfix``[NEW_ID_WIDTH+ROUTE_WIDTH-1:ROUTE_WIDTH], \
                   araddr_``axi_postfix``, \
                   arsize_``axi_postfix``, \
                  arburst_``axi_postfix``, \
                  arcache_``axi_postfix``, \
                   arprot_``axi_postfix``, \
                   arlock_``axi_postfix``[0], \
                  arsnoop_conv, \
                 ardomain_``axi_postfix``, \
                   aruser_``axi_postfix``, \
                     arid_``axi_postfix``[ROUTE_WIDTH-1:0]} = arp_``axi_payld_if``; \
        assign  {   awqos_``axi_postfix``, \
                    awlen_``axi_postfix``[3:0], \
                     awid_``axi_postfix``[NEW_ID_WIDTH+ROUTE_WIDTH-1:ROUTE_WIDTH], \
                   awaddr_``axi_postfix``, \
                   awsize_``axi_postfix``, \
                  awburst_``axi_postfix``, \
                  awcache_``axi_postfix``, \
                   awprot_``axi_postfix``, \
                   awlock_``axi_postfix``[0], \
                  awsnoop_conv, \
                 awdomain_``axi_postfix``, \
                   awuser_``axi_postfix``, \
                     awid_``axi_postfix``[ROUTE_WIDTH-1:0]} = awp_``axi_payld_if``; \
        assign  {     wid_``axi_postfix``[NEW_ID_WIDTH+ROUTE_WIDTH-1:ROUTE_WIDTH], \
                    wstrb_``axi_postfix``, \
                    wdata_``axi_postfix``, \
                    wlast_``axi_postfix``, \
                      wid_``axi_postfix``[ROUTE_WIDTH-1:0]} = wp_``axi_payld_if``; \
        assign {rp_``axi_payld_if``} = {rid_``axi_postfix``[NEW_ID_WIDTH+ROUTE_WIDTH-1:ROUTE_WIDTH], \
                                      rresp_``axi_postfix``, \
                                      rdata_``axi_postfix``, \
                                      rlast_``axi_postfix``, \
                                      ruser_``axi_postfix``, \
                                        rid_``axi_postfix``[ROUTE_WIDTH-1:0]}; \
        assign {bp_``axi_payld_if``} = {bid_``axi_postfix``[NEW_ID_WIDTH+ROUTE_WIDTH-1:ROUTE_WIDTH], \
                                      bresp_``axi_postfix``, \
                                      buser_``axi_postfix``, \
                                        bid_``axi_postfix``[ROUTE_WIDTH-1:0]}; \
      end else begin : BLK_without_user \
        assign  {   arqos_``axi_postfix``, \
                    arlen_``axi_postfix``[3:0], \
                     arid_``axi_postfix``[NEW_ID_WIDTH+ROUTE_WIDTH-1:ROUTE_WIDTH], \
                   araddr_``axi_postfix``, \
                   arsize_``axi_postfix``, \
                  arburst_``axi_postfix``, \
                  arcache_``axi_postfix``, \
                   arprot_``axi_postfix``, \
                   arlock_``axi_postfix``[0], \
                  arsnoop_conv, \
                 ardomain_``axi_postfix``, \
                     arid_``axi_postfix``[ROUTE_WIDTH-1:0]} = arp_``axi_payld_if``; \
        assign  {   awqos_``axi_postfix``, \
                    awlen_``axi_postfix``[3:0], \
                     awid_``axi_postfix``[NEW_ID_WIDTH+ROUTE_WIDTH-1:ROUTE_WIDTH], \
                   awaddr_``axi_postfix``, \
                   awsize_``axi_postfix``, \
                  awburst_``axi_postfix``, \
                  awcache_``axi_postfix``, \
                   awprot_``axi_postfix``, \
                   awlock_``axi_postfix``[0], \
                  awsnoop_conv, \
                 awdomain_``axi_postfix``, \
                     awid_``axi_postfix``[ROUTE_WIDTH-1:0]} = awp_``axi_payld_if``; \
        assign  {     wid_``axi_postfix``, \
                    wstrb_``axi_postfix``, \
                    wdata_``axi_postfix``, \
                    wlast_``axi_postfix``} = wp_``axi_payld_if``; \
        assign {rp_``axi_payld_if``} = {rid_``axi_postfix``[NEW_ID_WIDTH+ROUTE_WIDTH-1:ROUTE_WIDTH], \
                                      rresp_``axi_postfix``, \
                                      rdata_``axi_postfix``, \
                                      rlast_``axi_postfix``, \
                                        rid_``axi_postfix``[ROUTE_WIDTH-1:0]}; \
        assign {bp_``axi_payld_if``} = {bid_``axi_postfix``[NEW_ID_WIDTH+ROUTE_WIDTH-1:ROUTE_WIDTH], \
                                      bresp_``axi_postfix``, \
                                        bid_``axi_postfix``[ROUTE_WIDTH-1:0]}; \
      end \
    end \
    else begin \
      if(USER_WIDTH > 0) begin : BLK_with_user \
        assign  {   arqos_``axi_postfix``, \
                    arlen_``axi_postfix``[3:0], \
                     arid_``axi_postfix``, \
                   araddr_``axi_postfix``, \
                   arsize_``axi_postfix``, \
                  arburst_``axi_postfix``, \
                  arcache_``axi_postfix``, \
                   arprot_``axi_postfix``, \
                   arlock_``axi_postfix``[0], \
                  arsnoop_conv, \
                 ardomain_``axi_postfix``, \
                   aruser_``axi_postfix``} = arp_``axi_payld_if``; \
        assign  {   awqos_``axi_postfix``, \
                    awlen_``axi_postfix``[3:0], \
                     awid_``axi_postfix``, \
                   awaddr_``axi_postfix``, \
                   awsize_``axi_postfix``, \
                  awburst_``axi_postfix``, \
                  awcache_``axi_postfix``, \
                   awprot_``axi_postfix``, \
                   awlock_``axi_postfix``[0], \
                  awsnoop_conv, \
                 awdomain_``axi_postfix``, \
                   awuser_``axi_postfix``} = awp_``axi_payld_if``; \
        assign  {     wid_``axi_postfix``, \
                    wstrb_``axi_postfix``, \
                    wdata_``axi_postfix``, \
                    wlast_``axi_postfix``} = wp_``axi_payld_if``; \
        assign {rp_``axi_payld_if``} = {rid_``axi_postfix``, rresp_``axi_postfix``, rdata_``axi_postfix``, rlast_``axi_postfix``, ruser_``axi_postfix``}; \
        assign {bp_``axi_payld_if``} = {bid_``axi_postfix``, bresp_``axi_postfix``, buser_``axi_postfix``}; \
      end else begin : BLK_without_user \
        assign  {   arqos_``axi_postfix``, \
                    arlen_``axi_postfix``[3:0], \
                     arid_``axi_postfix``, \
                   araddr_``axi_postfix``, \
                   arsize_``axi_postfix``, \
                  arburst_``axi_postfix``, \
                  arcache_``axi_postfix``, \
                   arprot_``axi_postfix``, \
                   arlock_``axi_postfix``[0], \
                  arsnoop_conv, \
                 ardomain_``axi_postfix``} = arp_``axi_payld_if``; \
        assign  {   awqos_``axi_postfix``, \
                    awlen_``axi_postfix``[3:0], \
                     awid_``axi_postfix``, \
                   awaddr_``axi_postfix``, \
                   awsize_``axi_postfix``, \
                  awburst_``axi_postfix``, \
                  awcache_``axi_postfix``, \
                   awprot_``axi_postfix``, \
                   awlock_``axi_postfix``[0], \
                  awsnoop_conv, \
                 awdomain_``axi_postfix``} = awp_``axi_payld_if``; \
        assign  {     wid_``axi_postfix``, \
                    wstrb_``axi_postfix``, \
                    wdata_``axi_postfix``, \
                    wlast_``axi_postfix``} = wp_``axi_payld_if``; \
        assign {rp_``axi_payld_if``} = {rid_``axi_postfix``, rresp_``axi_postfix``, rdata_``axi_postfix``, rlast_``axi_postfix``}; \
        assign {bp_``axi_payld_if``} = {bid_``axi_postfix``, bresp_``axi_postfix``}; \
      end \
    end \
  endgenerate \
  assign   arlen_``axi_postfix``[7:4] = 'h0; \
  assign   awlen_``axi_postfix``[7:4] = 'h0; \
  assign  arlock_``axi_postfix``[1] = 'b0; \
  assign  awlock_``axi_postfix``[1] = 'b0; \
  assign   arbar_``axi_postfix`` = 'b0; \
  assign   awbar_``axi_postfix`` = 'b0; \
  assign arsnoop_``axi_postfix`` = ARSNOOP_decomp(arsnoop_conv); \
  assign awsnoop_``axi_postfix`` = AWSNOOP_decomp(awsnoop_conv);



`define assign_axi_vip_trace_master(dut, vip, trace) \
  assign  ``dut``.arvalid       = enable_trace_master ? ``trace``.arvalid : ``vip``.arvalid; \
  assign  ``vip``.arready   = ``dut``.arready; \
  assign  ``trace``.arready = ``dut``.arready; \
  assign  ``dut``.arid          = enable_trace_master ? ``trace``.arid : ``vip``.arid; \
  assign  ``dut``.araddr        = enable_trace_master ? ``trace``.araddr : ``vip``.araddr; \
  assign  ``dut``.arlen         = enable_trace_master ? ``trace``.arlen : ``vip``.arlen; \
  assign  ``dut``.arsize        = enable_trace_master ? ``trace``.arsize : ``vip``.arsize; \
  assign  ``dut``.arburst       = enable_trace_master ? ``trace``.arburst : ``vip``.arburst; \
  assign  ``dut``.arlock        = enable_trace_master ? ``trace``.arlock : ``vip``.arlock; \
  assign  ``dut``.arcache       = enable_trace_master ? ``trace``.arcache : ``vip``.arcache; \
  assign  ``dut``.arprot        = enable_trace_master ? ``trace``.arprot : ``vip``.arprot; \
  assign  ``dut``.arqos         = enable_trace_master ? ``trace``.arqos : ``vip``.arqos; \
  assign  ``dut``.aruser        = enable_trace_master ? ``trace``.aruser : ``vip``.aruser; \
  assign  ``vip``.rvalid    = ``dut``.rvalid; \
  assign  ``trace``.rvalid  = ``dut``.rvalid; \
  assign  ``dut``.rready        = enable_trace_master ? ``trace``.rready : ``vip``.rready; \
  assign  ``vip``.rid       = ``dut``.rid; \
  assign  ``trace``.rid     = ``dut``.rid; \
  assign  ``vip``.rdata     = ``dut``.rdata; \
  assign  ``trace``.rdata   = ``dut``.rdata; \
  assign  ``vip``.rresp     = ``dut``.rresp; \
  assign  ``trace``.rresp   = ``dut``.rresp; \
  assign  ``vip``.rlast     = ``dut``.rlast; \
  assign  ``trace``.rlast   = ``dut``.rlast; \
  assign  ``vip``.ruser     = ``dut``.ruser; \
  assign  ``trace``.ruser   = ``dut``.ruser; \
  assign  ``dut``.awvalid       = enable_trace_master ? ``trace``.awvalid : ``vip``.awvalid; \
  assign  ``vip``.awready   = ``dut``.awready; \
  assign  ``trace``.awready = ``dut``.awready; \
  assign  ``dut``.awid          = enable_trace_master ? ``trace``.awid : ``vip``.awid; \
  assign  ``dut``.awaddr        = enable_trace_master ? ``trace``.awaddr : ``vip``.awaddr; \
  assign  ``dut``.awlen         = enable_trace_master ? ``trace``.awlen : ``vip``.awlen; \
  assign  ``dut``.awsize        = enable_trace_master ? ``trace``.awsize : ``vip``.awsize; \
  assign  ``dut``.awburst       = enable_trace_master ? ``trace``.awburst : ``vip``.awburst; \
  assign  ``dut``.awlock        = enable_trace_master ? ``trace``.awlock : ``vip``.awlock; \
  assign  ``dut``.awcache       = enable_trace_master ? ``trace``.awcache : ``vip``.awcache; \
  assign  ``dut``.awprot        = enable_trace_master ? ``trace``.awprot : ``vip``.awprot; \
  assign  ``dut``.awqos         = enable_trace_master ? ``trace``.awqos : ``vip``.awqos; \
  assign  ``dut``.awuser        = enable_trace_master ? ``trace``.awuser : ``vip``.awuser; \
  assign  ``dut``.wvalid        = enable_trace_master ? ``trace``.wvalid : ``vip``.wvalid; \
  assign  ``vip``.wready    = ``dut``.wready; \
  assign  ``trace``.wready  = ``dut``.wready; \
  assign  ``dut``.wdata         = enable_trace_master ? ``trace``.wdata : ``vip``.wdata; \
  assign  ``dut``.wstrb         = enable_trace_master ? ``trace``.wstrb : ``vip``.wstrb; \
  assign  ``dut``.wlast         = enable_trace_master ? ``trace``.wlast : ``vip``.wlast; \
  assign  ``dut``.wid           = enable_trace_master ? ``trace``.wid   : ``vip``.wid  ; \
  assign  ``vip``.bvalid    = ``dut``.bvalid; \
  assign  ``trace``.bvalid  = ``dut``.bvalid; \
  assign  ``dut``.bready        = enable_trace_master ? ``trace``.bready : ``vip``.bready; \
  assign  ``vip``.bid       = ``dut``.bid; \
  assign  ``trace``.bid     = ``dut``.bid; \
  assign  ``vip``.bresp     = ``dut``.bresp; \
  assign  ``trace``.bresp   = ``dut``.bresp; \
  assign  ``vip``.buser     = ``dut``.buser; \
  assign  ``trace``.buser   = ``dut``.buser;



// vim: tabstop=2 softtabstop=2 shiftwidth=2 expandtab autoindent smartindent
