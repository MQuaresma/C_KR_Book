#include <stdio.h>


main(){


    printf("Hello World!!\b \n"); /* the backspace erases the second exclamation mark */
    printf("Monday \t Tuesday \v \v Weekdays\n"); /* the \v escape sequence represents a vertical tab as opposed to the horizontal one from \t */
    printf("Monday \t Tuesday \n \n \t \t Weekdays");/* produces similar result to the previous instruction */
    return 0;

}
