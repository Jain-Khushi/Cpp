#include<iostream>
using namespace std;
#define TR 8.50
int main()
{
    float items,price,discount,subtotal,discount_amt,discount_total,total_sale;
    cout<<"Enter number of items sold :"; 
    cin>>items;
    cout<<"Enter the unit price :";
    cin>>price;
    cout<<"Enter the discount rate (percent) :";
     cin>>discount;
    subtotal=items*price;
    discount_amt=(7*subtotal)/100;
    discount_total=subtotal-discount_amt;
    total_sale=discount_total+TR;
    cout<<"Subtotal :"<<subtotal<<endl;
    cout<<"Discount :"<<discount_amt<<endl;
    cout<<"Discounted total :"<<discount_total<<endl;
    cout<<"Sales tax :"<<TR<<endl;
    cout<<"Total sale :"<<total_sale<<endl;
    return 0;
}