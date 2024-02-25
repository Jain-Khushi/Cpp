#include<iostream>
#include<cmath>
using namespace std;
int main()
{
     float sub1,sub2,sub3,sub4,avg,dev1,dev2,dev3,dev4;
     cout<<"Enter marks of 4 subjects";
     cin>>sub1>>sub2>>sub3>>sub4;
     avg=(sub1+sub2+sub3+sub4)/4;
     dev1=fabs(sub1-avg);
     dev2=fabs(sub2-avg);
     dev3=fabs(sub3-avg);
     dev4=fabs(sub4-avg);
    cout<<"The average is :"<<avg<<endl;
    cout<<"The deviations are:"<<dev1<<dev2<<dev3<<dev4;
    return 0;
}