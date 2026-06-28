//wap to merge two sorted arrays.
#include <stdio.h>

int main() {
   int n1,n2;
    printf("Enter the size of the first sorted array");
    scanf("%d",&n1);
    int a1[n1];
    printf(" Enter %d sorted elemnet for the first array\n ",n1);
    for(int i=0;i<n1;i++){
        scanf("%d",&a1[i]);
    }

    printf("Enter the size of the second sorted array");
    scanf("%d",&n2);
    int a2[n2];
    printf(" Enter %d sorted elemnet for the first array\n ",n2);
    for(int i=0;i<n2;i++){
        scanf("%d",&a2[i]);
    }
    
    int mergearr[n1+n2];
    int i=0,j=0,k=0;

    while (i < n1 && j < n2) {
        if (a1[i] < a2[j]) {
            mergearr[k++] = a1[i++];
        } else {
            mergearr[k++] = a2[j++];
        }
    }

    while (i < n1) {
        mergearr[k++] = a1[i++];
    }

    while (j < n2) {
        mergearr[k++] = a2[j++];
    }

    printf("Merged array: ");
    for (int l = 0; l < n1 + n2; l++) {
        printf("%d ", mergearr[l]);
    }
    return 0;
}