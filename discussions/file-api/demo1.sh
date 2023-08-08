#! /bin/bash

echo "hello" > oldfile
ln -s oldfile link1
ln oldfile link2
rm oldfile

