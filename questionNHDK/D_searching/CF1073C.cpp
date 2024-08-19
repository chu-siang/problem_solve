#include <bits/stdc++.h>

using namespace std;

const int N = int(1e5) + 9;

string s;
int n;
int x, y;

void upd(pair<int, int> &pos, char mv, int d){
	if(mv == 'U')
		pos.second += d;
	if(mv == 'D')
		pos.second -= d;
	if(mv == 'L')
		pos.first -= d;
	if(mv == 'R')
		pos.first += d;
}

bool can(pair<int, int> u, pair<int, int> v, int len){
	int d = abs(u.first - v.first) + abs(u.second - v.second);
	if(d % 2 != len % 2) return false;
	return len >= d;
}

bool ok(int len){
	pair<int, int> pos = make_pair(0, 0);
	for(int i = len; i < n; ++i)
		upd(pos, s[i], 1);

	int l = 0, r = len;
	while(true){
		if(can(pos, make_pair(x, y), len))
			return true;
		
		if(r == n) break;
		upd(pos, s[l++], 1);
		upd(pos, s[r++], -1);		
	}
	
	return false;
}

int main() {
	//freopen("input.txt", "r", stdin);
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin >> n;
	cin >> s;
	cin >> x >> y;
	
	if(!ok(n)){
		puts("-1");
		return 0;
	}
	
	int l = 0, r = n;
	while( r > l){
		int mid = (l + r) / 2;
		if(ok(mid)) r = mid;
		else l = mid+1;
	}
	
	cout << l << '\n';
    return 0;
}