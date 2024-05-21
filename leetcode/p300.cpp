    for(int i = 0; i < n; i++){
        auto it = lower_bound(lis.begin(),lis.end(),v[i])-lis.begin();
        if(it == lis.size())lis.push_back(v[i]);
        else lis[it] = v[i]; 
    }
    cout << lis.size();