// Copy contents of one file to another

#include <stdio.h>
int main() {
    FILE *sourceFile, *destFile;
    char sourceName[100], destName[100];
    char ch;
    // Get source file name from user
    printf("Enter the source file name: ");
    scanf("%s", sourceName);
    // Get destination file name from user
    printf("Enter the destination file name: ");
    scanf("%s", destName);
    sourceFile = fopen(sourceName, "r");
    if (sourceFile == NULL) {
        printf("Error: Could not open source file.\n");
        return 1;
    }
    // Open the destination file in write mode
    destFile = fopen(destName, "w");
    if (destFile == NULL) {
        printf("Error: Could not open destination file.\n");
        fclose(sourceFile);
        return 1;
        // Copy contents from source file to destination file
        while ((ch = fgetc(sourceFile)) != EOF)
        {
        fputc(ch, destFile);
        }
        printf("File copied successfully.\n");
        // Close the files
        fclose(sourceFile);
        fclose(destFile);
        return 0;
        }
}