#ifndef TIME_HPP
#define TIME_HPP
class Time
{
private:
    int year;
    int month;
    int day;
    double hour;

public:
    Time(int y, int m, int d, double h);
    Time();
    ~Time();
    bool compareTime(Time time);
    int getYear();
    int getMonth();
    int getDay();
    double getHour();
    void setYear(int y);
    void setMonth(int m);
    void setDay(int d);
    void setHour(double h);
    bool isEqual(Time time);
    void addTime(double h);
    double getTotalHours();
};
#endif