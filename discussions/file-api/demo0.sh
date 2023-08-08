#! /bin/bash

# Multiple Names for a File
#

echo "Beginning..." > file1
ln file1 link
cat link
ls -li
echo "More Info" >> file1
mv file1 file2
rm file2

