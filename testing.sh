#!/bin/bash

echo Graph tester

make
echo Test 1
./graph-test.exe test1.csv
echo Finished
echo Test 2
./graph-test.exe test2.csv
echo Finished
echo Test 3
./graph-test.exe test3.csv
echo Finished
echo Test 4
./graph-test.exe test4.csv
echo Finished
make clean
