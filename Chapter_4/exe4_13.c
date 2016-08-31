#include <stdio.h>
#include <string.h>

void reverse(char [], int , int);

main(){
    
    char s[] = "leugiM";
    reverse(s, 0, strlen(s) - 1);
    printf("%s\n", s);

    return 0;
}

/* reverse: recursive version of the function reverse, which allows for better readability */
void reverse(char s[], int left, int right){

    char c;

    if(left >= right) return;

    c = s[left];
    s[left] = s[right];
    s[right] = c;
    reverse(s, left+1, right-1);
}
