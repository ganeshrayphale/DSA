#include<iostream>
using namespace std;
int main(){
int num=11010;
int ans=0,pow=1;
while (num!=0)
{
   int lastdigit=num%10;
   ans=ans+lastdigit*pow;

    num/=10;
    pow*=2;
}
cout<<ans;
}