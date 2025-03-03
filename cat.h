#include<iostream>
#include<memory>
using namespace std;
#include<string>


class Cat
{
private:
    /* data */
public:
    Cat(/* args */);
    Cat(string name);
    void speak();
    virtual void eat() = 0;
    ~Cat();
    string names = "cat";
};


