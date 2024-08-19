#include <bits/stdc++.h>
 
using namespace std;
using ll = long long;
 
#define mirusort ios_base::sync_with_stdio(0);cin.tie(0);
int arr[5], num, n, t, a[5], b[5];
 
void array_to_num(){
    num = 0;
    for (int i = n - 1; i >= 0; i--){
        num *= 51;
        num += a[i];
    }
}
 
void num_to_array(){
    for (int i = 0; i < n; i++){
        a[i] = num % 51;
        num /= 51;
    }
}
 
int main(){
    mirusort
    cin >> n;
    set<int> cnt;
    for(int i = 0; i < n; ++i)
        cin >> arr[i];
    cin >> t;
    int gcd = arr[0];
    for(int i = 1; i < n; ++i)
        gcd = __gcd(gcd, arr[i]);
    if(t % gcd || *max_element(arr, arr + n) < t){
        cout << "-1\n";
        return 0;
    }
    queue<pair<int, int>> q;
    q.push({0, 0});
    array_to_num();
    cnt.insert(0);
    while(!q.empty()){
        pair<int, int> cur = q.front();
        q.pop();
        num = cur.second;
        num_to_array();
        for(int i = 0; i < n; ++i)
            b[i] = a[i];
        for(int i = 0; i < n; ++i){
            for(int j = 0; j < n; ++j){
                if(i == j){
                    if(b[i] < arr[i]){
                        for(int k = 0; k < n; ++k)
                            a[k] = b[k];
                        a[i] = arr[i];
                        array_to_num();
                        if(cnt.find(num) == cnt.end()){
                            if(a[i] == t){
                                printf("%d", cur.first + 1);
                                return 0;
                            }
                            q.push({cur.first + 1, num});
                            cnt.insert(num);
                        }
                    }
                    if(b[i] > 0){
                        for(int k = 0; k < n; ++k)
                            a[k] = b[k];
                        a[i] = 0;
                        array_to_num();
                        if (cnt.find(num) == cnt.end()){
                            if(a[i] == t){
                                printf("%d", cur.first + 1);
                                return 0;
                            }
                            q.push({cur.first + 1, num});
                            cnt.insert(num);
                        }
                    }
                }
                else{
                    int l = min(b[i], arr[j] - b[j]);
                    if(l > 0){
                        for(int k = 0; k < n; ++k)
                            a[k] = b[k];
                        a[i] -= l;
                        a[j] += l;
                        array_to_num();
                        if(cnt.find(num) == cnt.end()){
                            if(a[i] == t || a[j] == t){
                                printf("%d", cur.first + 1);
                                return 0;
                            }
                            q.push({cur.first + 1, num});
                            cnt.insert(num);
                        }
                    }
                }
            }
        }
    }
    return 0;
}