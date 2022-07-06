// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution
{
    private:
 //   bool cmp(pair p1,pair p2)
   // return (p1.second/p1.first  > p2.second/p2.first);
    int solve(int ind,int wt[],int val[],int n,int w, vector<vector<int>>&dp)
    {
        if(ind<0){
            return 0;
        }
        // if(w==0)
        // return 0; 
        if(dp[ind][w]!=-1) return dp[ind][w];
        int left=0;
        int right=0;
        if(w>=wt[ind])
        left=val[ind]+ solve(ind-1,wt,val,n,w-wt[ind],dp); 
        right=0+ solve(ind-1,wt,val,n,w,dp);
        return dp[ind][w]=max(left,right);
        
    }
    public:
    //Function to return max value that can be put in knapsack of capacity W.
    int knapSack(int W, int wt[], int val[], int n) 
    { 
       // Your code here 
       vector<vector<int>>dp(n,vector<int>(W+1,-1));
       vector<pair<int,int>>v;
    //   for(int i=0;i<n;++i) 
        // v.push_back({wt[i],val[i]}); 
        // for(auto itr: v)
        // cout<<itr.first<<" "<<itr.second<<endl;
      // sort(v.begin(),v.end(),cmp);
      return  solve(n-1,wt,val,n,W,dp);
       
    }
};

// { Driver Code Starts.

int main()
 {
    //taking total testcases
    int t;
    cin>>t;
    while(t--)
    {
        //reading number of elements and weight
        int n, w;
        cin>>n>>w;
        
        int val[n];
        int wt[n];
        
        //inserting the values
        for(int i=0;i<n;i++)
            cin>>val[i];
        
        //inserting the weights
        for(int i=0;i<n;i++)
            cin>>wt[i];
        Solution ob;
        //calling method knapSack()
        cout<<ob.knapSack(w, wt, val, n)<<endl;
        
    }
	return 0;
}  // } Driver Code Ends