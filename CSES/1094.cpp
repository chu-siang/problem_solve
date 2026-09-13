#include <iostream>
#include <cmath>
#include <algorithm>

int main(){
    int cnt = 0;
    int n;
    std::cin >> n;
    for(int i = 0, l = 0, t = 0; i < n; ++i){
       std::cin >> l;
       if(t > l)cnt += t-l;
       t = std::max(t,l); 
    }
    std :: cout << cnt;
}