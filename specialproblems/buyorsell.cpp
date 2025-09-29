#include<iostream>
using namespace std;
int buytime(int arr[]){
    int profit=0;
    int maxprofit=0;
    int besttime=arr[0];

    for(int i=1;i<6;i++){
        if(besttime>arr[i]){
            besttime=arr[i];
        }

        if((arr[i]-besttime)>maxprofit){
            maxprofit=arr[i]-besttime;
        }
    }
    return maxprofit;

}

int main(){
   int  arr[6]={7,1,5,3,6,4};
   cout<<buytime(arr);

}