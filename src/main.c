#include <stdio.h>
#include "../include/MyInteger.h"
#include "../include/MyString.h"
#include "../include/Person.h"

// Function to print encoded output
void print_encoded(const uint8_t *data, size_t size) {
    size_t i;
    printf("Encoded Value: ");
    for (i = 0; i < size; i++) {
        printf("%02X ", data[i]);
    }
    printf("\n");
}

// Function to encode an object
void encode_object(asn_TYPE_descriptor_t *type_descriptor, const void *object) {
    uint8_t *buffer;
    size_t buffer_size = 1024; // Allocate a reasonable buffer size
    asn_enc_rval_t enc_result;

    // Allocate memory for the buffer
    buffer = (uint8_t *)malloc(buffer_size);
    if (buffer == NULL) {
        printf("Memory allocation failed\n");
        return;
    }

    // Perform encoding
    enc_result = uper_encode_to_buffer(type_descriptor, (void *)object, buffer, buffer_size);

    if (enc_result.encoded == -1) {
        printf("Failed to encode object of type %s\n", type_descriptor->name);
        free(buffer);
        return;
    }

    // Print the encoded output
    print_encoded(buffer, (enc_result.encoded + 7) / 8);

    // Free the allocated buffer
    free(buffer);
}

int main() {
    MyInteger_t myInt = 42; // Assign a value within the range (0..100)
    printf("Assigned MyInteger: %ld\n", myInt);

    // Encode MyInteger
    encode_object(&asn_DEF_MyInteger, &myInt);

    MyString_t myString;
    char sampleText[] = "Hello, ASN.1!";
    myString.buf = (uint8_t *)sampleText;
    myString.size = sizeof(sampleText) - 1;
    printf("Assigned MyString: %s\n", myString.buf);

    // Encode MyString
    encode_object(&asn_DEF_MyString, &myString);

    Person_t person;
    person.id = 1;
    char personName[] = "Rizwan";
    person.name.buf = (uint8_t *)personName;
    person.name.size = sizeof(personName) - 1;
    person.age = 25;

    printf("Assigned Person:\n");
    printf("  ID: %ld\n", person.id);
    printf("  Name: %s\n", person.name.buf);
    printf("  Age: %ld\n", person.age);

    // Encode Person
    encode_object(&asn_DEF_Person, &person);

    return 0;
}
