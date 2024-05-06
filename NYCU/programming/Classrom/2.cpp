#include<bits/stdc++.h>
using namespace std;

int main(){
    fstream f;
    f.open("a.txt");
    string s;
    f >> s;
    cout << s << '\n';
    f.close();
}