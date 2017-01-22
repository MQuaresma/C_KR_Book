#include <stdio.h>

int daytab[2][13]={
    {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
    {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}
};


/* day_of_year: set day of the year from month and day */
int day_of_year(int year, int month, int day){


    int leap, i;

    leap = !(year % 4) && ((year % 100) || !(year%400));

    for(i = 1; month > i; i ++) 
        day += *(*(daytab+leap)+i);

    return day;            
}


/* month_day: set month, day from day of the year */
void month_day(int year, int yearday, int *pmonth, int *pday){
    
    int i, leap;

    leap = !(year % 4) && (year%100 || !(year%400));

    for(i = 1; yearday > *(*(daytab+leap)+i); i ++)
        yearday -= *(*(daytab+leap)+i);

    *pmonth = i;
    *pday = yearday;

}
    


main(void){


    int month, day;

    printf("%d\n", day_of_year(2012, 3, 15));

    month_day(2015, 74, &month, &day);
    printf("%d %d\n", month, day);
    
    return 0;
}
