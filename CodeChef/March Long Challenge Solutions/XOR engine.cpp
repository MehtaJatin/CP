#include<bits/stdc++.h>
using namespace std;
int se(int a)
{
    int count=0;
   while(a)
   {
       count++;
       a=a & (a-1);
   }
   return count;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    while(t--)
    {
        int n,q;
        cin>>n>>q;
        vector<int>v(n);
        int count=0;
        for(int i=0;i<n;i++)
        {
        cin>>v[i];
        if(se(v[i])%2==0)
        count++;
        }
        while(q--)
        {
         int p;
         cin>>p;
         int r=se(p);
         if(r%2==0)
         cout<<count<<" "<<n-count<<"\n";
         else
         cout<<n-count<<" "<<count<<"\n";
        }

    }
}
