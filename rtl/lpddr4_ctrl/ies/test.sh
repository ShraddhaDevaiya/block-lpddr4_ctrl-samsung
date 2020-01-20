#!/bin/bash

source /tools/license/incisive.bashrc
source /tools/cadence/incisive-14.10.014/env.sh

export OMC_DESIGN_ROOT=.

ncverilog -sv -top omc -f design.f \
          -USELICENSE IESL -l test.log \
          -timescale 1ns/1ps
