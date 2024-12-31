#include "Time.hpp"

Time::Time(int y, int m, int d, double h) : year(y), month(m), day(d), hour(h) {}

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

int Time::getYear() const
{
    return year;
}

int Time::getMonth() const
{
    return month;
}

int Time::getDay() const
{
    return day;
}

double Time::getHour() const
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
