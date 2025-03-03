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
    //virtual void eat() = 0;//纯虚函数
    void eat();
    ~Cat();
    string names = "cat";
};


