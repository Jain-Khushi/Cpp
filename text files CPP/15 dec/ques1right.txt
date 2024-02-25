#include<iostream>
using namespace std;
int main()
{
     int num,digit;
     cout<<"Enter a number: ";
     cin>>num;
     digit=num%10;
     cout<<"The rightmost digit of the number is: "<<digit;
     return 0;
}