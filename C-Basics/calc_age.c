/*------------------------------------------------------
* Filename: calc_age.c
* Description: The program gets the current date and a birth date and calculate the age.
* Author: Rephael Riahi
-------------------------------------------------------*/

#include <stdio.h>

#define DAYS_IN_YEAR 365
#define DAYS_IN_MONTH 30

int main() {
    int day = 0, month = 0, year = 0, current_day = 0, current_month = 0, current_year = 0, days_age = 0;
    float months_age = 0.0, years_age = 0.0;

    printf("Enter current date: \n");
    scanf("%d/%d/%d",&current_day,&current_month,&current_year);
    printf("Enter your birthday: \n");
    scanf("%d/%d/%d",&day,&month,&year);
    // I separted the lines for readability
    days_age = current_year * DAYS_IN_YEAR + current_month * DAYS_IN_MONTH + current_day;
    days_age -= year * DAYS_IN_YEAR + month * DAYS_IN_MONTH + day;
    months_age = (double)days_age / DAYS_IN_MONTH;
    years_age = (double)days_age / DAYS_IN_YEAR;

    printf("Your age in days : %d\n",days_age);
    printf("Your age in months : %f\n",months_age);
    printf("Your age in years : %f\n",years_age);
    return 0;
}
