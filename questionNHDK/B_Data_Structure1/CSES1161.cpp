#include <iostream>
#include <queue>
using namespace std;


int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int x, n;
    cin >> x >> n;    

    priority_queue<int, vector<int>, greater<int>> pq;
    long long sum = 0;

    while(n--){
        int num;
        cin >> num;
        pq.emplace(num);
    }


    while(pq.size() >= 2){
        int tmp = 0;
        tmp += pq.top();
        pq.pop();
        tmp += pq.top();
        pq.pop();
        sum += tmp;
        pq.emplace(tmp);
    }

    cout << sum << '\n';
    return 0;
}

