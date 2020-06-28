#!/bin/bash
DIRSCRIPT=$(pwd)
cd build/ 
rm main
cmake $DIRSCRIPT
make
./main
cd $DIRSCRIPT
