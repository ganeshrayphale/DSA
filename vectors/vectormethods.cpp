#include<iostream>
#include<vector>
using namespace std;
int main(){
vector <int> vec={4,5};
cout<<vec[0]<<endl;
cout<<vec[1]<<endl;
cout<<vec[2];
cout<<&(*vec.begin());

}