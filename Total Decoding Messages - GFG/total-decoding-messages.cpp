//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

int dp[10002];
class Solution {
    private:
    int mod=1e9+7;
    int solve(int i,string &str,int n){
        if(i>=n) return 1;
        
        int temp=0;
        int ans=0;
        int l=0;
        int r=0; 
        if(str[i]=='0'){
            return 0;
        } 
        if(dp[i]!=-1) 
         return dp[i];
        temp+=str[i]-'0';
        if(temp>0){
            l=solve(i+1,str,n);
        }
        if(i+1<n){
            temp=temp*10+str[i+1]-'0'; 
            if(temp<=26){
              r=solve(i+2,str,n);
            }
        }
        return dp[i]=(l+r)%mod;

        
    }
	public:
		int CountWays(string str){
		    // Code here 
		    int n=str.size(); 
		    memset(dp,-1,sizeof(dp));
		    return solve(0,str,n);
		}

};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		string str;
		cin >> str;
		Solution obj;
		int ans = obj.CountWays(str);
		cout << ans << "\n";
	}
	return 0;
}
// } Driver Code Ends