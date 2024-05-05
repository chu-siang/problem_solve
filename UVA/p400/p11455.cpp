#include<iostream>
#include<algorithm>
using namespace std;

int main(){
    int arr[5];
    int n;
    cin >> n;
    while(n--){
        for(int i = 1; i <= 4; i++) cin >> arr[i];
        sort(arr + 1, arr + 5);
        if(arr[1] == 0 || arr[4] >= arr[1] + arr[2] + arr[3]) cout << "banana" ;
        else if(arr[1] == arr[2] && arr[2] == arr[3] && arr[3] == arr[4]) cout << "square";
        else if(arr[1]== arr[2] && arr[3] == arr[4]) cout << "rectangle";
        else cout << "quadrangle";
        cout << '\n';
    }
}