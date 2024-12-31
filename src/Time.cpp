#include "Time.hpp"

Time::Time(int y, int m, int d, double h) : year(y), month(m), day(d), hour(h) {}

Time::Time() : year(0), month(0), day(0), hour(0)
{
}

Time::~Time()
{
    year = 0;
    month = 0;
    day = 0;
    hour = 0;
}

bool Time::compareTime(Time time)
{
    if (year < time.getYear())
    {
        return true;
    }
    else if (year == time.getYear())
    {
        if (month < time.getMonth())
        {
            return true;
        }
        else if (month == time.getMonth())
        {
            if (day < time.getDay())
            {
                return true;
            }
            else if (day == time.getDay())
            {
                if (hour < time.getHour())
                {
                    return true;
                }
            }
        }
    }
    return false;
}

int Time::getYear()
{
    return year;
}

int Time::getMonth()
{
    return month;
}

int Time::getDay()
{
    return day;
}

double Time::getHour()
{
    return hour;
}

void Time::setYear(int y)
{
    year = y;
}

void Time::setMonth(int m)
{
    month = m;
}

void Time::setDay(int d)
{
    day = d;
}

void Time::setHour(double h)
{
    hour = h;
}

bool Time::isEqual(Time time)
{
    return year == time.getYear() && month == time.getMonth() && day == time.getDay() && hour == time.getHour();
}

void Time::addTime(double h)
{
    hour += h;
    if (hour >= 24)
    {
        hour -= 24;
        day++;
        if (day > 30)
        {
            day = 1;
            month++;
            if (month > 12)
            {
                month = 1;
                year++;
            }
        }
    }
}

double Time::getTotalHours()
{
    return year * 8760 + month * 720 + day * 24 + hour;
}
