class Solution {
    public:
        int numRabbits(vector<int>& answers) {
            set<int>st;
            long long sum = 0;
            map<int,int>mp;
            for(auto i : answers){
                mp[i]++;
                st.emplace(i);
            }
            for(auto i : st){
                sum += ((mp[i]+i)/(i+1))*(i+1);
            }
            return sum;
        }
    };