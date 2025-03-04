#include "cat.h"
//cat.cpp  中只需要实现类的成员函数即可
Cat::Cat(string name) : names(name)
{
    cout << "Cat " << name << " is created." << endl;
}
Cat::Cat()
{
    cout << "Cat " << names << " is created." << endl;
}
Cat::~Cat()
{
    cout << "Cat " << names << " is destroyed." << endl;
}
void Cat::speak()
{
    cout << "Cat " << names << " is speaking." << endl;
}
void Cat::eat()
{
    cout << "Cat " << names << " is eating." << endl;
}
void Cat::set_friend(std::shared_ptr<Cat> cat)
{
    cat_friend = cat;
}
void Cat::set_weak(std::weak_ptr<Cat> cat)
{
    this->cat_weak = cat;
}
