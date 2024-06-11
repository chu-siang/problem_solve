#include <iostream>
#include <unordered_map>
using namespace std;

int main() {
    int n;
    cin >> n;
    int a[n];
    unordered_map<int, int> hashMap;
    long long count = 0;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        count += hashMap[a[i] - i];
        hashMap[a[i] - i]++;
    }

    cout << count << endl;
    return 0;
}