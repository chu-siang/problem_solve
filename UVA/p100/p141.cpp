#include<iostream>
#include<set>
#include<cstring>
using namespace std;

struct spot{
    bool arr[52][52];
};

int n;
bool operator <(const spot & a, const spot & b){
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= n; j++)
            if(a.arr[i][j] < b.arr[i][j]) return true;
            else if(a.arr[i][j] > b.arr[i][j])return false;
    return false;
}
void change(spot & a){
    spot p;
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= n; j++)
            p.arr[i][j] = a.arr[j][n+1-i];
    a = p;
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    int x,y;
    char c;
    spot p;
    while(cin >> n,n){
        bool flag = false;
        set<spot>s;
        memset(p.arr,false,sizeof(p.arr));
        int count = 0;
        for(int num = 1; num <= 2*n; num++){
            cin >> x >> y >> c;
            if(flag) continue;
    
            if(c == '+') p.arr[x][y] = true;
            else p.arr[x][y] = 0;
            if(s.count(p)){
                flag = true;
                count = num;
                continue;
            }

            spot t(p);
            for(int i = 0; i < 4; i++){
                s.emplace(t);
                change(t);
            }
        }
        if(flag){
            if(count % 2 == 0) cout << "Player 1 wins on move "<< count << '\n';
            else cout << "Player 2 wins on move " << count << '\n'; 
        }else cout << "Draw\n";
    }
}