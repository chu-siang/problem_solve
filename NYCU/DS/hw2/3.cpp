#include<bits/stdc++.h> 
#define int long long 
using namespace std; 
const int MAXN = 5e7+5; 
int a[MAXN];
map<signed,signed>cnt; 
signed main(){ 
    ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0); 
    int n,sum = 0,ans = 0; 
    cin >> n; 
    for(int i = 0; i < n; i++)cin >> a[i];  
    stack<int>st; 
    st.push(a[0]);
    cnt[a[0]]++;
    for(int i = 1; i < n; i++){
        if(a[i] == st.top()){ 
            ans += cnt[a[i]];
            if(cnt[a[i]] != st.size())ans++;
        }else if(a[i] > st.top()){
            while(st.size() && (a[i] > st.top())){
                ans++;
                cnt[st.top()]--;
                st.pop();
            }
            if(st.size() && (a[i] < st.top()))ans++;
            else if(st.size() && (a[i] == st.top())){
                ans += cnt[a[i]];
                if(cnt[a[i]] != st.size())ans++;
            }
        }else{
            ans++;
        }
        cnt[a[i]]++;
        st.push(a[i]);
    } 
    cout << ans << '\n'; 
}  
/*#include<bits/stdc++.h> 
#define int long long 
using namespace std; 
const int MAXN = 5e5+5; 
int a[MAXN],f[MAXN]; 
signed main(){ 
    ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0); 
    int n,sum = 0,ans = 0; 
    cin >> n; 
    for(int i = 0; i < n; i++)cin >> a[i]; 
    for(int i = 1; i <= 50000; i++)f[i] = (i-1 + f[i-1]); 
    stack<int>st; 
    st.push(a[0]); 
    for(int i = 1; i < n; i++){ 
        if(st.size() && a[i] > st.top()){ 
            int tmp = -2,cnt = 1; 
            while(st.size() && a[i] != st.top()){ 
                ans++; 
                if(a[i] < st.top()){ 
                    ans += (cnt-1 + f[cnt]); 
                    cnt = 1; 
                    break; 
                } 
                if(st.top() == tmp){ 
                    cnt++; 
                }else{ 
                    ans+=(cnt-1 + f[cnt]); 
                    cnt = 1; 
                } 
                tmp = st.top(); 
                st.pop(); 
            } 
            if(cnt > 1 && st.empty()){ 
                ans += f[cnt]; 
            }else if(st.size()&&a[i] == st.top() && cnt > 1){ 
                ans += cnt-1 + f[cnt]; 
            }  
        }else if(a[i]!=st.top())ans++; 
        st.push(a[i]); 
    } 
    int cnt = 1; 
    if(st.size()){ 
        int tmp = st.top(); 
        st.pop(); 
        while(st.size()){ 
            if(tmp == st.top()){ 
                cnt++; 
            }else{ 
                ans += (cnt-1 + f[cnt]); 
                cnt = 1; 
            } 
            tmp = st.top(); 
            st.pop(); 
        } 
        if(cnt > 1)ans += (f[cnt]); 
    } 
    cout << ans << '\n'; 
}  
*/