#!/bin/bash

# Variables
ASN_DIR="include"
SRC_DIR="src"
OUTPUT="final"


# Run asn1c
asn1c -fcompound-names -gen-PER asn/first.asn

# Remove Sample Files
rm *sample*

# Move the generated files to the output directory
mv *.c *.h include/

# Compile generated ASN.1 files
gcc -I"$ASN_DIR" -c "$ASN_DIR"/*.c

# Compile main.c
gcc -I"$ASN_DIR" -c "$SRC_DIR"/main.c

# Link all object files
gcc -o $OUTPUT *.o

# Clean up object files
rm *.o

# Run the program
echo -e "\n\n\n\t\t\tRunning the program:\n"

./$OUTPUT

echo -e "\n\n\t\t\tEnd Of The Program.\n\n\n"


# Clean up output and ASN files
rm $OUTPUT
rm -rf include/*









