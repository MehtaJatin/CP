/* test    */
/*
Jatin Geek
*/
#include <bits/stdc++.h>
using namespace std;

int main() {

	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		vector<int>a(n),b(n);
		for(int i=0;i<n;i++)
		cin>>a[i];
		for(int i=0;i<n;i++)
		cin>>b[i];
		pair<int,int>p[n];
		for(int i=0;i<n;i++)
			p[i]={a[i],b[i]};
		sort(p,p+n);
		vector<int>dp(n,1);
		dp[n-1]=1;
		for(int i=n-1;i>=0;i--)
		{
			for(int j=n-1;j>i;j--)
			{
				if(p[i].first<=p[j].first && p[i].second<=p[j].second)
				dp[i]=max(dp[i],dp[j]+1);
			}
		}
		cout<<*max_element(dp.begin(),dp.end())<<"\n";
	}
	return 0;
}
