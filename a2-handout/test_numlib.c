#include "numlib.h"
#include <stdio.h>
#include <stdint.h>
#include <assert.h>


int test_uint_be() {
    //return 0;
    printf("> test_uint_be\n\n");
    //værdier der er allerede kodet ind i filen 
    const uint32_t known[] = {0, 999999, UINT32_MAX};
    const size_t num_known = sizeof(known) / sizeof(known[0]);
    const char *known_data_filename = "known_big_endian_data.bin";
    uint32_t read_value;
    FILE *known_data_file = fopen(known_data_filename, "rb");
    //Test til at tjekke op på om read_uint_be stadig virker, ved at læse fra filen som er korrekt sat op, med værdierne kodet ind
    printf("(!)READ KNOPWN DATA\n");
    for (size_t i = 0; i < num_known; ++i) {
        if (read_uint_be(known_data_file, &read_value) != 0) {
            fprintf(stderr, "Failed to read from file in test %zu\n", i + 1);
            fclose(known_data_file); 
            return 1; //💀
        }
        printf("Reading test %zu: %u\n", i + 1, read_value);
        printf("Expected value: %u\n", known[i]);
        if (read_value != known[i]) {
            fprintf(stderr, "Mismatch in test %zu: read %u, expected %u\n", i + 1, read_value, known[i]);
            fclose(known_data_file);
            return 1; //💀
        }
    }
    fclose(known_data_file);
    printf("\n");
    const char *output_filename = "output.txt";
    size_t num_tests = sizeof(known) / sizeof(known[0]);
    printf("(!)WRITE KNOPWN DATA\n");
    for (size_t i = 0; i < num_tests; ++i) {
        printf("Test %zu: Writing and reading value %u\n", i + 1, known[i]);
        //Først skrive til filen
        FILE *output_file = fopen(output_filename, "w");
        assert(output_file != NULL);
        assert(write_uint_be(output_file, known[i]) == 0);
        fclose(output_file);
        //Så læse fra filen som så er testen
        FILE *input_file = fopen(output_filename, "r");
        assert(input_file != NULL);
        assert(read_uint_be(input_file, &read_value) == 0);
        fclose(input_file);
        // self check til sidst
        assert(read_value == known[i]);
    }
    printf("\nAll Task 1 tests: success.\n\n");
    return 0;
}


int test_double_bin() {
    //return 0;
    printf("> test_double_bin\n\n");
    const char *known_data_filename = "known_double_bin_data.bin";
    //værdier der er allerede kodet ind i filen 
    double known[] = {0.0, 123.456, -123.456, 5e10 - 1, -5e10 + 1};  // Replace with actual known values
    double read_value;
    size_t num_known_tests = sizeof(known) / sizeof(known[0]);
    FILE *known_data_file = fopen(known_data_filename, "rb");
    //Test til at tjekke op på om read_double_bin stadig virker, ved at læse fra filen som er korrekt sat op, med værdierne kodet ind
    printf("(!)READ KNOPWN DATA\n");
    for (size_t i = 0; i < num_known_tests; ++i) {
        if (read_double_bin(known_data_file, &read_value) != 0) {
            fprintf(stderr, "Failed to read from file in test %zu\n", i + 1);
            fclose(known_data_file);
            return 1;//💀
        }
        printf("Reading Test %zu: %f\n", i + 1, read_value);
        printf("Expected value: %f\n", known[i]);
        if (read_value != known[i]) {
            fprintf(stderr, "Mismatch in test %zu: read %f, expected %f\n", i + 1, read_value, known[i]);
            fclose(known_data_file);
            return 1;//💀
        }
    }
    fclose(known_data_file);
    printf("\n");
  const char *output_filename = "output_double.bin";
  size_t num_tests = sizeof(known) / sizeof(known[0]);
  printf("(!)WRITE KNOPWN DATA\n");
  for (size_t i = 0; i < num_tests; ++i) {
    printf("Test %zu: Writing and reading value %f\n", i + 1, known[i]);
    //Først skrive til filen
    FILE *output_file = fopen(output_filename, "wb");
    assert(output_file != NULL);
    assert(write_double_bin(output_file, known[i]) == 0);
    fclose(output_file);
    //Så læse fra filen som så er testen
    FILE *input_file = fopen(output_filename, "rb");
    assert(input_file != NULL);
    assert(read_double_bin(input_file, &read_value) == 0);
    fclose(input_file);
    // self check til sidst
    assert(read_value == known[i]);
  }
  printf("\nAll Task 2 tests: success.\n\n");
  return 0;
}


int test_double_ascii() {
    //return 0;
    printf("> test_double_ascii\n\n");
    const char *known_data_filename = "known_double_ascii_data.txt";
    //værdier der er allerede kodet ind i filen 
    double known[] = {0.0, 123.456, -123.456, 5e10 - 1, -5e10 + 1};  // Replace with actual known values
    double read_value;
    size_t num_known_tests = sizeof(known) / sizeof(known[0]);
    FILE *known_data_file = fopen(known_data_filename, "r");
    //Test til at tjekke op på om read_double_ascii stadig virker, ved at læse fra filen som er korrekt sat op, med værdierne kodet ind
    printf("(!)READ KNOPWN DATA\n");
    for (size_t i = 0; i < num_known_tests; ++i) {
        if (read_double_ascii(known_data_file, &read_value) != 0) {
            fprintf(stderr, "Failed to read from file in test %zu\n", i + 1);
            fclose(known_data_file);
            return 1;//💀
        }
        printf("Reading Test %zu: %f\n", i + 1, read_value);
        printf("Expected value: %f\n", known[i]);
        if (read_value != known[i]) {
            fprintf(stderr, "Mismatch in test %zu: read %f, expected %f\n", i + 1, read_value, known[i]);
            fclose(known_data_file);
            return 1;//💀
        }
    }
    fclose(known_data_file);
    printf("\n");
    const char *output_filename = "output_double_ascii.txt";
    size_t num_tests = sizeof(known) / sizeof(known[0]);
    printf("(!)WRITE KNOPWN DATA\n");
    for (size_t i = 0; i < num_tests; ++i) {
        printf("Test %zu: Writing and reading value %f\n", i + 1, known[i]);
        //Først skrive til filen
        FILE *output_file = fopen(output_filename, "w");
        assert(output_file != NULL);
        assert(write_double_ascii(output_file, known[i]) == 0);
        fclose(output_file);
        //Så læse fra filen som så er testen
        FILE *input_file = fopen(output_filename, "r");
        assert(input_file != NULL);
        assert(read_double_ascii(input_file, &read_value) == 0);
        fclose(input_file);
        // self check til sidst
        assert(read_value == known[i]);
        
    }
    printf("\nAll tests of Task 3 and 4: success.\n\n");
    return 0;
}


int main() {
    int result = test_uint_be();
    if (result != 0) return result;
    result = test_double_bin();
    if (result != 0) return result;
    return test_double_ascii();
}
