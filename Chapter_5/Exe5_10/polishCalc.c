#include <stdio.h> 
#include <ctype.h>
#include <string.h>
#include <math.h>

float strToFlt(char *);
char type(char *);
float pop();
void push(int);

/* exp: Reverse polish notation calclulator which takes CLI arguments as operands and operators */
main(int argc, char *argv[]){

    
    int op1;
    char c;

    if(--argc < 1){
        printf("Please check the manual for usage\n");
        return 1;
    }

    /*while(argc -- && **++argv == '-'){
        if(*++argv[0] == 'h'){
            printf("Polish Notation calculator\n");
            printf("Example:\n 2 3 4 + x = 2 * (3+4) = 14\n");
        }
    }*/

    
    while(argc --){
        switch((c = type(*++argv))){
            case '+': 
                push(pop()+pop());
                break;
            case '-': 
                op1 = pop();
                push(pop()-op1);
                break;
            case 'x': 
                push(pop()*pop());
                break;
            case '/': 
                op1 = pop();
                push(pop()/op1);
                break;
            case 'n':
                push(strToFlt(*argv));
                break;
            case 'e':
                push(M_E);
                break;
            default:
                printf("Invalid parameter, please check manual for usage\n");
                break;
        }
    }

    printf("Result: %.3f\n", pop());
    
    return 0;

}
