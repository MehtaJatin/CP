#include <bits/stdc++.h>
using namespace std;
#define pp pair<int,int>
pp p1,p2,p3,p4;
int dir(pp p,pp q,pp r)
{
    //int val = (q.second - p.second) * (r.first - q.first) -
      //        (q.first - p.first) * (r.first - q.first);
    int val=(q.first-p.first)*(r.second-q.second)-(q.second-p.second)*(r.first-q.first);
    return val;
}
bool on(pp p1,pp p2,pp p3)
{
    int x1=p1.first,y1=p1.second,x2=p2.first,y2=p2.second,x3=p3.first,y3=p3.second;
    if((min(x1,x2)<=x3 && x3<=max(x1,x2)) && (min(y1,y2)<=y3 && y3<=max(y1,y2)))
    return true;
    return false;
}
bool check()
{
    int d1=dir(p3,p4,p1);
    int d2=dir(p3,p4,p2);
    int d3=dir(p1,p2,p3);
    int d4=dir(p1,p2,p4);
    //cout<<d1<<" "<<d2<<" "<<d3<<" "<<d4<<"\n";
    if(((d1>0 && d2<0) || (d1<0 && d2>0)) &&  ((d3<0 && d4>0) || (d3>0 && d4<0)))
    return true;
    if(d1==0 && on(p3,p4,p1))
    return true;

    if(d2==0 && on(p3,p4,p2))
    return true;

    if(d3==0 && on(p1,p2,p3))
    return true;

    if(d4==0 && on(p1,p2,p4))
    return true;
    return false;
}
int main() {
	// your code goes here
	int t;
	cin>>t;
	while(t--)
	{
	    int n,q;
	    cin>>n>>q;
	    vector<int>v(n);
	    for(int i=0;i<n;i++)
	    cin>>v[i];
	    while(q--)
	    {
	        int x1,x2,y,count=0;
	        cin>>x1>>x2>>y;
	        p1.first=x1;
	        p1.second=y;
	        p2.first=x2;
	        p2.second=y;
	        for(int i=0;i<n-1;i++)
	        {
	            p3.first=i+1;
	            p3.second=v[i];
	            p4.first=i+2;
	            p4.second=v[i+1];
	            if((p2==p3) || (p1==p4))
	            continue;
	           if(check())
	           count++;
	        }
	        cout<<count<<"\n";
	    }
	}
	return 0;
}
