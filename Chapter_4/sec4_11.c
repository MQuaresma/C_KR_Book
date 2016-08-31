#include <stdio.h>
#define max(a,b) ((a>b) ? a : b)            /* macros can also be used as expressions */
#define try(expr, newline) printf(#expr "trying" #newline), printf("not finished" #newline),   /* adding an # before expr "turns" it into a literal string */

int main(){

    int x = 1, y = 2;

    try(3, \n) printf("One more thing\n");                     /* will print 3trying */
    printf("%d\n", max(2, 3));      /* will print 3 */
    return 0;

}
