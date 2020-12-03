#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include <string.h>
#include <errno.h>

struct Employee
{
    int sr;
    char fullName[25];
    char job[10];
    long phone;
};

int main() {
    int i;
    struct Employee Emp[4]; //array of structure
    for (i = 0; i < 4; i++)
    {

        printf("\nEnter details of %d Employee", i + 1);
        Emp[i].sr = i;

        printf("\n\tEnter Employee Full Name : ");
        scanf("%s", Emp[i].fullName );

        printf("\n\tEnter Employee Job Title : ");
        scanf("%s", Emp[i].job);

        printf("\n\tEnter Employee Phone Number : ");
        scanf("%ld", &Emp[i].phone);
    }

    printf("\nDetails of Employees");
    for (i = 0; i < 4; i++)
        printf("\n %d \t %s \t %s \t %ld", Emp[i].sr + 1, Emp[i].fullName, Emp[i].job, Emp[i].phone);

    int temp, temp1;
    char name[25];

    temp1 = 0;
    while (1) {
        temp = 0;
        printf("\n\nEnter the full name of the employee that you wish to copy to a text file :");
        scanf("%s", name);
        while (1) {
            if (strcmp(name, Emp[temp].fullName) == 0) {
                char buf[0x100];
                snprintf(buf, sizeof(buf), "D:\\%s.txt", name);    // change the location here before \\%s.txt
                FILE* fptr = fopen(buf, "w+");
                if (fptr == NULL)
                {
                    printf("Error!");
                    printf(" : %s\n", strerror(errno));
                    exit(1);
                }

                fprintf(fptr, "\n\t\t ---Employee Details--- \n\t Full Name : %s \n\t Job Title: %s \n\t Phone Number: %ld", Emp[temp].fullName, Emp[temp].job, Emp[temp].phone);
                fclose(fptr);


                temp1 = 1;
                break;
            }
            if (temp > 3) {
                printf("Details with this name not found...\nPlease Re-enter it again....");
                break;
            }
            temp++;
            // printf("%d",temp);
        }
        if (temp1) {
            break;
        }

    }



    return 0;
}
