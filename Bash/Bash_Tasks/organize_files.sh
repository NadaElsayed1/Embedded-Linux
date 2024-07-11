#!/bin/bash

# Check if the source directory that containing the files i want to organize.
# $1: Represents the first positional parameter in a Bash script. so when running `./script.sh arg1 arg2`, `$1` will be `arg1`, and `$2` will be `arg2`.

# -z: A test operator in Bash that checks if the length of a string is zero (is empty).

# "$1": ensure it's treated as a single string, preventing errors with filenames or paths that contain spaces or are empty.
if [ -z "$1" ]; then
  echo "Usage: $0 <source_directory>"
  exit 1
fi

#so this is a conditional statement in Bash checks if the value of $1 is an empty string. 
#If $1 is empty, the condition evaluates to true, and the script will execute the commands inside the then block.

# Assign the source directory to a variable
src_dir="$1"

# Create subdirectories for organizing files
mkdir -p "$src_dir/images" "$src_dir/documents" "$src_dir/others"

# Function to move files to the appropriate subdirectory
move_file() {
  local file="$1"
  
  ###*: This is a parameter expansion operator in Bash.
  #${file##*.}: This removes everything up to and including the last period . 
  #in the file variable, leaving only the extension.
  #So ext now hold olnly extensions of files like (txt)
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
#The script iterates over all files in the source directory.
# It skips directories.
# If a file doesn't have an extension, it moves it to the others directory.
# Otherwise, it calls the move_file function to move the file to the correct subdirectory.
for file in "$src_dir"/*; do
  if [ -f "$file" ]; then
    move_file "$file"
  fi
done

echo "Files have been organized."
