#include<iostream> 
using namespace std; 

class Fraction
{
    private:
        int numerator;
        int denominator;
    public:
        //Constructors
        Fraction();
        Fraction(int);
        Fraction(int,int);
        
        //Copy Constructor
        Fraction(const Fraction&);
        
        //Destructor
        ~Fraction();
        
        //Accessors and mutators
        void print() const;
        void store(int,int);
        
        //Overloaded prefix increment operator
        void operator++();
        
        //Overload postfix increment operator
        Fraction operator++(int);
        
        //Overload += operator
        Fraction operator+=(const Fraction&);
        
        //Overload + operator
        Fraction operator+(const Fraction&);
        
        //Overload <= operator
        bool operator<=(const Fraction&);
        
        //Overload assignment operator
        Fraction operator=(const Fraction&);
        
        //Conversion operator
        operator float();
};

//Default constructor
Fraction::Fraction()
{
    numerator = 0;
    denominator = 1;
}

//Single parameter constructor
Fraction::Fraction(int numer)
{
    numerator = numer;
    denominator = 1;
}

//Double parameter constructor
Fraction::Fraction(int numer, int denom)
{
    numerator = numer;
    denominator = denom;
}

//Copy constructor
Fraction::Fraction(const Fraction& fr)
{
    numerator = fr.numerator;
    denominator = fr.denominator;
}

//Destructor
Fraction::~Fraction()
{
    
}

//Accessor function
void Fraction::print() const
{
    cout<<numerator<<" / "<<denominator;
}

//Mutator function
void Fraction::store(int numer, int denom)
{
    numerator = numer;
    denominator = denom;
}

//Overloading prefix increment operator
void Fraction::operator++()
{
    numerator += denominator;
}

//Overloading postfix increment operator
Fraction Fraction::operator++(int a)
{
    Fraction obj(*this); //calling copy Constructor
    numerator += denominator;
    return obj;
}

//Overloading compound assignment operator
Fraction Fraction::operator+=(const Fraction& fr2)
{
    numerator = (numerator * fr2.denominator) + (fr2.numerator * denominator);
    denominator = denominator * fr2.denominator;
    return (*this);
}

//Overloading addition operator
Fraction Fraction::operator+(const Fraction& fr2)
{
    int numer = (numerator * fr2.denominator) + (fr2.numerator * denominator);
    int denom = denominator * fr2.denominator;
    return Fraction(numer,denom);
}

//Overloading <= operator
bool Fraction::operator<=(const Fraction& fr2)
{
    return (numerator*fr2.denominator <= denominator*fr2.numerator);
}

//Overloading assignment operator
Fraction Fraction::operator=(const Fraction& fr)
{
    numerator = fr.numerator;
    denominator = fr.denominator;
    return (*this);
}

//Overloading Conversion operator
Fraction::operator float() 
{
    return static_cast<float>(numerator)/denominator;
}

//Driver function to test code
int main()
{
    Fraction fr1(1,5);
    ++fr1;  //Equivalent to writing fr1.operator++();
    cout<<"Incremented Fr1: ";
    fr1.print();
    
    Fraction fr2(3,7);
    fr2 = fr1++; //Equivalent to writing fr1.operator++(a) where a is any int variable
    cout<<"\nIncremented Fr1: ";
    fr1.print();
    cout<<"\nFr2: ";
    fr2.print();
   
    fr1 += fr2; //Equivalent to writing fr1.operator+=(fr2);
    cout<<"\nAdded Fr1: ";
    fr1.print();
    cout<<"\nFr2: ";
    fr2.print();
    
    Fraction fr3;
    fr3 = fr1 + fr2; //Equivalent to writing fr1.operator+(fr2);
    cout<<"\nAdded Fr3: ";
    fr3.print();
    
    cout<<"\nIs fr1<= fr3? "<<(fr1<=fr3);
    
    Fraction fr4;
    fr4 = fr2 = fr1;
    cout<<"\nAssigned Fr3: ";
    fr4.print();
    cout<<"\nAssigned Fr2: ";
    fr2.print();
    cout<<"\nFr1: ";
    fr1.print();
    
    Fraction fr5 = 5.5;
    cout<<"\nFr5: ";
    fr5.print();
    
    
    float fr = fr1;
    cout<<"\nFloat fraction fr: "<<fr;
}