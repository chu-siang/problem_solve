#include<iostream>
#include<cmath>
using namespace std;

int main(){
    int n;
    cin >> n;
    while(n--){
        long long sum;
        cin >> sum;
        cout <<(sum+1)*(sum+1)-1<<'\n';
    }
}