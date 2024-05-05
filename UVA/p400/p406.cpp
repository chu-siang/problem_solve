#include<bits/stdc++.h>
#define ll long long
using namespace std;

bool f(int n){
	if(n == 1 || n == 2)return true;
	for(int i = 2; i*i<= n; i++){
		if(n%i == 0)return false;
	}
	return true;
}


int main(){
	ll n,c;
	while(cin >> n >> c){
		vector<ll>v;
		ll cnt = 0;
		for(int i = 1; i <= n; i++){
			if(f(i))v.push_back(i),cnt++;
		}
		sort(v.begin(),v.end());
		cout << n <<' ' <<c<<":";
		if(c >= (cnt+1)/2) c = (cnt+1)/2;
        ll mid = cnt/2;
		if(cnt&1){
			c--;
			for(int i = mid - c; i <= mid + c;i++)cout <<' ' <<v[i];
		}else{
			for(int i = mid - c; i <= mid +c -1; i++)cout << ' ' <<v[i];
		}
		cout << '\n' << '\n';
	}
} 
