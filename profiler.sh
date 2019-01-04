#! /bin/bash
path=$1
./$1 &
pid=$!

# If this script is killed, kill the `cp'.
trap "kill $pid 2> /dev/null" EXIT

counter=1
mkdir profiler

# While copy is running...
while kill -0 $pid 2> /dev/null; do
    echo q | htop --sort-key=PERCENT_MEM | aha --black --line-fix > profiler/htop-$counter.html
    ((++counter))
    sleep 1
done

# Disable the trap on a normal exit.
trap - EXIT