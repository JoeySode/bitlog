#include <stdio.h>
#include <stdlib.h>
#include <string.h>


void printULL(const char* str) {

    uint64_t n = strtoull(str, NULL, 10);
    int bit = 63;

    printf("%llu\t0b", n);

    // Following code does not work properly when n is 0, so return if it is
    if (n == 0) {
        puts("0\t0x0");
        return;
    }

    // Find the first 1 in n from left to right
    while ((n >> bit) == 0)
        bit--;

    // Print all bits starting from the first 1 and moving to the right
    while (bit >= 0) {
        putchar('0' + ((n >> bit) & 1));

        bit--;
    }

    printf("\t0x%llx\n", n);
    
}

void printLL(const char* str) {

    long long n = strtoll(str, NULL, 10);
    int bit = 63;

    printf("%lld\t0b", n);

    // Following code does not work properly when n is 0, so return if it is
    if (n == 0) {
        puts("0\t0x0");
        return;
    }

    // Find the first 1 in n from left to right
    while ((n >> bit) == 0)
        bit--;

    // Print all bits starting from the first 1 and moving to the right
    while (bit >= 0) {
        putchar('0' + ((n >> bit) & 1));

        bit--;
    }

    printf("\t0x%llx\n", n);
    
}

void printF32(const char* str) {

    float f = strtof(str, NULL);
    uint32_t n;
    int bit = 31;

    memcpy(&n, &f, 4);

    // Transfer bytes from f to n to be read as an integer
    printf("%f\t0b", f);

    // Following code does not work properly when n is 0, so return if it is
    if (n == 0) {
        puts("0\t0x0");
        return;
    }

    // Find the first 1 in n from left to right
    while ((n >> bit) == 0)
        bit--;

    // Print all bits starting from the first 1 and moving to the right
    while (bit >= 0) {
        putchar('0' + ((n >> bit) & 1));

        bit--;
    }

    printf("\t0x%x\n", n);

}

void printF64(const char* str) {

    double f = strtod(str, NULL);
    uint64_t n;
    int bit = 63;

    // Transfer bytes from f to n to be read as an integer
    memcpy(&n, &f, 8);

    printf("%f\t0b", f);

    // Following code does not work properly when n is 0, so return if it is
    if (n == 0) {
        puts("0\t0x0");
        return;
    }

    // Find the first 1 in n from left to right
    while ((n >> bit) == 0)
        bit--;

    // Print all bits starting from the first 1 and moving to the right
    while (bit >= 0) {
        putchar('0' + ((n >> bit) & 1));

        bit--;
    }

    printf("\t0x%llx\n", n);

}


int main(int argc, char** argv) {

    // Values are interpreted as an unsigned integer type by default
    void(*print_func)(const char*) = printULL;

    // For consistency
    if (argv[1][0] != '-')
        printf("\nu64:\n");
    
    for (int i = 1; i < argc; i++) {

        // Check if the user is trying to change how the values are being interpreted
        if (strcmp(argv[i], "-u") == 0) {
            print_func = printULL;
            printf("\nu64:\n");
        }
        
        else if (strcmp(argv[i], "-s") == 0) {
            print_func = printLL;
            printf("\ni64:\n");
        }

        else if (strcmp(argv[i], "-f") == 0) {
            print_func = printF32;
            printf("\nf32:\n");
        }

        else if (strcmp(argv[i], "-d") == 0) {
            print_func = printF64;
            printf("\nf64:\n");
        }

        else
            print_func(argv[i]);
    }

    return 0;

}
