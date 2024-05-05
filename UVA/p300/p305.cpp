//兩題joseph 151經典 : buttom up  old = (new + k)% n
//原遞迴式 :  f(n) = (f(n-1) + k)%n
//old 是 原本的編號  new 是 新的編號 k 是 數k個後淘汰 n是當前人數
// 做法 : 先從n個人 數 k 個 淘汰 (第一個淘汰編號:k-1)一直到 最後一個人--lastman(n == 1) 編號記得是0 (0~N-1)
// 在從 n = 2 buttom up 到最原始 n個人時 勝利者的原編號為何?
//來源 : https://blog.csdn.net/wusuopubupt/article/details/18214999
//來源 : https://blog.csdn.net/tingyun_say/article/details/52343897
//來源 : https://blog.csdn.net/m0_73355263/article/details/129271716
// 305 joseph : 模擬 top down new = (original + k)%n
// original 是 原本的編號(從第0個開始數)  new 是 新的編號 k 是 數k個後淘汰 n是當前人數
//做法 : 先從n個人 數 k 個 淘汰 (第一個淘汰編號:k-1) 然後持續到 條件結束(淘汰了cnt個人)(直接top down)
#include<bits/stdc++.h>
#define ll long long
using namespace std;

ll a[15];

int main(){
    for(int i = 1; i < 14; i++){
        ll n = 2*i;
        ll cnt;
        int kill;
        for(ll k = i+1; ;k++){
            //(當前要被淘汰的人 從 0 開始數k個 故kill 一開始設成0)
            kill = 0;
            // 如果第一輪給過就繼續 + k 是數k個 -1 是 從0開始
            if((kill + k - 1) % n >= i){
                for(cnt = 0; cnt < i; cnt++){
                    kill = (kill + k - 1) % (n - cnt);
                    if(kill < i)break;
                }
                if(cnt == i){
                    a[i] = k;
                    break;
                }
            } 
        }
    }
    int q;
    while(cin >> q,q){
        cout << a[q] << '\n';
    }
}