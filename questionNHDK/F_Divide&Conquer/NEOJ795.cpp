#include<bits/stdc++.h>
#define int long long
using namespace std;

const int MAXN =2e5+5;
pair<int,int>p[MAXN];
int ans = 1e18;

int dis(pair<int,int>a,pair<int,int>b){
    int x = a.first - b.first;
    int y = a.second - b.second;
    return x*x + y*y;
}

void dfs(int l,int r){
    int n = r-l+1;
    if(n <= 20){
        for(int i = l; i < r; i++){
            for(int j = i + 1; j <= r; j++){
                ans = min(dis(p[i],p[j]),ans);
            }
        }
        return ;
    }
    int mid = l+r>>1;
    int ml = mid,mr = mid;
    int midx = p[mid].first;
    while(l <= ml && p[ml].first == midx)ml--;
    while(r >= mr && p[mr].first == midx)mr++;
    dfs(l,ml);
    dfs(mr,r);

    int d = sqrt(ans)+1;
    vector<pair<int,int>>tmp;
    for(int i = mid; i >= l; i--){
        if(abs(p[i].first - midx) <= d)tmp.push_back(p[i]);
        else break;
    }
    for(int i = mid; i <= r; i++){
        if(abs(p[i].first - midx) <= d)tmp.push_back(p[i]);
        else break;
    }
    sort(tmp.begin(),tmp.end(),[&] (pair<int,int>&a,pair<int,int>&b){
        return a.second < b.second;
    });
    int nt = (int)tmp.size();
    for(int i = 0; i < nt; i++){
        for(int j = i+1,cnt = 0; j < nt && cnt < 3; j++,cnt++){
            ans = min(dis(tmp[i],tmp[j]),ans);
        }
    }
    return;
}


signed main(){
    ios_base::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
    int N;
    cin >> N;
    for(int i = 0; i < N; i++){
        cin >> p[i].first >> p[i].second;
    }
    dfs(0,N-1);
    cout << ans << '\n';
}