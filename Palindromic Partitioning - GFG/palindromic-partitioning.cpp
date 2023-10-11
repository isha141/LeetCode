//{ Driver Code Starts
// Initial Template for c++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

int dp[505];
class Solution{
    private:
    int n;
    bool ok(string &temp){
        int i=0;
        int j=temp.size()-1;
        if(temp.size()==0) 
        return 0;
        while(i<=j){
            if(temp[i]!=temp[j])
              return 0;
            i++;
            j--;
        }
        return 1;
    }
    int solve(int i,string &str){
        if(i>=n)
         return 0;
        if(dp[i]!=-1)
          return dp[i];
        string temp="";
        int ans=INT_MAX;
        for(int j=i;j<n;++j){
            temp+=str[j];
            if(ok(temp)){
                ans=min(ans,1+solve(j+1,str));
            }
        }
        return dp[i]=ans;
    }
public:
    int palindromicPartition(string str)
    {
        n=str.size();
        memset(dp,-1,sizeof(dp));
       return solve(0,str)-1;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        string str;
        cin>>str;
        
        Solution ob;
        cout<<ob.palindromicPartition(str)<<"\n";
    }
    return 0;
}
// } Driver Code Ends