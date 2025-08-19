#include<iostream>
#include<string>
using namespace std;
int reverse(int n){
string num;
    while (n!=0)
    {
        int remainder=n%10;
        num=num+to_string(remainder);
        n=n/10;
    }
   
    return stoi(num);
}
int main(){
int n=562959;
cout<<"the integer is :"<<n<<endl;
cout<<"the reverse  is :"<<reverse(n)<<endl;
}

