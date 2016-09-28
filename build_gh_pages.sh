#!/usr/bin/env bash

./bootstrap
mkdir -p gh_out out
cd gh_out
cmake ..
make ct_common_docs
cp -r bin/modeling_language.html bin/programming_guide.html bin/explicit_cast.png bin/style ../out/
cd ..
