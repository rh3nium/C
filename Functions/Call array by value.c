// Call array by value

#include<stdio.h>
void modify(int *arr) {
    arr[2] = 98;
}
int main() {
    int nums[] = {1, 2, 3};
    modify(nums);
    printf("Modified array: %d, %d, %d\n", nums[0], nums[1], nums[2]); /* Output: 1, 2, 98 */
}