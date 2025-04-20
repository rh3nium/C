// fprintf - Write data to file

#include <stdio.h>
#include<stdlib.h>
int main() {
    FILE *File = fopen("input.txt", "w");
    if (File == NULL) {
        printf("Failed to open file\n");
        return 1;
    }
    else {
        char name[] = "Riya";
        // fprintf - Write data to file
        fprintf(File, "%s", name);
        fclose(File);
        return 0;
    }
}