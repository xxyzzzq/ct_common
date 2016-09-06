#!/usr/bin/env bash

cur_dir=`dirname $0`
files=`find $cur_dir/../src -name *.h -and -not -name optional.h -or -name *.cpp`

python $cur_dir/../third_party/cpplint/cpplint.py $files 2>&1 | grep -v "Done processing"
