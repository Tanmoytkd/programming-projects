#ifndef BIRTHDAY_H
#define BIRTHDAY_H


class Birthday
{
    public:
        Birthday();
        Birthday(int d, int m, int y);
        int date();
        int month();
        int year();
    protected:
    private:
        const int itsDate, itsMonth, itsYear;
};

#endif // BIRTHDAY_H
