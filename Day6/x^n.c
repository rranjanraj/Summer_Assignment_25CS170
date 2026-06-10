#include <stdio.h>
int main() {
    int n,p,i,c=1,temp;
    
    printf("Enter a base number: ");
    scanf("%d", &n);
    printf("Enter the power ");
    scanf("%d",&p);

    for(i=1;i<=p;i++) {
        temp=n;
       c=c*temp;
    }
    printf("Result :%d",c);
    return 0;
}