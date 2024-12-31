class Time
{
private:
    int year;
    int month;
    int day;
    double hour;

public:
    Time(int y, int m, int d, double h);
    ~Time();
    bool compareTime(Time time);
    int getYear() const;
    int getMonth() const;
    int getDay() const;
    double getHour() const;
    void setYear(int y);
    void setMonth(int m);
    void setDay(int d);
    void setHour(double h);
};
;