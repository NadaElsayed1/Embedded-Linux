#!/bin/bash

#variables
DIR1="myDirectory"
DIR2="secondDirectory"
FILE="myNotePaper"
NEWFILE="myOldNotePaper"

#create directories
mkdir -p $DIR1
mkdir -p $DIR1/$DIR2

#create a file in the second directory
touch $DIR1/$DIR2/$FILE

echo "My Name is: Nada"> $DIR1/$DIR2/$FILE

#copy this file to the 1st directory
cp $DIR1/$DIR2/$FILE $DIR1/

# Rename the copied file
mv $DIR1/$FILE $DIR1/$NEWFILE

#------------------------------------------------
echo "Directory $DIR1 AND $DIR2 created"
echo "File $FILE created in $DIR2 and copied to $DIR1"
