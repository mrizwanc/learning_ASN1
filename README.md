## learning_ASN1

This project demonstrates the use of ASN.1 files to define data structures and generate C code using `asn1c`.

I started learning ASN1 with these

## Directory Structure
- `asn/`: Contains ASN.1 definitions.
- `src/`: Source files for the application.
- `include/`: Header files and all the generated code from asn1c.

## Usage
1. Modify `first.asn` to define your data structures.
2. Generate C code using `asn1c`:
   ```bash
   asn1c -fcompound-names -gen-PER asn/first.asn

# Description of build.sh
Processes happen in the scripting file-
- Compile the .asn file
- Remove sample.c and makefile.sample generated from asn1c compilation
- Move all the generated files to the include directory
- Compile all the generated files from .asn compilation
- Compile main.c
- Link all the object files and build the output file
- Clean all the object files
- Run the output file
- Clean the output file and all the asn1c generated files


**Infuture will replace the shell script with a makefile
