#include"cat.cpp"
//#include"cat.cpp"


unique_ptr<Cat> get_unique_cat()
{
    unique_ptr<Cat> cat = make_unique<Cat>("Tom");
    return cat;
}

int main()
{
    //unique_ptr->shared_ptr

    std::unique_ptr<Cat> cat1 = make_unique<Cat>("Tom");
    cout << "cat1 is address: " << cat1.get() << endl;
    std::shared_ptr<Cat> cat2 = move(cat1);
    cout << "cat1 is address: " << cat1.get() << endl;
    cout << "cat2 is address: " << cat2.get() << endl;

    //shared_ptr->unique_ptr using func
    std::shared_ptr<Cat> cat3 = get_unique_cat(); 
    cout << "cat3 is address: " << cat3.get() << endl;


    return 0;
    

}