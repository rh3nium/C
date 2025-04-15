// Write data to file

#include <stdio.h>
int main()
{
    FILE *fp;
    char c;
    printf("Write data to file\n\n");

    // Open file in write mode
    fp = fopen("input.txt", "w"); // If file does not exist, new file will be created

    while ((c = getchar()) != EOF) { // EOF - End of file signal
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