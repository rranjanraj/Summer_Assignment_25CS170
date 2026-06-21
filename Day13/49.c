#include<stdio.h>
int main(){
    int arr[100],n;
    printf("Enter the size of array :");
    scanf("%d",&n);

    printf("Enter the element in array:\n");
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }

    printf("The element in the array are:");
    for(int i=0;i<=n;i++){
        printf("%d\n",arr[i]);
    }
    
    return 0;
}