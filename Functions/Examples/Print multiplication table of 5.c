// Print multiplication table of 5

#include<stdio.h>
int printTable() {
    int num = 5;
    for (int i = 1; i <= 12; i++){
        printf("%d\n", num*i);
    }
}
int main() {
    printTable();
    return 0;
}
/* Output:
5
10
15
20
15
20
25
30
35
40
45
50
55
60
*/