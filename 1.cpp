#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define ll long long int
 
int main()
{
  int i,n,m;
  cin>>n>>m;
  vector<int> arr;

  for(i=0;i<m;i++)
  {
    int x;
    cin>>x;
    if(n%x==0)
      arr.pb(x);
  }

  m = arr.size();
  sort(arr.begin(),arr.end());
  queue<vector<ll> > q;

  for(i=0;i<m;i++)
  {
    vector<ll> v;
    v.pb(1);
    v.pb(arr[i]);
    q.push(v);
  }

  int ans = INT_MAX;
  vector<vector<ll> > anss,a;  

  while(!q.empty())
  {
    vector<ll> v = q.front();
    q.pop();
 
    for(int i=0;i<m;i++)
    {
      vector<ll> vv=v;
      if(vv.back()*arr[i]==n)
      {
        vv.pb(n);
        if(vv.size()<ans)
        {
          anss = a;
          anss.pb(vv);
          ans=vv.size();
        }
        else if(vv.size()==ans)
          anss.pb(vv);
      }

      if(n%(vv.back()*arr[i])==0 && vv.back()*arr[i]<n && vv.size()+1<ans)
      {
        vv.pb(vv.back()*arr[i]);
        q.push(vv);
      }
    }
  }

  int min_index = 0,minVal = INT_MAX;
  vector<int> minn,mm;

  for(i=0;i<anss.size();i++)
    minn.pb(i);

  int j=1;
  while(minn.size()!=1 && j<ans-1)
  {
    minVal = INT_MAX;
    for(int i=0;i<minn.size();i++)
    {
      if(anss[minn[i]][j]<minVal)
        minVal=anss[minn[i]][j];
      
    }

    for(int i=0;i<minn.size();i++)
    {
      if(minVal == anss[minn[i]][j])
        mm.pb(minn[i]);
    }

    minn = mm;
    j++;
    mm.clear();
  }

  for(int i=0;i<ans;i++)
    cout<<anss[minn[0]][i]<< " "; 
  
  return 0;
}
