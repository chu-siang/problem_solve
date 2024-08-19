#include<iostream>
#include<utility>
#include<algorithm>
#define MAXN 1005
using namespace std;
int n;
pair<int, int> p[MAXN];

int main() {
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> p[i].first >> p[i].second;
    sort(p, p + n);

    for (int i = 0; i < n; i++)
        cout << p[i].first << " " << p[i].second << endl;
}