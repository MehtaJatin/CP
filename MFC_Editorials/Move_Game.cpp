#include<bits/stdc++.h>
using namespace std;
#define mod 1000000007
#define int long long int
int power(int n)
{
    //int total=2;
    int a=2;
    int total=1;
    while(n)
    {
        if(n%2)
        total=(total*a)%mod;
        n=n/2;
        a=(a*a)%mod;
    }
    return total;
}
signed main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        if(n%2)
        cout<<power((n-3)/2)<<"\n";
        else
        cout<<"0\n";
    }
}
