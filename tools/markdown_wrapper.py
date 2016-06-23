#!/usr/bin/env python

import os
import subprocess
import sys
import argparse

script_path = os.path.dirname(os.path.abspath(__file__))

markdown_path = os.path.normpath(os.path.join(script_path, "../third_party/markdown2"))
markdown_bin_path = os.path.join(markdown_path, 'bin/markdown2')

parser = argparse.ArgumentParser(add_help=False)
parser.add_argument('-h', '--help', action='store_true',
                    help='show this help message and exit.')
parser.add_argument('-o', nargs=1, dest='OUTPUT_FILE',
                    help='The output file name,'
                    'the stdout of markdown2 will be redirected to this file.')
parser.add_argument('OTHER_ARG', nargs='*',
                    help='Other argument passed to markdown2')
parsed_args = parser.parse_args()

if parsed_args.help:
    parser.print_help()
    print "\n* Usage for markdown2 *"
    subprocess.call(['python', markdown_bin_path, '-h'])
    exit()

try:
    f = open(parsed_args.OUTPUT_FILE[0], 'w')
    subprocess.call(['python', markdown_bin_path] + parsed_args.OTHER_ARG, stdout=f)
except Exception as error:
    print error
