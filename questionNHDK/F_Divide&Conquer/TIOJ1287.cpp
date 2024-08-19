#include <bits/stdc++.h>
using namespace std;
//常數較小版本
vector<int> arr;

void mergesort(int l, int r) {

	// 邊界條件：陣列長度等於 1
	if (l == r) return;

	// 遞迴排序左半邊跟右半邊
	int mid = (l+r)/2;
	mergesort(l, mid);
	mergesort(mid+1, r);

	// 合併左右兩半邊
	vector<int> sorted;
	int Lptr = l, Rptr = mid+1;

	while (Lptr <= mid && Rptr <= r) {
		
		if (arr[Lptr] < arr[Rptr]) {
			sorted.push_back(arr[Lptr]);
			Lptr++;

		} else {
			sorted.push_back(arr[Rptr]);
			Rptr++;

		}

	}

	while (Lptr <= mid) {
		sorted.push_back(arr[Lptr]);
		Lptr++;
	}
	while (Rptr <= r) {
		sorted.push_back(arr[Rptr]);
		Rptr++;
	}

	for (int i = l, j = 0; i <= r; i++, j++) {
		arr[i] = sorted[j];
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n;
	while (cin >> n) {
		arr.clear(); arr.resize(n);
		for (auto& i : arr) cin >> i;
		mergesort(0, n-1);
		for (auto& i : arr) cout << i << ' ';
		cout << endl;
	}

	return 0;
}

/*#include<bits/stdc++.h>
#define int long long
using namespace std;


vector<int> mergesort(vector<int>v){
    int len = v.size();
    if(len == 1)return v;
    int mid = len/2;
    vector<int>left,right;
    for(int i = 0; i < len; i++){
        if(i < mid)left.push_back(v[i]);
        else right.push_back(v[i]);
    }
    left  = mergesort(left);
    right = mergesort(right);
    vector<int>sorted;
    int lptr = 0, rptr = 0;
    while(lptr < (int)left.size() && rptr < (int)right.size()){
        if(left[lptr] < right[rptr])sorted.push_back(left[lptr++]);
        else sorted.push_back(right[rptr++]);
    }
    while(lptr < (int)left.size())sorted.push_back(left[lptr++]);
    while(rptr < (int)right.size())sorted.push_back(right[rptr++]);
    return sorted;
}

signed main(){
    ios_base::sync_with_stdio(false);
	cin.tie(0);
    int n;
    while(cin >> n){
        vector<int>v(n);
        for(int i = 0; i < n; i++)cin >>v[i];
        v = mergesort(v);
        for(int i = 0; i < n; i++)cout << v[i] << " \n"[i==n-1];
        v.clear();
    }
}
*/