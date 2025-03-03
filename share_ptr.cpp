#include"cat.h"

int main(){
    shared_ptr<int> p1(new int(10));
    shared_ptr<int> p2 = p1;
    shared_ptr<int> p3 =make_shared<int>(20);
    cout<<"p1 is num:"<<*p1<<endl;
    cout<<"p2 is num:"<<*p2<<endl;
    cout<<"p1 is using count:"<<p1.use_count()<<endl;
    cout<<"p2 is using count:"<<p2.use_count()<<endl;

    *p2 = 30;
    cout<<"p1 is num:"<<*p1<<endl;
    p3=p1;//p3指向p1指向的内存,并且p1的引用计数加1,p3的引用计数减1
    cout<<"p1 is using count:"<<p1.use_count()<<endl;
    cout<<"p3 is using count:"<<p3.use_count()<<endl;
    //释放p1
    p1=nullptr;
    cout<<"p1 is using count:"<<p1.use_count()<<endl;
    cout<<"p2 is using count:"<<p2.use_count()<<endl;
    cout<<"p3 is using count:"<<p3.use_count()<<endl;
    //shared_ptr<int> p4 = new int(10);//不能直接赋值
    //只看最后一个shared_ptr对象是否释放资源


    







    return 0;







    

}