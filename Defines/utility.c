#include <stdio.h>
#include <math.h>
#include <stddef.h>

#define PI 3.14159265358979323846

#define DEGREES_TO_RAD(degrees) ((degrees)*(PI/180))
#define RAD_TO_DEGREES(rad) ((rad)*(180/PI))

#define stringify(entry) #entry
#define glue(a, b) a##b

#define KiloBytes(value) ((size_t)(value) * 1024L)
#define MegaBytes(value) ((size_t)KiloBytes(value) * 1024L)
#define GigaBytes(value) ((size_t)MegaBytes(value) * 1024L)

#define MIN(a, b) (((a) < (b)) ? (a) : (b))
#define MAX(a, b) (((a) > (b)) ? (a) : (b))
#define CLAMP(value, min_value, max_value) (MIN(MAX(value, min_value), max_value))
#define SQUARED(a) ((a) * (a))

#define FIRST_DIGIT(number) ((int)number % 10)
#define GET_BIT(number, bit_to_check) ((number & (1 << bit_to_check)) >> bit_to_check)
#define SET_BIT(number, bit_to_set) number |= (1 << bit_to_set)
#define UNSET_BIT(number, bit_to_unset) number &= (~(1 << bit_to_unset))

// PLEASE NOTE THIS ONLY WORKS ON STACK-BASED ARRAYS AN NOT POINTERS OR ARRAYS DECAYED INTO POINTERS
#define ArrayCount(array) (int)(sizeof(array) / sizeof(array[0]))

int main() {
    // --- Angle conversion ---
    double deg = 90.0;
    double rad = DEGREES_TO_RAD(deg);
    printf("%f degrees = %f radians\n", deg, rad);
    printf("%f radians = %f degrees\n", rad, RAD_TO_DEGREES(rad));

    // --- Stringify and glue ---
    printf("Stringify macro: %s\n", stringify(HelloWorld));
    int glue(var, 1) = 42; // becomes var1
    printf("Glue macro result: %d\n", var1);

    // --- Memory size macros ---
    printf("1 KB = %zu bytes\n", KiloBytes(1));
    printf("2 MB = %zu bytes\n", MegaBytes(2));
    printf("1 GB = %zu bytes\n", GigaBytes(1));

    // --- Math macros ---
    int a = 5, b = 10;
    printf("MIN(%d, %d) = %d\n", a, b, MIN(a, b));
    printf("MAX(%d, %d) = %d\n", a, b, MAX(a, b));
    printf("CLAMP(15, 0, 10) = %d\n", CLAMP(15, 0, 10));
    printf("SQUARED(%d) = %d\n", a, SQUARED(a));

    // --- Bit manipulation ---
    unsigned int num = 5; // in binary its 0101
    printf("Original number: %u\n", num);
    SET_BIT(num, 1); // now its 0111 = 7
    printf("After setting bit 1: %u\n", num);
    UNSET_BIT(num, 2); // now its 0011 = 3
    printf("After unsetting bit 2: %u\n", num);
    printf("Bit 0: %d\n", GET_BIT(num, 0));
    printf("First digit of 123 = %d\n", FIRST_DIGIT(123));

    // --- Array count ---
    int arr[] = {1, 2, 3, 4, 5};
    printf("Array count: %d\n", ArrayCount(arr)); // length is s5

    return 0;
}

/* Output:
90.000000 degrees = 1.570796 radians
1.570796 radians = 90.000000 degrees
Stringify macro: HelloWorld
Glue macro result: 42
1 KB = 1024 bytes
2 MB = 2097152 bytes
1 GB = 1073741824 bytes
MIN(5, 10) = 5
MAX(5, 10) = 10
CLAMP(15, 0, 10) = 10
SQUARED(5) = 25
Original number: 5
After setting bit 1: 7
After unsetting bit 2: 3
Bit 0: 1
First digit of 123 = 3
Array count: 5
*/