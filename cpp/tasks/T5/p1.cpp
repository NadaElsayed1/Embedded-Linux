#include <iostream>
#include <iomanip>

class Time
{
private:
    int hours;
    int minutes;
    int seconds;

public:
    /* Direct initialization using initializer list */
    Time() : hours(0), minutes(0), seconds(0) {}

    Time(int h, int m, int s) : hours(h), minutes(m), seconds(s)
    {
        normalize();
    }

    /* Display function in 11:59:59 format*/
    void display() const
    {
        std::cout << std::setfill('0') << std::setw(2) << hours << ":"
                  << std::setfill('0') << std::setw(2) << minutes << ":"
                  << std::setfill('0') << std::setw(2) << seconds << std::endl;
    }

    /* Adding to const instatnce*/
    void add(const Time &t1, const Time &t2)
    {
        hours = t1.hours + t2.hours;
        minutes = t1.minutes + t2.minutes;
        seconds = t1.seconds + t2.seconds;
        normalize();
    }

private:
    /* Normalize the time (ex. 75 seconds becomes:-> 00:01:15)*/
    void normalize()
    {
        if (seconds >= 60)
        {
            minutes += seconds / 60;
            seconds %= 60;
        }
        if (minutes >= 60)
        {
            hours += minutes / 60;
            minutes %= 60;
        }

        /* case 24 hours formating*/
        if (hours >= 24)
        {
            hours %= 24;
        }
    }
};

int main()
{
    const Time t1(11, 59, 59);
    const Time t2(0, 0, 1);
    Time t3;

    std::cout << "Time 1: ";
    t1.display();

    std::cout << "Time 2: ";
    t2.display();

    t3.add(t1, t2);

    std::cout << "Time 3 after adding Time 1 and Time 2: ";
    t3.display();

    return 0;
}
