#include <stdio.h>
#include "../include/MyInteger.h"
#include "../include/MyString.h"
#include "../include/Person.h"

int main() {
    // Example using MyInteger
    MyInteger_t myInt = 42; // Assign a value within the range (0..100)
    printf("MyInteger value: %ld\n", myInt);

    // Example using MyString
    MyString_t myString; // UTF8String type
    char sampleText[] = "Hello, ASN.1!";
    myString.buf = (uint8_t *)sampleText; // Point to the string data
    myString.size = sizeof(sampleText) - 1; // Set size of the string
    printf("MyString value: %s\n", myString.buf);

    // Example using Person
    Person_t person; // Create a Person object
    person.id = 1;   // Assign ID
    char personName[] = "John Doe";
    person.name.buf = (uint8_t *)personName; // Assign name
    person.name.size = sizeof(personName) - 1; // Set size of name
    person.age = 30; // Assign age

    // Print Person values
    printf("Person ID: %ld\n", person.id);
    printf("Person Name: %s\n", person.name.buf);
    printf("Person Age: %ld\n", person.age);

    // Example: Encoding the Person structure
    uint8_t buffer[1024]; // Encoding buffer
    asn_enc_rval_t encResult = der_encode_to_buffer(
        &asn_DEF_Person, &person, buffer, sizeof(buffer));

    if (encResult.encoded > 0) {
        printf("Encoded Person successfully, size: %ld bytes\n", encResult.encoded);
    } else {
        printf("Failed to encode Person\n");
    }

    // Example: Decoding the Person structure
    Person_t *decodedPerson = NULL; // Pointer for decoded object
    asn_dec_rval_t decResult = ber_decode(NULL, &asn_DEF_Person, (void **)&decodedPerson, buffer, encResult.encoded);

    if (decResult.code == RC_OK) {
        printf("Decoded Person successfully:\n");
        printf("  ID: %ld\n", decodedPerson->id);
        printf("  Name: %s\n", decodedPerson->name.buf);
        printf("  Age: %ld\n", decodedPerson->age);
    } else {
        printf("Failed to decode Person\n");
    }

    // Free allocated memory
    ASN_STRUCT_FREE(asn_DEF_Person, decodedPerson);

    return 0;
}
