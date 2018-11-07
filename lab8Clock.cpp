#include <iostream>
#include <stdlib.h>
#include "lab8Clock.h"
using namespace std;

int Clock::get_hour() const { return hour; }
void Clock::set_hour(int h){ 
    if(h < 23 && h >= 0)
        hour = h;
}

int Clock::get_minute() const { return minute; }
void Clock::set_minute(int m){ 
    if(m < 59 && m >= 0)
        minute = m; 
}

int Clock::get_second() const { return second; }
void Clock::set_second(int s){ 
    if(s < 59 && s >= 0)
        second = s;
}

Clock::Clock(): hour(0), minute(0), second(0) { };

Clock::Clock(int s){
    if(s < 0){
        hour = 0;
        minute = 0;
        second = 0;
    }else{
        sec_to_hms(s);
    }
}

Clock::Clock(int h, int m, int s){
    if(h > 23 || h < 0 || m > 59 || m < 0 || s > 59 || s < 0){
        hour = 0;
        minute = 0;
        second = 0;
    }else{
        hour = h;
        minute = m;
        second = s;
    }
}

void Clock::increment(){
    second++;
    if(second > 59){
        second = 0;
        minute++;
    }
    if(minute > 59){
        minute = 0;
        hour++;
    }
    if(hour > 23){
        hour = 0;
    }
}

void Clock::decrement(){
    second--;
    if(second < 0){
        second = 59;
        minute--;
    }
    if(minute < 0){
        minute = 59;
        hour--;
    }
    if(hour < 0){
        hour = 23;
    }
}

void Clock::add_seconds(int s){
    if (s >= 0){
        int t;
        t = hms_to_sec() + s;
        sec_to_hms(t);
    }
}

int Clock::hms_to_sec(){
    int t = hour * 3600 + minute * 60 + second;
    return t;
}

void Clock::sec_to_hms(int s){
    hour = s / 3600;
    minute = (s % 3600) / 60;
    second = (s % 3600) % 60;
    if(hour > 23){
        hour = hour % 24;
    }
}