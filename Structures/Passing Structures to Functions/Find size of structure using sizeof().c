// Find size of structure using sizeof()

#include <stdio.h>
struct Student {
    int id;
    char name[20];
    float marks;
    long int mobile;
    char address[100];
};
int main() {
    struct Student s1;
    printf("Size of structure using variable: %lu bytes\n", sizeof(s1)); /* Output: 144 bytes */
    printf("Size of structure using type: %lu bytes\n", sizeof(struct Student)); /* Output: 144 bytes */
    return 0;
}