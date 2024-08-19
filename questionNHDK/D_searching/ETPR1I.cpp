#include <bits/stdc++.h>

#define int long long

using namespace std;

signed main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	
	vector <int> a(10);
	
	for(int i=0;i<10;i++)
	{
		cin >> a[i];
	}
	
	int n;
	
	cin >> n;
	
	vector <pair<int,int>> b;
	
	for(int i=0;i<n;i++)
	{
		int input;
		
		cin >> input;
		
		for(int k=0;k<10;k++)
		{
			if( a[k] <= input )
			{
				b.push_back({input-a[k],i});
			}
		}
	}
	
	sort(b.begin(),b.end());
	
	set <int> s;
	
	vector <int> c(n,0);
	
	int ans = 1e18,index1 = 0,index2 = 0;
	
	c[b[0].second]++;
		
	s.insert(b[0].second);
		
	while( index1 < b.size() )
	{
		while( s.size() != n && index2 < b.size() )
		{
			index2++;
			
			if( index2 == b.size() ) break;
			
			s.insert(b[index2].second);
			
			c[b[index2].second]++;
		}
		
		if( s.size() == n  )
		{
			int u = b[index2].first - b[index1].first;
			
			ans = min(ans,u);
			
			if( c[b[index1].second] == 1 )
			{
				s.erase(b[index1].second);
			}
			
			c[b[index1].second]--;
			
			index1++;
		}
		else
		{
			break;
		}
	}
	
	cout << ans << "\n";
}