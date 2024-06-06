#################################################
#File Name:autobuild.sh
#Autor:rao
#################################################
#!/bin/bash
set -x

rm -rf "$(pwd)"/build/*
cd "$(pwd)"/build &&
    cmake .. &&
    make
