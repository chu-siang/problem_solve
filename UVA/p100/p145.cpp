#include<bits/stdc++.h>
#define ll long long
using namespace std;
int main(){
    char c;
    map<char,vector<double>> mp = {{'A',{0.02,0.1,0.06}},{'B',{0.05,0.25,0.15}},
    {'C',{0.13,0.53,0.33}},{'D',{0.17,0.87,0.47}},{'E',{0.30,1.44,0.80}}};
    int b[] = {480,1080,1320,1920,2520,2760,2880};
    while(cin >> c){
        if(c == '#')break;
        string id;
        cin >> id;
        int w,x,y,z;
        cin >> w >> x >> y >> z;
        int m1 = w*60 + x;
        int m2 = y*60 + z;
        int T[3] = {0};
        double cost = 0;
        if(m1 == m2){
            T[0] = 600;
            T[1] = 600;
            T[2] = 240;
            cost = T[0]*mp[c][0] + T[1]*mp[c][1]+T[2]*mp[c][2];
            cout << setw(10) << id << setw(6) << T[1]
            << setw(6) << T[2] << setw(6) << T[0]
            <<setw(3) << c << setw(8) << fixed << setprecision(2) <<cost << '\n';
            continue;
        }
        if(m1 == 0) m1 = 1440;
        if(m2 == 0) m2 = 1440;
        if(m1 > m2) m2 += 24*60;

        for(int i = 0; i < 7; i++){
            if(m1 <= b[i]){
                if(m2 <= b[i]){
                    T[i%3] += (m2 - m1); 
                    cost += (m2 - m1)*mp[c][i%3];
                    break;
                }else{
                    T[i%3] += (b[i] - m1);
                    cost += (b[i] - m1)*mp[c][i%3];
                    m1 = b[i];
                }
            }
        }
        cout << setw(10) << id << setw(6) << T[1]
            << setw(6) << T[2] << setw(6) << T[0]
            <<setw(3) << c << setw(8) << fixed << setprecision(2) <<cost << '\n';
    }
}
/*A 183-5724 17 58 18 04*/