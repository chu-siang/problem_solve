/*考虑二分答案，假设二分的答案为mid

对于平均值，我们可以构造一个数组b[i]=a[i]-mid，如果选择出来的数的 ∑ b [ i ] > = 0 \sum{b[i]}>=0∑b[i]>=0，就说明平均值大于等于k，所以我们只需要求出满足条件的最大的 ∑ b [ i ] \sum{b[i]}∑b[i]来作为check的条件

对于中位数，如果选择出来的数中大于等于mid的数量大于数量的一半，则中位数大于等于mid，我们可以构造一个数组b[i] = a[i] >= mid ? 1 : -1，如果选择出来的数的 ∑ b [ i ] > = 0 \sum{b[i]}>=0∑b[i]>=0，就说明中位数大于等于mid，同意的我们只需要求出满足条件的最大的 ∑ b [ i ] \sum{b[i]}∑b[i]来作为check的条件

现在的问题转换成给定一个数组b[i]，需要满足相邻两项至少选择一项的条件下，最大的和是多少？

这就可以考虑dp了，dp[i][0]表示不选择i能产生的最大的和，dp[i][1]表示选择i能产生的最大的和

转移方程就很显然了：

d p [ i ] [ 0 ] = d p [ i − 1 ] [ 1 ] ; dp[i][0] = dp[i - 1][1];dp[i][0]=dp[i−1][1];

d p [ i ] [ 1 ] = m a x ( d p [ i − 1 ] [ 0 ] , d p [ i − 1 ] [ 1 ] ) + b [ i ] ; dp[i][1] = max(dp[i - 1][0], dp[i - 1][1]) + b[i];dp[i][1]=max(dp[i−1][0],dp[i−1][1])+b[i];

还有需要注意的是二分平均数的时候，l和r等都是double型的，结束的条件是while(r - l >= 1e-6)
————————————————
版权声明：本文为CSDN博主「Chels.」的原创文章，遵循CC 4.0 BY-SA版权协议，转载请附上原文出处链接及本声明。
原文链接：https://blog.csdn.net/weixin_51216553/article/details/123526259*/

#include<iostream>
#include<vector>
#include<cmath>
using namespace std;
const int MAXN = 3e5+5;
int n,m,k;
int tr[MAXN];
double dp[MAXN][2];

bool check1(double mid){
    dp[0][0] = dp[0][1] = 0.0;
    for(int i = 1; i <= n; i++){
        dp[i][0] = dp[i-1][1];
        dp[i][1] = max(dp[i-1][0],dp[i-1][1]) + tr[i] - mid;
    }
    if(max(dp[n][1],dp[n][0]) >= 0)return true;
    else return false;
}

bool check2(int mid){
    dp[0][0] = dp[0][1] = 0;
    for(int i = 1; i <= n; i++){
        dp[i][0] = dp[i - 1][1];
        dp[i][1] = max(dp[i-1][0], dp[i-1][1]) + (tr[i] >= mid ? 1: -1);
    }
    if(max(dp[n][1],dp[n][0]) > 0) return true;
    else return false;
}

void work(){
    cin >> n;
    for(int i = 1; i <= n; i++)cin >> tr[i];
    double l = 0, r = 1e9;
    while(r - l >= 1e-6){
        double mid = (l + r)/2;
        if(check1(mid)) l = mid;
        else r = mid;
    }
    int ll = 0, rr = 1e9;
    while(ll <= rr){
        int mid = (ll + rr) /2;
        if(check2(mid)) ll = mid + 1;
        else rr = mid - 1;
    }
    cout << r << '\n' << rr << '\n';
}


int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    work();
    return 0;
}