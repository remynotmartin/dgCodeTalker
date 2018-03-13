#!/bin/sh

g++ -std=c++11 -Wall ../src/*.cpp -I ../../libs/include -L../../lib -lnamegen -o ../../bin/codeTalker.out
