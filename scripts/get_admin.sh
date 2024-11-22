#!/bin/bash

# Check if the number of arguments is 2
if [ "$#" -ne 2 ]; then
  echo "Usage: $0 target_directory output_file"
  exit 1
fi

# get the target directory from the first command line argument
dir_path="$1"

# get the output file path from the second command line argument
output_file="$2"

echo "| attribute | value |" >> "$output_file"
echo "| --- | --- |" >> $output_file
# loop through all text files in the directory
for file_path in "$dir_path"/*; do

  # get the file name without the directory path or file extension
  file_name="$(basename "$file_path" .txt)"

  # check if the file name starts with an underscore
  if [[ "$file_name" =~ ^_ ]]; then
    # remove the underscore from the file name
    file_name="${file_name#_}"
  fi

  # check if the file name is '_content.adoc'
  if [ "$(basename "$file_path")" = '_content.adoc' ]; then
    continue  # skip this file and go to the next one
  fi

  # read the file contents into a variable
  file_contents="$(cat "$file_path")"

  # append the file name and contents to the specified output file in the desired format
  echo "${file_name} | ${file_contents} |" >> "$output_file"

done
