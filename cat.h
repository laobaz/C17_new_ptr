#ifndef CAT_H
#define CAT_H
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
    std::shared_ptr<Cat> cat_friend;
    std::weak_ptr<Cat> cat_weak;//使用weak_ptr解决循环引用问题
    void set_friend(std::shared_ptr<Cat> cat);
    void set_weak(std::weak_ptr<Cat> cat);
};

#endif

