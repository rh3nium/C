// Calculate and display average and total of subject marks

#include <stdio.h>
int main() {
    float marks[5], total = 0, average;
    for(int i = 0; i < 5; i++) {
        printf("Enter marks for subject %d: ", i + 1);
        scanf("%f", &marks[i]);
        total += marks[i];
    }
    average = total / 5;
    printf("\n Total marks: %.2f \n", total);
    printf("Average marks: %.2f \n", average);
    return 0;
}
