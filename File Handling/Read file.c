// Read file

#include <stdio.h>
int main()
{
    FILE *fp;
    char c;
    printf("Read data\n\n");
    // Open file in read mode
    fp = fopen("input.txt", "r");
    // Close file
    fclose(fp);
    return 0;
}