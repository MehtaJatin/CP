//GeekJatin
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,k;
        cin>>n>>k;
        vector<int>v(n),p(n);
        for(int i=0;i<n;i++)
        cin>>v[i];
        for(int i=0;i<n;i++)
        cin>>p[i];
        map<int,int>m;
        for(int i=0;i<n;i++)
        m[v[i]]+=p[i];
        int mx=INT_MAX;
        for(auto itr:m)
            if(itr.second<mx)
            mx=itr.second;

        cout<<mx<<"\n";
    }
}
