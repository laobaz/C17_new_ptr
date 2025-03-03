#include"cat.h"


class Cat
{
public:
    Cat(string name) : names(name)
    {
        cout << "Cat " << name << " is created." << endl;
    }
    Cat()
    {
        cout << "Cat " << names << " is created." << endl;
    }
    ~Cat()
    {
        cout << "Cat " << names << " is destroyed." << endl;
    }
    void speak()
    {
        cout << "Cat " << names << " is speaking." << endl;
    }
    void eat()
    {
        cout << "Cat " << names << " is eating." << endl;
    }
    string names = "cat";
};