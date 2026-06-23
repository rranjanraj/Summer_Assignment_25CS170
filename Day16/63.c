#include<stdio.h>
int main(){
    int n,i,j,sum;
    printf("Enter the size of an array:");
    scanf("%d",&n);

    printf("Enter the target sum:");
    scanf("%d",&sum);

 int a[n];
    printf("Enter the element in array:");
    for( i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    for(i=0;i<n;i++){
        for(j=i+1;j<n;j++){
            if(a[i]+a[j]==sum){
                printf("Pair with sum %d is :(%d, %d)\n",sum,a[i],a[j]);
            }
        }
    }
    return 0;
}   