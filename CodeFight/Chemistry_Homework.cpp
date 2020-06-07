/* For your chemistry homework, you wrote out a long chemical formula without any spaces between the elements.
But then your little brother found your paper and messed up the formula by changing all the lowercase letters to uppercase.
It's impossible to figure out where one element ends and the next begins! Now you have to restore the formula.
If there are several possible answers, return the one with the smallest number of elements. 
If there are still several answers, return the lexicographically smallest one.
*/

std::string restoreChemicalFormula(std::vector<std::string> e, std::string f) {
    unordered_map<string,int>m;
    for(int i=0;i<e.size();i++)
    m[e[i]]++;
    vector<int>v(f.size()+1,0);
    v[0]=-1;
    string y="";
    for(int i=0;i<f.size();i++)
    f[i]=tolower(f[i]);
    for(int i=0;i<=f.size();i++)
    {
        for(int j=1;j<=f.size()-i;j++)
        {
           if(v[i])
           {
              string k=f.substr(i,j);
              k[0]=toupper(k[0]);
              if(m.count(k) && j>v[j+i])
              v[j+i]=j;
           }
        }

       if(v[f.size()])
        {
            string u="";
            int j=f.size();
            cout<<v[j]<<" ";
             while(j>0)
            {
                string q=f.substr(j-v[j],v[j]);
                q[0]=toupper(q[0]);
                u=q+u;
                j-=v[j];
            }
            if(u<y || y=="")
            y=u;
        }
    }
    return y;
}
