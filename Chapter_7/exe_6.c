#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void patternFinder();

/* Pattern finding in files */
int main(int argc, char *argv[]){

    FILE *fp = NULL;
    char c, *prog = *argv, *line;
    int except, number, curLine;
    except = number = 0;

    while(--argc >= 0 && **++argv == '-'){
        while((c = *++*argv)){
             switch(c){
                case 'x':
                        except = 1;
                        break;
                case 'l':
                        number = 1;
                        break;
                default:
                        printf("%s: '%c' is not a valid parameter.\n",prog, c);
                        break;
            }
        }
    }
    if(argc <= 0){ 
        printf("%s: no pattern specified.\n", prog);
        exit(1);
    }
     
    if(!fp) fp = stdin;
    else if(argc > 0) fp = fopen(*argv, "r");
    curLine = 0;
    while(fgets(line,fp)){
        curLine ++;
        //if(strstr(line, ))
    }
}
