#include<stdio.h>
int main(){
    int a[100],n,i,count=0;
    printf("Enter the size of an array:");
    scanf("%d",&n);

    printf("Enter the element in array:");
    for( i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    for(i=0;i<n;i++){
        if(a[i]!=0){
            a[count++]=a[i];
        }
    }
    while(count <n){
        a[count++]=0;
    }

    printf("The array after moving zeroes to end is:");
    for( i=0;i<n;i++){
        scanf("%d",a[i]);
    }
    return 0;
}    