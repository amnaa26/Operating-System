#!/bin/bash

# Check if a filename is provided
if [ $# -eq 0 ]; then
    echo "Usage: $0 <filename>"
    exit 1
fi

# Store the filename
filename=$1

# Check if the file exists
if [ ! -f "$filename" ]; then
    echo "File not found!"
    exit 1
fi

# Count the number of lines and display the result
line_count=$(wc -l < "$filename")
echo "The file '$filename' has $line_count lines."

