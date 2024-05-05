#include<bits/stdc++.h>
#define ll long long
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        int count = 0;
        int arr[55];
        for(int i = 0; i < n; i++)cin >> arr[i];
        for(int i = 0; i < n - 1; i++){
            for(int j = 1; j < n - i; j++){
                if(arr[j] < arr[j - 1]) {
                    swap(arr[j],arr[j-1]);
                    count++;
                }
            }
        }
        cout<< "Optimal train swapping takes " << count << " swaps.\n";
    }

    return 0;
}