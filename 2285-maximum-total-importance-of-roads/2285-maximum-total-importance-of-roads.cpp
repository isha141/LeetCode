// #ishajindal GCC optimize("O2")
#include<bits/stdc++.h>
using namespace std; 
#define pb push_back
#define ppb pop_back
#define ins insert 
#define ss second
#define lb lower_bound
#define ub upper_bound 
#define umap unordered_map
#define rep(i,n) for(int i = 0; i < (int)(n); i++)
#define rrep(i,n) for(int i = (int)(n) - 1; i >= 0; i--)
#define all(x) begin(x), end(x)
#define rall(x) rbegin(x), rend(x)
template<class T> bool chmax(T& a, const T& b) { if (a < b) { a = b; return true; } else return false; }
template<class T> bool chmin(T& a, const T& b) { if (b < a) { a = b; return true; } else return false; }
using ll = long long;
using p = pair<int,int>;
using vi = vector<int>;
using vvi = vector<vi>;
using vl = vector<ll>; 
using vvl = vector<vl>; 
class Solution {
public:
    long long maximumImportance(int n, vector<vector<int>>& roads) {
        vi degree(n);
        for(auto itr : roads)
        {
           degree[itr[0]]++;
           degree[itr[1]]++;
        } 
        vector<pair<ll,ll>>v;
        rep(i,n)
        v.pb({degree[i],i});
        sort(rall(v));  
        // for(auto [p,q]:v)
        //     cout<<p <<" "<<q<<endl;
        vi val(n,0);
        for(auto it: v)
        {
           val[it.ss]=n--;
        } 
        // for(auto it: val)
        //     cout<<it<<" ";
        //cout<<endl;
        ll ans=0;
        for(auto &itr: roads)
        {
          ans+=val[itr[0]]+val[itr[1]];
        }
      return ans;
    }
};