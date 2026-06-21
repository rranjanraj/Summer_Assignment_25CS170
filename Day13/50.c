#include<stdio.h>
int main(){
    int a[100],n,sum=0;
    float avg;
    printf("Enter the size of an array:");
    scanf("%d",&n);

    printf("Enter the element in array:");
    for(int i=0;i<n;i++){
        scanf("%d",&a[i]);
        sum=sum+a[i];
    }
    avg=(float)sum/n;

    printf("The sum of the array is: %d\n",sum);
     printf("The average of the array is: %f\n",avg);

     return 0;
}
