// Count number of positive, negative, and zero values input by user

#include<stdio.h>
int main() {
    int total, pos = 0, neg = 0, zero = 0;
    printf("Enter the total number of values you wish to input: ");
    scanf("%d", &total);
    int val[total];
    for (int i=0; i<total; i++) {
        printf("Enter value %d: ", i+1);
        scanf("%d", &val[i]);
    }
    for (int i=0; i<=total; i++) {
        if (val[i]>0) {
            pos+=1;
        }
        else if (val[i]<0) {
            neg+=1;
        }
        else zero+=1;
    }
    printf("\nNumber of positive values: %d", pos);
    printf("\nNumber of negative values: %d", neg);
    printf("\nNumber of zero values: %d\n", zero);
    return 0;
}