//wap to convert lowercase to uppercase.
#include<stdio.h>
int main(){
    char ch;
    printf("Enter a character: ");
    scanf("%c",&ch);

    if(ch >= 'a' && ch <= 'z'){
        ch = ch - 32;
    }
    printf("Uppercase character: %c", ch);
    return 0;

}