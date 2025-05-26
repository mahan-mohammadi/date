#include <iostream>
#include <string>
using namespace std;

enum Months {
    JANUARY = 1, FEBRUARY, MARCH, APRIL, MAY, JUNE, JULY, AUGHUST, SEPTEMBER, OCTOBER ,  NOVEMBER, DECEMBER
};

enum Mode {
    DDDYYYY , MMDDYY , TEXT 
};

class Date {
private:
    int day;
    int month;
    int year;
    static const int MONTHS_PER_YEAR = 12;
    static const int DAYS_PER_MONTH = 30;
    Mode mode;
    static Months daytomonth(Date);
public:
    Date(int, int);
    Date(int, int, int);
    Date(Months, int, int);
    Date();
    ~Date();

    void setDay(int);
    void setMonth(int);
    void setMonth(Months);
    void setYear(int);
    int getYear() const;
    int getDay() const;
    int getMonth() const;
    void setMode(Mode);
    int getMode() const;
    void print() const;
    void print0() const;
    void print1() const;
    void print2() const;
};

int Date::getYear() const {
    return year;
}

int Date::getDay() const {
    return day;
}

int Date::getMonth() const {
    return month;
}

void Date::setDay(int day) {
    this->day = day;
}

void Date::setMonth(int month) {
    this->month = month;
}

void Date::setMonth(Months month) {
    this->month = month;
}


void Date::setYear(int year) {
    this->year = year;
}

Date::Date(Months month, int day, int year) {
    this->month = month;
    if (day >= 1 && day < 30)
        this->day = day;
    this->year = year;
    mode = TEXT;
}

Date::Date(int month, int day, int year) {
    if (day >= 1 && day <= 30)
        this->day = day;
    if (month >= 1 && month <= MONTHS_PER_YEAR)
        this->month = month;
    this->year = year;
    mode = MMDDYY;
}
Date::~Date() {

}

void Date::print() const {
    switch (mode) {
    case DDDYYYY: print0(); break;
    case MMDDYY: print1(); break;
    case TEXT: print2(); break;
    }
}


void Date::print0() const {
    cout << day + ((month - 1) * 30) << " " << year;
}

void Date::print1() const {
    std::cout << month << "/" << day << "/" << year % 100;
}

void Date::print2() const {
    std::cout << static_cast<Months>(month) << " " << day << ", " << year;
}

Date::Date(int dayOfYear, int y) : year(y), mode(DDDYYYY) {
    int monthDays[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
    int m = 1;
    while (dayOfYear > monthDays[m - 1]) {
        dayOfYear -= monthDays[m - 1];
        m++;
    }
    month = m;
    day = dayOfYear;
}

Date::Date() {
    year = 1970;
    day = 1;
    month = 1;
}

int main() {
    Date d1(JANUARY, 15, 2023);
    Date birthday(DECEMBER, 21, 2005);
    d1.print(); // Output: 1/15/23 (if mode is MMDDYY)
    cout << '\n';
    d1.print0();
    cout << endl;
    d1.print2();
    cout << endl;
    d1.print();
    cout << endl;
    birthday.print0();
    return 0;
}