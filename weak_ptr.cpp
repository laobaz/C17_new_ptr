#include "cat.cpp"

int main()
{
    std::shared_ptr<Cat> s_cat_1 = make_shared<Cat>("Tom");
    std::weak_ptr<Cat> w_cat_2 = s_cat_1;

    cout << "s_cat_1 is address: " << s_cat_1.get() << endl;
    // 弱链接不会增加引用计数
    // w_cat_2->speak();不要这样使用，因为w_cat_2可能已经释放资源
    cout << "w_cat_2 is using count: " << w_cat_2.use_count() << endl;
    cout << "s_cat_1 is using count: " << s_cat_1.use_count() << endl;
    cout << "w_cat_2 is address: " << w_cat_2.lock().get() << endl;

    shared_ptr<Cat> s_cat_2 = make_shared<Cat>("Mimi");
    shared_ptr<Cat> s_cat_3 = make_shared<Cat>("Mimi1");
    weak_ptr<Cat> w_cat_3 = s_cat_3;
    weak_ptr<Cat> w_cat_2_1 = s_cat_2;
    // s_cat_2->set_friend(s_cat_3);
    // s_cat_3->set_friend(s_cat_2);
    // 相互设置为朋友，这样就会形成循环引用，导致内存泄漏
    // 解决方法是使用weak_ptr
    // weak_ptr是一种不控制所指向对象生存周期的智能指针，它指向一个shared_ptr管理的对象。
    // 将weak_ptr转换为shared_ptr需要调用lock()函数，
    // 如果weak_ptr指向的对象已经释放，则lock()函数会返回一个空指针。
    s_cat_2->set_weak(w_cat_3);
    s_cat_3->set_weak(w_cat_2_1);
    
    return 0;
}