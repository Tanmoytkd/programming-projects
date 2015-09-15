#ifndef PERSON_H
#define PERSON_H


class person
{
    public:
        person(int age);
        void printAge();
        ~person();
    protected:
    private:
        const int itsAge;
};

#endif // PERSON_H
