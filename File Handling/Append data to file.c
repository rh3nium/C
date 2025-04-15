// Append data to file

#include <stdio.h>
int main()
{
    FILE *fp;
    char c;
    printf("Append data to file\n\n");
    // Open file in append mode
    fp = fopen("input.txt", "a");
    while ((c = getchar()) != EOF) {
        putc(c, fp);
    }
    /* How to initiate the EOF signal and display output:
    On Windows, press Ctrl+Z
    On Linux, press Ctrl+D
    */
   
    // Close file
    fclose(fp);
    return 0;
}