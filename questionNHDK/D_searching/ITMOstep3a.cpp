//pilot
#include <bits/stdc++.h>

using namespace std;
using ll = long long;

#define mirusort ios_base::sync_with_stdio(0);cin.tie(0);

int main()
{
    mirusort
    ll n, p, total = 0;
    cin >> n >> p;
    vector<ll> arr(2 * n + 1), sum(2 * n + 1, 0);
    for(int i = 1; i <= n; ++i)
    {
        cin >> arr[i];
        arr[i + n] = arr[i];
    }
    for(int i = 1; i <= 2 * n; ++i)
        sum[i] = sum[i - 1] + arr[i];
    if(sum[n] < p)
    {
        total += p / sum[n] * n;
        p %= sum[n];
    }
    ll ans = 1e9, idx = -1, l = 1;
    for(int r = 1; r <= 2 * n; ++r)
    {
        while(l <= r && sum[r] - sum[l] >= p)
            l++;
        if(sum[r] - sum[l - 1] >= p)
        {
            if(ans > r - l + 1)
            {
                ans = r - l + 1;
                idx = l;
            }
        }
    }
    if(idx > n)
        idx -= n;
    cout << idx << ' ' << total + ans << '\n';
    return 0;
}