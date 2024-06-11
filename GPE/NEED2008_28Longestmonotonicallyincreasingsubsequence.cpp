#include<bits/stdc++.h>
#define int long long
using namespace std;
const int MAXN = 100;
int s[MAXN];
int length[MAXN];
int N,l;
vector<vector<int>>ans;
// 遞迴版本
void print_LIS(int i,vector<int>tmp){
	if (length[i] == l) {
        tmp.push_back(s[i]);
        if(tmp.size() == l)ans.push_back(tmp);
        return ;
    }
	for (int j = i; j < N; ++j)
		if (s[i] < s[j]){
			if (length[i] + 1 == length[j]){
                tmp.push_back(s[i]);
				print_LIS(j,tmp);
                tmp.pop_back();
            }
        }
}

void LIS(){
	for (int i=0; i<N; i++) length[i] = 1;
	for (int i=0; i<N; i++)
		for (int j=i+1; j<N; j++)
			if (s[i] < s[j])
				length[j] = max(length[j], length[i] + 1);
	l = 0;
	for (int i=0; i<N; i++)
		if (length[i] > l)
			l = length[i];
    vector<int>tmp;
	for (int i=0; i<N; i++){
        if(length[i] == 1)print_LIS(i,tmp);
    }
}
signed main(){
    int t;
    cin >> t;
    while(t--){
        cin >> N;
        for(int i = 0; i < N; i++)cin >> s[i];
        ans.clear();
        LIS();
        cout << ans.size() << '\n';
        for(auto i:ans){
            for(int j = 0; j < i.size(); j++){
                cout << i[j] << " \n"[j == i.size()-1];
            }
        }
    }
}