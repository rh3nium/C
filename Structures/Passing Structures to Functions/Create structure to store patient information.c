// Define structure to store patient information

#include <stdio.h>
struct dob {
    int day;
    int month;
    int year;
};
struct Patient {
    int id;
    char name[50];
    struct dob dob;
};
int main() {
    struct Patient p[2];
    for (int i=0; i<2; i++) {
        printf("\nEnter details for patient %d:", i+1);
        printf("\nID: ");
        scanf("%d", &p[i].id);
        printf("Name: ");
        scanf("%s", p[i].name);
        printf("DOB (DD-MM-YYYY): "); 
        scanf("%d %d %d", &p[i].dob.day, &p[i].dob.month, &p[i].dob.year);
    };
    printf("\nPatient Details:");
    for (int i=0; i<2; i++) {
        printf("\n%d:\n", i+1);
        printf("ID: %d\nName: %s\nDOB: %d-%d-%d\n", p[i].id, p[i].name, p[i].dob.day, p[i].dob.month, p[i].dob.year);
    }
    return 0;
}