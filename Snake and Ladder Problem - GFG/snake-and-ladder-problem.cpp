//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
    private:
    int solve(int i,int arr[],map<int,int>&mp){
      vector<int>vis(31,0);
      queue<int>q;
      q.push(i);
      int count=0;
      while(!q.empty()){ 
          int t=q.size();
          while(t--){
          auto itr=q.front();
          q.pop();  
          if(itr==30)
          return count;
          vis[itr]=1;
          for(int i=1;i<=6;++i){
              int pos=(itr+i);
              if(pos<=30 && vis[pos]==0 && mp.find(pos)!=mp.end()){
                  q.push(mp[pos]);
                  vis[pos]=1;
              }
              else if(pos<=30 && vis[pos]==0){
                  q.push(pos);
                  vis[pos]=1;
              }
          }
          }
          count++;
      }
      return count;
    }
public:
    int minThrow(int n, int arr[]){
        // code here 
        map<int,int>mp;
        for(int i=0;i<2*n;i+=2){
            mp[arr[i]]=arr[i+1];
        }
        return solve(1,arr,mp);
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        int arr[2*N];
        for(int i = 0;i < 2*N;i++)
            cin>>arr[i];
        
        Solution ob;
        cout<<ob.minThrow(N, arr)<<"\n";
    }
    return 0;
}
// } Driver Code Ends