#include<iostream>
#include<queue>
#include <cstdio>
#include <cstring>
using namespace std;
using namespace std;

deque< deque<int> > dq;
deque< deque<int> >::iterator it;
int team[1000005];


int main(void) {
	int t, n, element, x, i, cas = 1;
	string s;
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
	while(cin>>t && t) {
		memset(team, 0, sizeof(team));
		dq.clear();

		for(i = 1; i <= t; ++i) {
			cin>>n;
			while(n--) {
				cin>>element;
				team[element] = i;
			}
		}

		cout<<"Scenario #"<<cas++<<endl;
		while(cin>>s && s!= "STOP") {
			if(s== "ENQUEUE") {
				cin>> x;
				for(it = dq.begin(); it != dq.end(); ++it) {//it 到的那個deque  跟x同個team(deque) team[deque.front()]==team[x]
					if(team[it->front()] == team[x]) {
						(*it).push_back(x);
						break;
					}
				}
				if(it == dq.end()) {//沒有被定義在team裡 自己成為一個deque  double deque 新增都是新增 一個deque;
					deque<int> tmp;
					tmp.push_back(x);
					dq.push_back(tmp);
				}
			}
			else if(s=="DEQUEUE") {
				x = dq.front().front();//印出第一隊 第一個人
				if(dq.front().size() == 1) dq.pop_front();//剩一個人 把他pop調
				else dq.front().pop_front();
				cout<<x<<endl;
			}
		}
		cout<<endl;
	}
	return 0;
}
