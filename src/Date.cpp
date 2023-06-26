#include "Date.h"
Date::Date() : day(1), month(1), year(1900) {
    std::tm t{};
    t.tm_year = year - 1900;  
    t.tm_mon = month - 1;  
    t.tm_mday = day;
    tp = std::chrono::system_clock::from_time_t(std::mktime(&t));
}
Date::Date(int day, int month, int year) 
: day(day), month(month), year(year) {
    std::tm t{};
    t.tm_year = year - 1900;  // Les années comptent à partir de 1900
    t.tm_mon = month - 1;  // Les mois vont de 0 (janvier) à 11 (décembre)
    t.tm_mday = day;
    tp = std::chrono::system_clock::from_time_t(std::mktime(&t));
}

Date::~Date(){}

int Date::daysBetween(const Date& d1, const Date& d2) {
    return std::chrono::duration_cast<std::chrono::hours>(d2.tp - d1.tp).count() / 24;
}

// Getters
int Date::getDay() const {
    return day;
}

int Date::getMonth() const {
    return month;
}

int Date::getYear() const {
    return year;
}

// Setters
void Date::setDay(int newDay) {
    day = newDay;
    std::tm t{};
    t.tm_year = year - 1900;  
    t.tm_mon = month - 1;  
    t.tm_mday = day;
    tp = std::chrono::system_clock::from_time_t(std::mktime(&t));
}

void Date::setMonth(int newMonth) {
    month = newMonth;
    std::tm t{};
    t.tm_year = year - 1900;  
    t.tm_mon = month - 1;  
    t.tm_mday = day;
    tp = std::chrono::system_clock::from_time_t(std::mktime(&t));
}

void Date::setYear(int newYear) {
    year = newYear;
    std::tm t{};
    t.tm_year = year - 1900;  
    t.tm_mon = month - 1;  
    t.tm_mday = day;
    tp = std::chrono::system_clock::from_time_t(std::mktime(&t));
}


void Date::print() const {
    std::cout << day << '/' << month << '/' << year << std::endl;
}
