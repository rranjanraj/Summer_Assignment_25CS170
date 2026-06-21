#include<stdio.h>
int main(){
    int a[100],n,i,key,count=0;
    printf("Enter the size of array:");
    scanf("%d",&n);

    printf("Enter the element in array:");
    for(i=0;i<n;i++){
        scanf("%d",&a[i]);
    }

    printf("Enter the element to find frequency:");
    scanf("%d",&key);
    for( i=0;i<n;i++){
        if (a[i]==key){
         count++;
    }
  } 
  printf("Frequency of %d is:%d\n",key,count);
  return 0;
}