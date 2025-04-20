// fscanf - Read data in file

#include <stdio.h>
#include<stdlib.h>
int main() {
    FILE *File = fopen("input.txt", "r");
    if (File == NULL) {
        printf("Failed to open file\n");
        return 1;
    }
    else {
        char name[50];
        // fscanf() - Read data in file
        fscanf(File, "%s", name);
        // Print data read by fscanf()
        printf("Name: %s\n", name);
        fclose(File);
        return 0;
    }
}