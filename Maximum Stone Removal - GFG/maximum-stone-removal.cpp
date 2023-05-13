//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class disjoint{
    //  vector<int>row; 
    public:
     vector<int>rank;
     vector<int>parent;
      disjoint(int n){
           parent.resize(n+1,0);
           rank.resize(n+1,1); 
           for(int i=0;i<=n;++i){
               parent[i]=i;
           }
      }
       int findparent(int n){
            if(parent[n]==n)
              return n;
            return parent[n]=findparent(parent[n]);
       }
        void unionbyrank(int u,int v){
            u=findparent(u);
            v=findparent(v);
            if(u==v) return ;
            if(rank[u]<rank[v]){
                 parent[u]=v;
                  rank[v]+=rank[u];
            }
            else {  
                parent[v]=u; 
                rank[u]+=rank[v];
            }
        }
};
class Solution {
  public:
    int maxRemove(vector<vector<int>>& s, int n) { 
         int maxRow=0;
         int maxCol=0;
         for(auto itr: s){
              maxRow=max(maxRow,itr[0]);
              maxCol=max(maxCol,itr[1]);
         }
         disjoint ds(maxRow+maxCol+1); 
         map<int,int>mp;
         for(auto itr: s){
              int r=itr[0];
              int c=itr[1];
               int ar=r;
               int col=c+maxRow+1;
               ds.unionbyrank(ar,col); 
               mp[ar]++;
               mp[col]++;
         }
          int count=0;
          for(auto itr: mp){
               if(ds.findparent(itr.first)==itr.first)
                count+=1;
          }
        //   cout<<n<<" "<<endl;
          return n-count;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> adj;

        for (int i = 0; i < n; ++i) {
            vector<int> temp;
            for (int i = 0; i < 2; ++i) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            adj.push_back(temp);
        }

        Solution obj;

        cout << obj.maxRemove(adj, n) << "\n";
    }
}
// } Driver Code Ends