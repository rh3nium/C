// Convert Fahrenheit to Celsius and Celsius to Fahrenheit

#include<stdio.h>
int main() {
    float temp;
    int choice;
    // Display menu to user
    printf("Temperature Conversion\n");
    printf("1. Convert Fahrenheit to Celsius\n");
    printf("2. Convert Celsius to Fahrenheit\n");
    printf("Enter your choice - 1 or 2: ");
    scanf("%d", &choice);
    // Perform conversion
    if(choice == 1) {
        printf("Enter temperature in Fahrenheit: ");
        scanf("%f", &temp);
        temp = (temp - 32) * 5 / 9;
        printf("Temperature in Celsius: %.2f\n", temp);
    } else if(choice == 2) {
        printf("Enter temperature in Celsius: ");
        scanf("%f", &temp);
        temp = (temp * 9 / 5) + 32;
        printf("Temperature in Fahrenheit: %.2f\n", temp);
    } else {
        printf("Invalid choice. Please select either 1 or 2.\n");
    }
    return 0;
}
