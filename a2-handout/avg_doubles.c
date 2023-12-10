#include "numlib.h"
#include <stdio.h>

int main() {
    double sum = 0.0, value;
    int count = 0;
    while (read_double_bin(stdin, &value) == 0) {
        sum += value;
        count++;
    }
    if (count == 0) {
        fprintf(stderr, "No numbers provided\n");
        return 1;
    }
    double average = sum / count;
    write_double_ascii(stdout, average);
    printf("\n");
    return 0;
}