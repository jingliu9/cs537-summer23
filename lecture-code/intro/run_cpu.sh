#! /bin/bash

# Ask for the input
echo "How many ./cpu are we going to run?: "
read -rs N

# Start N proceesses of *cpu*
for (( X=1; X<=N; X++ ))
do
    ./cpu "Hello cpu No. $X" &
done
