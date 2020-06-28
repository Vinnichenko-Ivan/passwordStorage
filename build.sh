#!/bin/bash
DIRSCRIPT=$(pwd)
cd .gitignore/build/ 
rm main
cmake $DIRSCRIPT
make
./main
cd $DIRSCRIPT
