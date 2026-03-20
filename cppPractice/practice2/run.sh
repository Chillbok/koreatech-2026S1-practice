#!/bin/bash

SOURCE_FILE=$1

if [ -z "$SOURCE_FILE"]; then
    echo "사용법: ./run.sh 파일이름.cpp 또는 ./run.sh 파일이름.c"
    exit 1
SOURCE_FILE
g++ "$SOURCE_FILE" -o program.out && ./program.out