#!/usr/bin/env python

import os
import subprocess
import sys
import argparse

SKELETON=("<!DOCTYPE html>\n"
          "<html>\n"
          "<title>{title}</title>\n"
          "<textarea theme=\"united\" style=\"display:none;\">\n"
          "{body}\n"
          "</textarea>\n"
          "<script src=\"style/strapdown.js\"></script>\n"
          "</html>\n")

def wrap_content(title, body):
    return SKELETON.format(title=title, body=body)

parser = argparse.ArgumentParser()
parser.add_argument('--out-dir', nargs=1, dest='OUTPUT_DIR', required=True,
                    help='The output directory name')
parser.add_argument('FILE_NAME', nargs=1,
                    help='Other argument passed to markdown2')
parsed_args = parser.parse_args()

input_name = parsed_args.FILE_NAME[0]
input_name_no_ext = os.path.splitext(os.path.basename(input_name))[0]
output_name = os.path.join(
    parsed_args.OUTPUT_DIR[0], input_name_no_ext + ".html")
with open(input_name, 'r') as infile:
    title = infile.readline()
    title = title.strip('#').strip()
with open(input_name, 'r') as infile, open(output_name, 'w') as outfile:
    body = infile.read()
    outfile.write(wrap_content(title, body))
    success = True

if not success:
    print "cannot read/write file"
