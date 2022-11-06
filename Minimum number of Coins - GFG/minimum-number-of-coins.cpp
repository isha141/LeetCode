//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{ 
    private:
    int solve(int i,int amount,vector<int>&ans,int *coins){ 
        if(amount==0)
        return 1;
        if(i<0)
        return 0;
        if(amount>=coins[i]){
        ans.push_back(coins[i]);
        if( solve(i,amount-coins[i],ans,coins))
        return 1;
       }
       else
       solve(i-1,amount,ans,coins);
        return 0;
    }
public:
    vector<int> minPartition(int n)
    {
                // code here 
        vector<int>ans;
        if(n==0)
        return ans;
        int coins[]={ 1, 2, 5, 10, 20, 50, 100, 200, 500, 2000 } ;
        int i=9;
        solve(i,n,ans,coins);
        return ans;

    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        
        Solution ob;
        vector<int> numbers = ob.minPartition(N);
        for(auto u: numbers)
            cout<<u<<" ";
        cout<<"\n";
    }
    return 0;
}
// } Driver Code Ends