#!/usr/bin/env bash

./bootstrap
mkdir -p gh_out out
cd gh_out
cmake ..
make ct_common_docs
cp -r bin/programming_guide.html bin/style ../out/
