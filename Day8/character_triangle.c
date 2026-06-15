#include<stdio.h>
int main(){
    int row;
    printf("Enter the number of row=");
    scanf("%d",&row);
    for(int i=1;i<=row;i++){
        for(int j=0;j<=i;j++){
            printf("%c",'A'+j);
        }
        printf("\n");
    }
    return 0;
}