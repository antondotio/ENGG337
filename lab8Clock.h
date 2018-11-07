
#ifndef lab8clock_h
#define lab8clock_h

class Clock{
public:
    Clock();
    Clock(int s);
    Clock(int h, int m, int s);

    int get_hour() const;
    void set_hour(int h);

    int get_minute() const;
    void set_minute(int m);

    int get_second() const;
    void set_second(int s);

    void increment();
    void decrement();
    void add_seconds(int s);

private:
    int hour;
    int minute;
    int second;

    int hms_to_sec();
    void sec_to_hms(int s);
};

#endif