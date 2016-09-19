#include <stdio.h>

static char daytab[2][13]={
    {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
    {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
};


/* day_of_the_year: set day of the year from month and day */
int day_of_the_year(int month, int day, int year){
    int i, leap;
    size_t size = sizeof(char);

    leap = year%4 == 0 && year%100 != 0 || year%400 == 0;

    if(month > 12 || month < 1 || day > *(daytab[0]+(leap*13+month)) || day < 1 || year < 0){
        printf("Invalid date\n");
        return -1;
    }

    for(i = 1; i < month; i ++)
        day +=  *(daytab[0]+(leap*13+month));       /*sizeof is used for portability reasons */

    return day;
}

/* month_day: set month, day from day of year */
void month_day(int year, int yearday, int *mon, int *day){

    int i, leap;
    leap = year%4 == 0 && year%100 != 0 || year%400 == 0;

    if(yearday > (365+leap) || yearday < 0 || year < 0){
        printf("Invalid year/yearday\n");
        return;
    }

    for(i = 1; yearday >  *(daytab[0]+(leap*13+i)); yearday -= *(daytab[0]+(leap*13+i)), i ++); 

    printf("Month: %d \t Day: %d\n", i, yearday);
    *day = yearday;
    *mon = i; 
}


int main(void){

    int month, day, yearday;

    yearday = day_of_the_year(3, 1, 2015);
    printf("Day:%d\n", yearday); 
    month_day(2015, yearday, &month, &day);

    return 0;
}
