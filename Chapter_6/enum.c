#include <stdio.h>

/* Enumeration: Enumeration is a set of named integer constants */
enum DAY{
    saturday, 
    sunday,
    monday,
    tuesday,
    wednesday,
    thursday,
    friday,
}weekend1;

typedef enum DAY week;

main(){

    week curDay = thursday;
    week nextDay = friday;

    printf("Current day: %d\n", curDay);
    printf("Next day: %d\n", nextDay);
    printf("The first day of the weekend is: %d \n", weekend1);
    
    return 0;

}
