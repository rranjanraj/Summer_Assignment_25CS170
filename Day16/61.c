#include<stdio.h>
int main(){
    int n,i;
    printf("Enter the size of an array:");
    scanf("%d",&n);
 int a[n];
    printf("Enter the element in array:");
    for( i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    int expectedsum=(n+1)*(n+2)/2;
    int actual_sum=0;
    for(i=0;i<n;i++){
        actual_sum+=a[i];
    }
    int missingnumber=expectedsum-actual_sum;
    printf("The missing number is:%d\n",missingnumber);

    return 0;
}