#include<bits/stdc++.h>
#define ll long long
using namespace std;

int main(){
    int n, k;
    cin >> n >> k;
    set<pair<int, int>> leftset;
    set<pair<int, int>> rightset;

    vector<int>values(n);
    for(int i = 0; i < n; i++){
        cin >> values[i];
    }

    if(k ==  1){// 成本 = 0(自己-自己)
        for(int i = 0; i < n; i++){
            cout << "0 ";
        }
        return 0;
    }
    if(k == 2){// 成本 = 互減
        for(int i = 1; i < n; i++){
            cout << abs(values[i]-values[i-1]) << ' ';
        }
        return 0;
    }
    vector<pair<int ,int>> st;
    for(int i = 0; i < k; i++){
        //st.push_back({values[i],i});
        st.emplace_back(values[i],i);
    }
    sort(st.begin(),st.end());//集合中排列 2 4 3 變  2 3 4
    ll leftSetsum = 0;
    ll rightSetsum = 0;
    for(int i = 0; i < k/2 + (k%2); i++){
        leftset.insert(st[i]);
        leftSetsum += st[i].first;
    }
    for(int i = k/2 + (k%2); i < k; i++){
        rightset.insert(st[i]);
        rightSetsum += st[i].first;
    }
    ll median = leftset.rbegin()->first;
    cout << median * leftset.size() - leftSetsum + rightSetsum - median * rightset.size() <<" ";

    for(int j = 1; j < n - k + 1; j++){
        if(leftset.count({values[j-1], j-1})){
            leftSetsum -= values[j-1];
            leftset.erase({values[j-1], j-1});
        }
        else{
            rightSetsum -= values[j-1];
            rightset.erase({values[j-1], j-1});
        }
        if(leftset.rbegin()->first < values[k-1 + j]){ // if(*(leftset.rbegin()) < make_pair(values[k-1+j],j-1)))
            rightSetsum += values[k-1 + j];
            rightset.emplace(values[k-1 +j],k-1+j);
        }
        else{
            leftSetsum += values[k-1 + j];
            leftset.insert({values[k-1 + j], k-1+j});
        }
        while(leftset.size() < k / 2 + (k % 2)){
            pair<int, int> p = *(rightset.begin());
            leftSetsum += p.first;
            leftset.insert(p);
            rightSetsum -= p.first;
            rightset.erase(p);
        }
        while(leftset.size() > k / 2 + (k % 2)){
            pair<int, int> p = *(leftset.rbegin());
            rightSetsum += p.first;
            rightset.insert(p);           
            leftSetsum -= p.first;
            leftset.erase(p);
        }
        median = leftset.rbegin()->first;
        cout << median * leftset.size() - leftSetsum + rightSetsum - median * rightset.size() << " ";
    } 
    return 0;
}