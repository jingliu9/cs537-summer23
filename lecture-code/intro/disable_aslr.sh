#! /bin/bash

# Disable address space layout randomization (ASLR).
# Note, must be run in root.

echo 0 | sudo tee /proc/sys/kernel/randomize_va_space
