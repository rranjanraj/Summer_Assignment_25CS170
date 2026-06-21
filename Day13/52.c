#include<stdio.h>
int main(){
    int a[100],n,i,evencount=0,oddcount=0;
    printf("Enter the size of array: ");
    scanf("%d",&n);

    printf("Enter the element in array:");
    for(int i=0;i<n;i++){
        scanf("%d",&a[i]);
        if(a[i]%2==0){
            evencount++;
        }
        else{
            oddcount++;
        }
    }
    printf("The number of even element is: %d\n",evencount);
    printf("The number of odd element is :%d\n",oddcount); 
    return 0;
}