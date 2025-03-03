#include"cat.h"

// unique_ptr 是一个独占所有权的智能指针，
// 它禁止拷贝和赋值操作，从而保证了资源的独占性。
// unique_ptr 通过移动语义std::move()来转移所有权，从而避免了资源的拷贝和传递。
// unique_ptr 适用于需要独占资源的场景，
// 如管理文件句柄、数据库连接等。



void do_with_cat(const unique_ptr<Cat> &cat)//引用传递
{
    cat->speak();
    cat->names = "Mimi";
}
void do_with_cat_ref(const unique_ptr<Cat> cat)//值传递
{
    cat->speak();
    //cat.reset();
}
int main()
{
    // //不好用
    // Cat *cat=new Cat("Tom");//创建一个Cat对象,指针
    // unique_ptr<Cat> cat1(cat);//创建一个unique_ptr对象,指向Cat对象
    // delete cat;//释放内存,使得cat1成为唯一指向Cat对象的指针

    // unique_ptr<Cat> cat1(new Cat("Tom"));
    // 创建一个unique_ptr对象,需要分配内存
    // new cat返回一个指向Cat对象的指针

    // 推荐
    unique_ptr<Cat> cat1 = make_unique<Cat>();
    // 创建一个unique_ptr对象,不需要分配内存
    // make_unique返回一个unique_ptr对象
    cout << "cat is address: " << cat1.get() << endl;
    cat1->speak();
    unique_ptr<Cat> cat2 = move(cat1); // 转移所有权
    cat2->speak();
    cout<<"cat1 is address: "<<cat1.get()<<endl;
    //cat1已经释放资源,不能再使用
    cout<<"cat2 is address: "<<cat2.get()<<endl;

    const unique_ptr<Cat> cat3 =move(cat2);
    //cat3.reset();//const对象不能释放资源
    cout<<"cat3 is address: "<<cat3.get()<<endl;
    cat2.reset(); // 释放资源
    cout<<"cat2 is address: "<<cat2.get()<<endl;
    cout<<"cat3 is address: "<<cat3.get()<<endl;
    //cat2->speak();//cat2已经释放资源,不能再使用
    cat3->speak();//cat3可以使用
    unique_ptr<Cat> cat4 = make_unique<Cat>("Tom");
    cout<<cat4->names<<endl;
    do_with_cat(cat4);//引用传递,不会释放资源
    cout<<cat4->names<<endl;
    cout<<"cat4 is address: "<<cat4.get()<<endl;
    do_with_cat_ref(move(cat4));
    //只是向修改cat4中的值,不会转移所有权
    cout<<"cat4 is address: "<<cat4.get()<<endl;
    //do_with_cat_ref(cat4);//值传递,会释放资源
    
    return 0;
}