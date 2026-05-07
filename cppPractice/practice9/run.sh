#!/bin/bash

SOURCE_FILE=$1

if [ -z "$SOURCE_FILE" ]; then
    echo "사용법: ./run.sh 파일이름.cpp 또는 ./run.sh 파일이름.c"
    exit 1
fi

if [[ "$SOURCE_FILE" == *.c ]]; then
    COMPILER="gcc"
    echo "C 파일로 인식해 $COMPILER 를 사용함."
elif [[ "$SOURCE_FILE" == *.cpp ]]; then
    COMPILER="g++"
    echo "C++ 파일로 인식해 $COMPILER 를 사용함."
else "지원하지 않는 파일 형식"
    exit 1
fi

$COMPILER "$SOURCE_FILE" -o program.out && ./program.out