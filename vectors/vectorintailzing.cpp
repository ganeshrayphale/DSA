#include<iostream>
#include<vector>
using namespace std;

int main(){
vector <int> vec;

cout<<vec.size()<<endl;
vec.push_back(10);

cout<<vec.size()<<endl;
vec.push_back(100);

cout<<vec.size()<<endl;
vec.push_back(1000);

cout<<vec.size()<<endl;
vec.push_back(10);

cout<<vec.size()<<endl;
vec.push_back(10);

cout<<vec.size()<<endl;

for(int val :vec){
    cout<<val<<endl;
}
return 0;
}