// getw(), putw() - Gets and Writes data to file

#include <stdio.h>
int main()
{
    FILE *sFile, *dFile;
    int n;
    sFile = fopen("input.txt", "r");
    if (sFile == NULL) {
        printf("Failed to open file\n");
        return 1;
    }
    dFile = fopen("output.txt", "w");
    if (dFile == NULL) {
        printf("Failed to open file\n");
        fclose(sFile);
        return 1;
    }
    while ((n = getw(sFile))!=EOF) {
        putw(n, dFile);
    }
    fclose(sFile);
    fclose(dFile);
    printf("Data copied successfully");
    return 0;
}