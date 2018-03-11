#!/bin/sh

g++ -Wall -std=c++11 ../app/obj/*.o -I ../libs/namegen/include -L ../lib -l namegen -o ./codeTalker.out
