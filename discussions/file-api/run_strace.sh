#! /bin/bash

set -e

source strace_commons.sh

#run_with_strace cp_strace.txt cp link2 link2cp
#run_with_strace_comb cp_strace.txt cp link2 link2cp
#run_with_strace_comb mv_strace.txt mv link2cp link2mv
run_with_strace_comb del_strace.txt rm -f link2mv

