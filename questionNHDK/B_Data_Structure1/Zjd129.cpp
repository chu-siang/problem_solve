#include<iostream>
#include<set>

using namespace std;

int main(){
    set<long long>st;
    st.emplace(1);

    int count = 0;

    for(auto it = st.begin(); it != st.end(); it++){
        ++count;
        if(count == 1500)
            cout << "The 1500'th ugly number is " << *it << ".";
        st.emplace(*it * 2);
        st.emplace(*it * 3);
        st.emplace(*it * 5);
    }
    return 0;
}


















