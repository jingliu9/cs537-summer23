#! /bin/bash

MK_NAME=Makefile.matrix_mult

function cleanup() {
    make -f $MK_NAME clean > /dev/null 2>&1
}

cleanup
make -f $MK_NAME

echo ">>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>"
echo "Let's see how fast it is?!"
echo ">>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>"

function exec_triple() {
    for R in 1 2 3
    do
        TIME_SEC=$($1)
        echo "  run-$R: $TIME_SEC sec"
    done
}

for SUFFIX in "O0" "O3" "O3opt0" "O3opt1" "O3opt2"
do
    echo " matrix_multi_$SUFFIX"
    exec_triple "./matrix_mult_$SUFFIX"
done

echo " This is amazingly fast python version"
exec_triple "python3 matrix_mult_openblas.py"

cleanup
