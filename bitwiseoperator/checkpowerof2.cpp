#include<iostream>
using namespace std;

int main(){
int n=32;
bool flag = false;
while (n!=0)
{
   int remaninder=n%2;
   n=n/2;
   if(remaninder==1 && n!=0){
    flag=true;
     break;
    
   }

}
if(flag==false){
    cout<<"yes number is in power of 2";

}
else{
    cout<<"number is not in power of 2";
}
}