//10200
#include <iostream>

using namespace std;

int sum[10001];

int judge(int x){
    for(int i = 2;i * i <= x;++i)
        if(x % i==0)
            return 0;
    return 1;
}

int main()
{
    int a, b;
    sum[0] = 1;
    for(int i = 1;i <= 10000;++i)
        sum[i] = sum[i - 1] + judge(i * i + i + 41);

    while(cin >> a >> b){
        printf("%.2f\n",(sum[b] - sum[a - 1]) * 100.0 / (b - a + 1) + 1e-6);
    }
} 