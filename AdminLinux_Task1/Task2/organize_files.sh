#!/bin/bash

# $1: Represents the first positional parameter in a Bash script, so when running ./script.sh arg1 arg2, $1 will be arg1, and $2 will be arg2.
# -z: A test operator in Bash that checks if the length of a string is zero (is empty).
# "$1": Double quotes around $1 ensure it's treated as a single string, preventing errors with filenames or paths that contain spaces or are empty.
if [ -z "$1" ]; then
# echo "Usage: $0 <source_directory>": Prints a usage message to inform the user how to run the script. $0 represents the name of the script.
# exit 1: Exits the script with a status code of 1, indicating an error or abnormal termination.
  echo "Usage: $0 <source_directory>"
  exit 1
fi

# Assign the source directory to a variable
src_dir="$1"

# Create subdirectories for organizing files
mkdir -p "$src_dir/images" "$src_dir/documents" "$src_dir/others"

# Function to move files to the appropriate subdirectory
move_file() {
  local file="$1"

  # ##*: This is a parameter expansion operator in Bash.
  # ${file##*.} strips off everything up to and including the last ., resulting in txt

  local ext="${file##*.}"

  case "$ext" in
    jpg|png|gif)
      mv "$file" "$src_dir/images/"
      ;;
    txt|doc|pdf)
      mv "$file" "$src_dir/documents/"
      ;;
    *)
      mv "$file" "$src_dir/others/"
      ;;
  esac
}
# If a file doesn't have an extension, it is moved to the others directory.
# then the remaining files go to the function to redirect then to the appropriate directory 
# Iterate over files in the source directory
for file in "$src_dir"/*; do
  if [ -f "$file" ]; then
    move_file "$file"
  fi
done

echo "Files have been organized."
