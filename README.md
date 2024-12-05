## learning_ASN1


This project demonstrates the use of ASN.1 files to define data structures and generate C code using `asn1c`.

I started learning ASN1 with these

## Directory Structure
- `asn/`: Contains ASN.1 definitions.
- `src/`: Source files for the application.
- `include/`: Header files and all the generated code from asn1c.

## Usage
1. Modify `example.asn` to define your data structures.
2. Generate C code using `asn1c`:
   ```bash
   asn1c -fcompound-names -gen-PER -print asn/example.asn
