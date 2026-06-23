#include<stdio.h>
int main(){
    int n,i,j;
    printf("Enter the size of an array:");
    scanf("%d",&n);
 int a[n];
    printf("Enter the element in array:");
    for( i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    int unique_a[n];
    int unique_count=0;
    for(i=0;i<n;i++){
        int is_duplicate=0;
        for(j=0;j<unique_count;j++){
            if(a[i]==unique_a[j]){
                is_duplicate=1;
                break;
            }

        }
        if (!is_duplicate){
            unique_a[unique_count++]=a[i];
        }
    }
    printf("Array after removing duplicate:");
    for(i=0;i<unique_count;i++){
        printf("%d\n",unique_a[i]);
    }
    return 0;

}    