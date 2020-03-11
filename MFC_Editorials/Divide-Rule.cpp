/* Logic -: Find all Prime factor's frequency of 'a' and 'c' and if there is any prime factor which is not in 'a'
            or if any prime factor let's call it as 'k' which is present in both 'a' and 'c' having
            freqInC[k]*d>freqInA[k]*b then print "NO" else print "YES"
*/


#include<bits/stdc++.h>
using namespace std;
#define int long long int
map<int,int>m,k;
void primeFactors(int n,int f)
{
    while (n % 2 == 0)
    {
        if(f)
        m[2]++;
        else
        k[2]++;
        n = n/2;
    }
    for (int i = 3; i <= sqrt(n); i = i + 2)
    {
        while (n % i == 0)
        {
            if(f)
            m[i]++;
            else
            k[i]++;
            n = n/i;
        }
    }

    if (n > 2)
        {
            if(f)
            m[n]++;
            else
            k[n]++;
        }
}
signed main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int  a,b,c,d;
        cin>>a>>b>>c>>d;
        m.clear();
        k.clear();
        primeFactors(a,1);
        primeFactors(c,0);
        int f=0;
        if(m.size()<k.size())
        cout<<"NO\n";
        else
        {
            auto itr=m.begin();
            auto ptr=k.begin();
            while(itr!=m.end() && ptr!=k.end())
            {
                if(itr->first==ptr->first && itr->second*b<ptr->second*d)
                {
                    f=1;
                    break;
                }
                if(itr->first==ptr->first)
                {itr++;
                ptr++;
                }
                else
                itr++;
            }
        if(f || ptr!=k.end())
        cout<<"NO\n";
        else
        cout<<"YES\n";
        }
    }
}
