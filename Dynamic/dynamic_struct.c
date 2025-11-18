/*------------------------------------------------------
* Filename: dynamic_struct.c
* Description: the program gets 2 hours and peints their addition 
*Author: Rephael Riahi
-------------------------------------------------------*/

#include <stdio.h>
#include "stdlib.h"

#define SEC_IN_MIN 60
#define MIN_IN_H 60
#define HOURS_IN_DAY 24

typedef struct{
    int hours;
    int minutes;
    int seconds;
}Time;

Time* make_time(int h, int min, int sec);
Time* add_times(Time *time1, Time *time2);

int main() {
    int check_h = 0, check_min = 0, check_sec = 0;
    Time *time1, *time2, *time3;

    time1 = (Time*)malloc(sizeof(Time));
    if(time1 == NULL){
        return -1;
    }
    time2 = (Time*)malloc(sizeof(Time));
    if(time2 == NULL){
        return -1;
    }
    time3 = (Time*)malloc(sizeof(Time));
    if(time3 == NULL){
        return -1;
    }

    printf("Enter the first time:\n");
    scanf("%d:%d:%d",&check_h,&check_min,&check_sec);
    if(check_h < 0 || check_h >= HOURS_IN_DAY ||
     check_min < 0 || check_min >= MIN_IN_H ||check_sec < 0 || check_sec >= SEC_IN_MIN){
        printf("Wrong input!");
        return 0;
    }else{
        time1 = make_time(check_h,check_min,check_sec);
    }

    printf("Enter the second time:\n");
    scanf("%d:%d:%d",&check_h,&check_min,&check_sec);
    if(check_h < 0 || check_h >= HOURS_IN_DAY ||
     check_min < 0 || check_min >= MIN_IN_H ||check_sec < 0 || check_sec >= SEC_IN_MIN){
        printf("Wrong input!");
        return 0;
    }else{
        time2 = make_time(check_h,check_min,check_sec);
    }

    time3 = add_times(time1,time2);

    printf("The added time :\n%d:%d:%d\n", time3->hours, time3->minutes, time3->seconds);
    return 0;
}

Time* make_time(int h, int min, int sec){
    Time *time = (Time*)malloc(sizeof(Time));
    if(time == NULL){
        return NULL;
    }
    time -> hours = h;
    time -> minutes = min;
    time -> seconds = sec;
    return time;
}

Time* add_times(Time *time1, Time *time2){
    int add_h = 0, add_min = 0, add_sec = 0;

    add_sec = time1 -> seconds + time2 -> seconds;
    add_min = time1 -> minutes + time2 -> minutes + add_sec / SEC_IN_MIN;
    add_h = time1 -> hours + time2 -> hours + add_min / MIN_IN_H;

    add_sec %= SEC_IN_MIN;
    add_min %= MIN_IN_H;
    add_h %= HOURS_IN_DAY;

    return make_time(add_h,add_min,add_sec);
}