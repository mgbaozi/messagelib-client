#!/bin/bash
g++ *.cc packet/*.cc --std=c++11 -o main -lprotobuf -levent -lpthread
