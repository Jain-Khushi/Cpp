#include <iostream>

using namespace std;

class StaticDemo
{
    private:
        int x;
        
        
    public:
        static int counter;
        StaticDemo();
        ~StaticDemo();
        void nonStaticPrintCount();
        static void staticPrintCount();
};

int StaticDemo::counter = 0;

StaticDemo::StaticDemo()
{
    x = 0;
    counter++;
}

StaticDemo::~StaticDemo()
{
    counter--;
}

void StaticDemo::nonStaticPrintCount() 
{
    //Non-static member functions can access both static and non-static member data
    cout<<"\nCounter value: "<<counter;
    cout<<"\nx: "<<x;
}

void StaticDemo::staticPrintCount() 
{
    //Static member functions can only access static member data
    cout<<"\nCounter value: "<<counter;
    /*cout<<"\nx: "<<x;*/  //This line won't compile
}


int main()
{
    StaticDemo s1;
    s1.nonStaticPrintCount(); //printing counter using non-static function
    
    cout<<endl<<StaticDemo::counter;
    cout<<endl<<s1.counter; //This works
    
    
    StaticDemo::staticPrintCount(); //printing counter using static function
    
    s1.staticPrintCount();  //This also works
    
    return 0;
}
