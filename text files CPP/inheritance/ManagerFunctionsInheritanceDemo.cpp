#include <iostream>

using namespace std;

class Base
{
    public:
        Base()
        {
            cout<<"\nDefault base constructor called";
        }
        Base(int a)
        {
            cout<<"\nParameterized base constructor with 1 parameter called";
        }
        Base(int a, int b)
        {
            cout<<"\nParameterized base constructor with 2 parameters called";
        }
        Base(const Base& b)
        {
            cout<<"\nBase Copy constructor called";
        }
};

class Derived: public Base
{
    public:
        Derived() 
        {
            cout<<"\nDefault derived constructor called";
        }
        Derived(int a)
        {
            cout<<"\nParameterized derived constructor with 1 parameter called";
        }
        Derived(const Derived& d) 
        {
            cout<<"\nDerived Copy constructor called";
        }
};

int main()
{
    Derived d1;
    Derived d2(d1);
}




/*class Polygon
{
    protected:
        double area;
        double perimeter;
    public:
        Polygon(double a, double p)
        {
            cout<<"\nbase constructor called";
            area = a;
            perimeter = p;
        }
    
};

class Triangle : public Polygon
{
    private:
        double sideA,sideB,sideC;
        
    public:
        Triangle() : Polygon(0.0,0.0)
        {
            cout<<"\nTriangle constr called";
        }
        Triangle(double a, double b, double c, double area = 0.0, double peri = 0.0) : Polygon(area, peri)
        {
            cout<<"\nChild constructor called";
        }
};

int main()
{
    Triangle t1;
    //Triangle t2(4,5,6,2.1,4.1);
}*/