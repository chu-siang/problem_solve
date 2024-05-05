//兩題joseph 151經典 : buttom up  old = (new + k)% n
//原遞迴式 :  f(n) = (f(n-1) + k)%n
//old 是 原本的編號  new 是 新的編號 k 是 數k個後淘汰 n是當前人數
// 做法 : 先從n個人 數 k 個 淘汰 (第一個淘汰編號:k-1)一直到 最後一個人--lastman(n == 1) 編號記得是0 (0~N-1)
// 在從 n = 2 buttom up 到最原始 n個人時 勝利者的原編號為何?
//來源 : https://blog.csdn.net/wusuopubupt/article/details/18214999
//來源 : https://blog.csdn.net/tingyun_say/article/details/52343897 
// 305 joseph : 模擬 top down new = (original + k)%n
// original 是 原本的編號(從第0個開始數)  new 是 新的編號 k 是 數k個後淘汰 n是當前人數
//做法 : 先從n個人 數 k 個 淘汰 (第一個淘汰編號:k-1) 然後持續到 條件結束(淘汰了cnt個人)(直接top down)
#include<bits/stdc++.h>
#define ll long long
using namespace std;

int main(){
    ll n;
    while(cin >> n,n){
        for(ll i = 1; ;i++){
            ll tmp = 0;
            for(ll cnt = 2; cnt < n; cnt++){
                tmp = (tmp + i) % cnt;
            }
            //tmp 原本從 1 ~ N  但是第一個固定會被淘汰 所以變 2 ~ N
            //平移後 變成 0 ~ N-2 總個數是 N - 1個
            //故原來求 last man 第13號時 變成 第11號(13 - 2)
            if(tmp == 11){
                cout << i << '\n';
                break;
            }
        }
    }
}