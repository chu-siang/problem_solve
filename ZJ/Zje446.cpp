#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    scanf("%d",&n);
    vector<int> v(n);
    for(int i = 0; i < n; i++){
        v[i] = i+1;
    }
    do{
        for(auto i:v){
            printf("%d ",i);
        }
        printf("\n");
    }while(next_permutation(v.begin(),v.end()));
    return 0;
}