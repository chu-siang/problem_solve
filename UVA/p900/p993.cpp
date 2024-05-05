//993
#include <iostream>
#include <set>

using namespace std;

int main(){
    int i, m;
    getchar();
    while(cin >> m)
    {
        multiset<int> st;
        if(m < 2) cout << m;
        else
        {
            while(m > 1)
            {
                for(i = 9;i > 1;i--)
                {
                    if(!(m % i))
                    {
                        m /= i;
                        st.insert(i);
                        break;
                    }
                }
                if(i == 1)
                {
                    cout << -1;
                    m = 0;
                    break;
                }
            }
        }
        if(m) for(auto i : st)cout << i;
        cout << endl;
    }
}