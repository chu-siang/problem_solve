    #include<iostream>
    #include<vector>
    #include<algorithm>
    #define ll long long
    using namespace std;
    ll a[10][10];
    int main(){
        ll n, k, ans = 0;
        cin >> n >> k;
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= n; j++){
                cin >> a[i][j];
            }
        }
        vector<int>v (n+2);
        for(int i = 1; i <= n ; i++) v[i] = i;
        v[n+1] = 1;
        do{
            ll sum = 0;
            for(int i = 1; i <= n; i++){
                sum += a[v[i]][v[i+1]];
            }
            if(sum == k) ans++;
        }while(next_permutation(v.begin()+2,v.end()-1));
        cout << ans;
    }