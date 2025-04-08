// Call by reference

#include <stdio.h>
struct student {
    int age;
};
void modify(struct student *s) {
    s -> age = 30;
}
void main() {
    struct student s1 = {20};
    printf("Before call by reference: Age = %d\n", s1.age); /* Output: Age = 20 */
    modify(&s1);
    printf("After call by reference: Age = %d\n", s1.age); /* Output: Age = 30 */
}
