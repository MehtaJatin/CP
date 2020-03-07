#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int x,y;
        cin>>x>>y;
        vector<pair<int,int> >v;
        v.push_back({x,y});
        int r,c;
        int p=(x-y)/2;
         r=x-p;
         c=y+p;
        int a=r,b=c,i=r-1;
        while(a>1 && b>1)
        {
            v.push_back({a,b});
            if(a<=4 && b<=4)
            {v.push_back({2*a-1,1});
            v.push_back({1,2*b-1});
            }
            else
            {
              v.push_back({8,2*a-8});
              v.push_back({2*a-8,8});

            }
            v.push_back({a,b});
            a--;
            b--;
        }
        v.push_back({a,b});
        while(a<=r && b<=c)
        {
            v.push_back({a,b});
            a++;
            b++;
        }
        while(a<8 && b<8)
        {
            v.push_back({a,b});
             if(a<=4 && b<=4)
            {v.push_back({2*a-1,1});
            v.push_back({1,2*b-1});
            }
            else
            {
              v.push_back({8,2*a-8});
              v.push_back({2*a-8,8});

            }
            v.push_back({a,b});
            a++;
            b++;
            v.push_back({a,b});
        }
        vector<pair<int,int> >e;
        if(a==8 && b==8 && r!=8 && c!=8)
        v.push_back({8,8});
        e.push_back(v[0]);
        for(int i=1;i<v.size();i++)
        if(v[i]!=e[e.size()-1])
        e.push_back(v[i]);
        cout<<e.size()<<"\n";
        for(int i=0;i<e.size();i++)
        cout<<e[i].first<<" "<<e[i].second<<"\n";

    }
}
