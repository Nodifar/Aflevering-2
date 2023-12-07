//mulig svar

#include <stdio.h>
#include <stdlib.h>

// Assuming read_double_bin() and write_double_ascii() are defined elsewhere
extern double read_double_bin();
extern void write_double_ascii(double);

int main() {
    double sum = 0.0;
    int count = 0;
    double number;

    // Read numbers until EOF
    while (fread(&number, sizeof(double), 1, stdin)) {
        sum += number;
        count++;
    }

    // Check if no numbers were read
    if (count == 0) {
        fprintf(stderr, "No numbers input.\n");
        return 1;
    }

    // Compute and print the average
    double avg = sum / count;
    write_double_ascii(avg);
    printf("\n");

    return 0;
}
