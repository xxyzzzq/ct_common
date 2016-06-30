#!/usr/bin/env bash

cur_dir=`dirname $0`
files=`find $cur_dir/../src -name *.h -or -name *.cpp`

python third_party/cpplint/cpplint.py $files
