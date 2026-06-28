// wap to create student record management system.
#include <stdio.h>
#include <string.h>

struct student{
int roll_no;
char name;
float sgpa;
};

int main() {
    int n,i;
    printf("Enter the number of student:");
    scanf("%d",&n);
    struct student s[n];
    

    for(i=0;i<n;i++){
        printf("Enter details of student\n",i+1);
        printf("Enter  the roll number");
        scanf("%d",&s[i].roll_no);

        printf("Enter  the name\n");
        scanf("%s",&s[i].name);
        
        printf("Enter  the last sem cgpa");
        scanf("%f",&s[i].sgpa);
    }

    printf("\n student records");
    for(i=0;i<n;i++){
        printf("%-10s %-20s %-5.2f\n",s[i].roll_no,s[i].name,s[i].sgpa);

    }
    return 0;


    
    
}