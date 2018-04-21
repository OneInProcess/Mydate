//
// Created by zyd on 2017/4/10.
// File Name:      MyDate.cpp
// Author:         Zhao YuDong
// Student Number: 3015230120
// Email:          zhao746714868@qq.com
// Assignment:     Mydate
// Version:        c++
// Description:    use seconds to save the time . And do the math.
//                 especially, I need to think of the years and the
//                 months'days.

#include <iostream>
#include <cmath>
#include <sstream>
#include <stdexcept>
#include "MyDate.h"

using namespace std;
int monthlist[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
int monthlistrun[] = {31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
int _1752monthlistrun[] = {31, 29, 31, 30, 31, 30, 31, 31, 19, 31, 30, 31};
//判断是否为闰年

bool MyDate::judgeRun(int jdYear) const {
    if (jdYear % 4 == 0 && jdYear % 100 != 0 || jdYear % 400 == 0) {
        return true;
    } else {
        return false;
    }
}

//以秒数直接存贮
MyDate::MyDate(long long sc) {
    this->sec = sc;
}

//根据日期到1970-01-01的时间来以秒存贮
MyDate::MyDate(int years, int months, int days) {
    if ((judgeRun(years) && monthlistrun[months - 1] >= days && days > 0) ||
        (!judgeRun(years) && monthlist[months - 1] >= days && days > 0)) {
        if (years >= 1970) {

            for (int i = 1970; i < years; i++) {
                if (judgeRun(i)) {
                    days = days + 366;
                } else {
                    days = days + 365;
                }
            }
            if (judgeRun(years)) {
                for (int i = 0; i < months - 1; i++) {
                    days = days + monthlistrun[i];
                }
            } else {
                for (int i = 0; i < months - 1; i++) {
                    days = days + monthlist[i];
                }

            }
            days = days - 1;
            sec = static_cast<long long >(days) * 24 * 60 * 60;
        } else {
            if (years == 1752 && months == 9 && days > 10) {
                days = days - 11;
            }
            int daysPass = days;
            days = 0;
            for (int i = years; i < 1970; i++) {
                if (judgeRun(i)) {
                    days = days + 366;
                    if (i == 1752) {
                        days = days - 11;
                    }
                } else {
                    days = days + 365;
                }
            }
            if (judgeRun(years)) {

                if (years == 1752) {
                    for (int i = 0; i < months - 1; i++) {
                        daysPass = daysPass + _1752monthlistrun[i];
                    }
                } else {
                    for (int i = 0; i < months - 1; i++) {
                        daysPass = daysPass + monthlistrun[i];
                    }
                }
            } else {
                for (int i = 0; i < months - 1; i++) {
                    daysPass = daysPass + monthlist[i];
                }


            }
            days = days - daysPass;
            sec = -static_cast<long long >(days) * 24 * 60 * 60;
        }
    } else {
        throw invalid_argument("Invalid Date!");
    }
}

//增加日期，用秒来计算
MyDate MyDate::add(int addDay) const {
    return MyDate(static_cast<long long >(this->sec) + static_cast<long long >(addDay) * 24 * 60 * 60);
}

//日期相减，用秒计算
MyDate MyDate::subtract(int subDay) const {
    return MyDate(static_cast<long long >(this->sec) - static_cast<long long > (subDay) * 24 * 60 * 60);
}

int MyDate::subtract(const MyDate &mydateNew) const {
    long long secOld = this->sec;
    long long secNew = mydateNew.sec;
    return static_cast<long long >(secOld - secNew) / 60 / 60 / 24;
}

//判断秒数是否相等
bool MyDate::equals(const MyDate &myDateNew) const {
    long long secOld = this->sec;
    long long secNew = myDateNew.sec;
    return secNew == secOld;
}

bool MyDate::lessThanOrEquals(const MyDate &myDateNew) const {
    long long secOld = this->sec;
    long long secNew = myDateNew.sec;
    return secOld <= secNew;
}

bool MyDate::lessThan(const MyDate &myDateNew) const {
    long long secOld = this->sec;
    long long secNew = myDateNew.sec;
    return secOld < secNew;
}

bool MyDate::greaterThan(const MyDate &myDateNew) const {
    long long secOld = this->sec;
    long long secNew = myDateNew.sec;
    return secOld > secNew;
}

bool MyDate::greaterThanOrEquals(const MyDate &myDateNew) const {
    long long secOld = this->sec;
    long long secNew = myDateNew.sec;
    return secOld >= secNew;
}

//将到1970-01-01的秒数转化为时间再转化为标准格式后输出
string MyDate::toString() const {
    if (this->sec >= 0) {
        int day = int(sec / 60 / 60 / 24);
        int year = 1970;
        int month = 0;
        while ((judgeRun(year) && day >= 366) || (!judgeRun(year) && day >= 365)) {
            year = year + 1;
            day = day - 365;
            if (judgeRun(year))
                day = day - 1;
        }
        day = day + 1;
        while ((judgeRun(year) && day > monthlistrun[month]) || (!judgeRun(year)) && day > monthlist[month]) {
            if (judgeRun(year)) {
                day = day - monthlistrun[month];
                month = month + 1;
            } else {

                day = day - monthlist[month];
                month = month + 1;
            }
        }
        month = month + 1;
        string day1;
        string month1;
        string year1;
        stringstream stringstream1;
        stringstream1 << day;
        stringstream1 >> day1;
        stringstream1.clear();
        stringstream1 << month;
        stringstream1 >> month1;
        stringstream1.clear();
        stringstream1 << year;
        stringstream1 >> year1;
        year1 = "000" + year1;
        month1 = "0" + month1;
        day1 = "0" + day1;
        int lengthyear = year1.length();
        string year2 = "";
        year2 = year2 + year1[lengthyear - 4] + year1[lengthyear - 3] + year1[lengthyear - 2] + year1[lengthyear - 1];
        int lenthmonth = month1.length();
        string month2 = "";
        month2 = month2 + month1[lenthmonth - 2] + month1[lenthmonth - 1];
        int lenthday = day1.length();
        string day2 = "";
        day2 = day2 + day1[lenthday - 2] + day1[lenthday - 1];
        string string1 = year2 + "-" + month2 + "-" + day2;
        return string1;
    } else {
        int day = int(sec / 60 / 60 / 24);
        int year = 1970;
        int month = 0;
        while (day < 0) {
            if (year == 1753) {
                year = year - 1;
                day = day + 354;
            } else {
                year = year - 1;
                day = day + 365;
                if (judgeRun(year))
                    day = day + 1;
            }
        }
        day = day + 1;
        while ((judgeRun(year) && day > monthlistrun[month]) || (!judgeRun(year)) && day > monthlist[month] ||
               (year == 1752 && day > _1752monthlistrun[month])) {
            if (year == 1752) {
                day = day - _1752monthlistrun[month];
                month = month + 1;
            } else if (judgeRun(year)) {
                day = day - monthlistrun[month];
                month = month + 1;
            } else {

                day = day - monthlist[month];
                month = month + 1;
            }
        }
        month = month + 1;
//        if(day==0){
//            if(month==1){
//                month=12;
//            } else{
//                month=month-1;
//            }
//            day=monthlist[month-1];
//        }
        string day1;
        string month1;
        string year1;
        stringstream stringstream1;
        stringstream1 << day;
        stringstream1 >> day1;
        stringstream1.clear();
        stringstream1 << month;
        stringstream1 >> month1;
        stringstream1.clear();
        stringstream1 << year;
        stringstream1 >> year1;
        year1 = "000" + year1;
        month1 = "0" + month1;
        day1 = "0" + day1;
        int lengthyear = year1.length();
        string year2;
        if (year1[3] == '-') {
            year1[3] = '0';
            year2 = "-";
            year2 = year2 + year1[lengthyear - 4] + year1[lengthyear - 3] + year1[lengthyear - 2] +
                    year1[lengthyear - 1];

        } else {
            year2 = "";
            year2 = year2 + year1[lengthyear - 4] + year1[lengthyear - 3] + year1[lengthyear - 2] +
                    year1[lengthyear - 1];
        }
        int lenthmonth = month1.length();
        string month2 = "";
        month2 = month2 + month1[lenthmonth - 2] + month1[lenthmonth - 1];
        int lenthday = day1.length();
        string day2 = "";
        day2 = day2 + day1[lenthday - 2] + day1[lenthday - 1];
        string string1 = year2 + "-" + month2 + "-" + day2;
        return string1;
    }
}

bool MyDate::operator==(const MyDate &newDate) const {
    return this->equals(newDate);
}

bool MyDate::operator<(const MyDate &newDate) const {
    return this->lessThan(newDate);
}

bool MyDate::operator<=(const MyDate &newDate) const {
    return this->lessThanOrEquals(newDate);
}

bool MyDate::operator>(const MyDate &newDate) const {
    return this->greaterThan(newDate);
}

bool MyDate::operator>=(const MyDate &newDate) const {
    return this->greaterThanOrEquals(newDate);
}

MyDate MyDate::operator+(int days) const {
    return this->add(days);
}

MyDate MyDate::operator-(int days) const {
    return this->subtract(days);
}

int MyDate::operator-(const MyDate &newDate) const {
    return this->subtract(newDate);
}

ostream &operator<<(ostream &os, const MyDate &dt) {
    os << dt.toString();
    return os;
}