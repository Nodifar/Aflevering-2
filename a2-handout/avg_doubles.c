//mulig svar

#include <stdio.h>
#include <stdlib.h>

extern double read_double_bin();
extern void write_double_ascii(double);

int main() {
    double sum = 0.0;
    int count = 0;
    double number;
    
    while (fread(&number, sizeof(double), 1, stdin)) {
        sum += number;
        count++;
    }

    if (count == 0) {
        fprintf(stderr, "No numbers input.\n");
        return 1;
    }

    double avg = sum / count;
    write_double_ascii(avg);
    printf("\n");

    return 0;
}
