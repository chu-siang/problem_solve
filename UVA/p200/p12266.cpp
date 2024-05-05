//a106 uva12266
#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;

priority_queue<pair<int,int>,vector<pair<int,int>>>buy;
priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>sell;

int lastprice;
void print(){
    if(sell.empty())cout << "- ";
    else cout << sell.top().first << " ";
    if(buy.empty())cout << "- ";
    else cout << buy.top().first << " ";
    if(lastprice == -1)cout << "-\n";
    else cout << lastprice << '\n';
}


// vector + lower_bound
int main(){
    int t;
    cin >> t;
    int n;

    while(t--){
        cin >> n;
        while(!buy.empty()){buy.pop();}
        while(!sell.empty()){sell.pop();}
        lastprice = -1;
        for(int i = 1; i <= n; i++){
            string s1,s2,at;
            int num,id;
            cin >> s1 >> num >> s2 >> at >> id;
            if(s1 == "buy"){ 
                buy.push({id,num});
            }else{
                sell.push({id,num});
            }
            while(!sell.empty() && !buy.empty() && (sell.top().first <= buy.top().first)){
                pair<int,int> a = buy.top();
                pair<int,int> b = sell.top();
                buy.pop(),sell.pop();
                int mi = min(a.second,b.second);
                lastprice = b.first;
                a.second-=mi;
                b.second-=mi;
                
                if(a.second > 0)buy.push(a);
                if(b.second > 0)sell.push(b);
            }
            print();
        }
    }
}