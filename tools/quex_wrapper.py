#!/usr/bin/env python

import os
import subprocess
import sys

script_path = os.path.dirname(os.path.abspath(__file__))

quex_path = os.path.normpath(os.path.join(script_path, "../third_party/quex"))
quex_bin_path = os.path.join(quex_path, 'quex-exe.py')
os.environ['QUEX_PATH'] = quex_path
subprocess.call(['python', quex_bin_path] + sys.argv[1:])
