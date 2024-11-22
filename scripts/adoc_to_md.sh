#!/bin/bash

OUTPUT="output.xml"

asciidoc -b docbook -o $OUTPUT $1
pandoc -f docbook -t markdown_strict $OUTPUT -o $2
rm $OUTPUT