# File Organizer Script

## Description

This Bash script organizes files from a source directory into subdirectories based on their file types. It categorizes files into three types: images, documents, and others.

## Usage

```bash
./organize_files.sh <source_directory>
```

- `<source_directory>`: The directory containing the files you want to organize.

## How It Works

1. **Check for Source Directory**:
   - The script checks if the source directory is provided as an argument.
   - `$1`: Represents the first positional parameter in the script. For example, when running `./script.sh arg1 arg2`, `$1` will be `arg1`, and `$2` will be `arg2`.
   - `-z`: A test operator in Bash that checks if the length of a string is zero (i.e., if it is empty).
   - `"${1}"`: Ensures the value of `$1` is treated as a single string, preventing errors with filenames or paths that contain spaces or are empty.

   ```bash
   if [ -z "$1" ]; then
     echo "Usage: $0 <source_directory>"
     exit 1
   fi
   ```

2. **Assign Source Directory**:
   - Assigns the source directory to the `src_dir` variable.

   ```bash
   src_dir="$1"
   ```

3. **Create Subdirectories**:
   - Creates subdirectories within the source directory for organizing files.

   ```bash
   mkdir -p "$src_dir/images" "$src_dir/documents" "$src_dir/others"
   ```

4. **Move Files**:
   - The `move_file` function determines the file extension and moves the file to the appropriate subdirectory.

   ```bash
   move_file() {
     local file="$1"
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
   ```

5. **Iterate Over Files**:
   - The script iterates over all files in the source directory and moves them to the appropriate subdirectory.

   ```bash
   for file in "$src_dir"/*; do
     if [ -f "$file" ]; then
       move_file "$file"
     fi
   done
   ```

6. **Completion Message**:
   - Prints a message indicating that the files have been organized.

   ```bash
   echo "Files have been organized."
   ```

## Notes

- The script skips directories.
- If a file doesn't have an extension, it is moved to the `others` directory.

## Example

To organize files in `/home/user/downloads`, run:

```bash
./organize_files.sh /home/user/downloads
```
