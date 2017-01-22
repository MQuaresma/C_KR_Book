#include <stdio.h>

static char daytab[2][13]={
    {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
    {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
};


/* day of the year: set day of the year from month and day */
int day_of_year(int month, int year, int day){

    int i, leap;
    leap = year%4 == 0 && year%100 != 0 || year%400 == 0;
    for(i = 1; i < month; i ++)
        day += daytab[leap][i];
    return day;

}


/* month_day: set month, day from day of year */
void month_day(int year, int yearday, int *pmonth, int *pday){

    int i, leap;

    leap = year%4 == 0 && year%100 != 0 || year%400 == 0;

    for(i = 1; yearday > daytab[leap][i]; i ++);
        yearday -= daytab[leap][i];

    *pmonth = i; 
    *pday = yearday;
}

main(void){


    int year, day;

    printf("%d\n", day_of_year(3, 2015, 15));
    
    return 0;
}
