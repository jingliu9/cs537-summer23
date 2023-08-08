#! /bin/bash

#TRACE_CALLS="%file,/pread*,/read*,/pwrite*,/write*,/f*sync,fsync,close,sync,/l*seek,dup,splice,sendfile,fcntl,ioctl,fstat,getdents64,msync,mmap"
TRACE_CALLS="%file,%desc,%%stat,%process"
#TRACE_CALLS="%file,%desc,%%stat"
# timestamp in microsecond

# This combination will give us a summary view of what system calls are invoked.
#TRACE_CALLS="all"
#TRACE_FLAGS="-c"

function get_strace_flags() {
    if [[ $# -lt 1 ]]
    then
        echo "get_strace_flags <default|comb>"
        exit 1
    fi
    case "$1" in
        (default)
            # timestamp in microsecond since epoch, -ff will gen a file for each thread
            echo "-ttt -ff -T"
            ;;
        (comb)
            echo "-ttt -f -T"
            ;;
        (*)
            echo "-tt -ff -T"
            ;;
    esac
}

function run_with_strace() {
    if [[ $# -lt 2 ]]
    then
        echo "run_with_strace <output_name> <cmd>"
        exit 1
    fi

    OUT_NAME=$1
    APP_CMD="${@:2}"

    # timestamp in microsecond since epoch, -ff will gen a file for each thread
    TRACE_FLAGS=$(get_strace_flags default)

    echo "run_with_strace($APP_CMD)"

    strace $TRACE_FLAGS -e trace="$TRACE_CALLS" -o "${OUT_NAME}" -- $APP_CMD
}


function run_with_strace_comb() {
    if [[ $# -lt 2 ]]
    then
        echo "run_with_strace_comb <output_name> <cmd>"
        exit 1
    fi

    OUT_NAME=$1
    APP_CMD="${@:2}"

    TRACE_FLAGS=$(get_strace_flags comb)

    echo "run_with_strace_comb($APP_CMD) flags:$TRACE_FLAGS"

    strace $TRACE_FLAGS -e trace="$TRACE_CALLS" -o "${OUT_NAME}" -- $APP_CMD
}

