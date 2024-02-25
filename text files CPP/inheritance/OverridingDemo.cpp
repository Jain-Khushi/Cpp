#include <iostream>

using namespace std;

class Parent
{
    private:
        int data;
        
    public:
        Parent(int d);
        void print() const;
};

Parent::Parent(int d)
{
    data = d;
}

void Parent::print() const
{
    cout<<"\nParent data: "<<data;
    return;
}

class Child: public Parent
{
    private:
        int childData;
    
    public:
        Child(int p, int c);
        void print() const;
};

Child::Child(int p, int c):Parent(p)
{
    childData = c;
}

void Child::print() const
{
    Parent::print();
    cout<<"\nChild data: "<<childData;
    return;
}

int main()
{
    Parent pObj(1);
    Child cObj(2,3);
    
    pObj.print();
    cObj.print();
    cObj.Parent::print(); //To access base class function using child object
    return 0;
}