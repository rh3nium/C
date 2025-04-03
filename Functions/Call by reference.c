// Call by Reference

void modify(int *x) {
    *x = 20;
    printf("Inside function: x = %d\n", *x);
}

int main() {
    int a = 10;
    modify(&a); /* Output: x = 20*/
    printf("After function call: a = %d\n", a); /* Output: a = 20 */
    return 0;
}