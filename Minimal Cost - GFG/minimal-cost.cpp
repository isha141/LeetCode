//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  private:
  public:
    int minimizeCost(vector<int>& h, int n, int k) {
        vector<int>dp(n+1,INT_MAX);
        dp[n-1]=0;
        for(int i=n-2;i>=0;--i){ 
            int ans=INT_MAX;
              for(int j=1;j<=k;++j){
                  if((i+j)<n){
                     int  temp=abs(h[i]-h[i+j])+dp[i+j];
                    //   if((i+j+1)<n){
                    //   temp+=dp[i+j+1]
                    ans=min(ans,temp);
                  }
              } 
              dp[i]=ans;
        }
        // for(int i=0;i<n;++i) cout<<dp[i]<<";;;";
        // cout<<endl;
        return dp[0];
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, K;
        cin >> N >> K;
        vector<int> arr(N);
        for (int i = 0; i < N; i++) {
            cin >> arr[i];
        }
        Solution obj;
        cout << obj.minimizeCost(arr, N, K) << "\n";
    }
    return 0;
}
// } Driver Code Ends