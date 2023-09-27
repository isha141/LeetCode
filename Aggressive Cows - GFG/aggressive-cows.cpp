//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution { 
    private:
    int ok(int mid,vector<int>&stalls,int n,int k){
        int count=1;
        int sum=0;
        for(int i=1;i<n;++i){
            sum+=stalls[i]-stalls[i-1];
            if(sum>=mid){
                sum=0;
                count+=1;
            }
        }
        if(count>=k)
          return 1;
        return 0;
    }
public:
    int solve(int n, int k, vector<int> &stalls) {
     sort(stalls.begin(),stalls.end());
      long low=0;
      long high=stalls[n-1];
      long ans=0;
      while(low<=high){
          long mid=(low+high)>>1;
          if(ok(mid,stalls,n,k)){
              ans=mid;
              low=mid+1;
          }
          else{
              high=mid-1;
          }
      }
      return ans;
        // Write your code here
    }
};

//{ Driver Code Starts.

int main() {
    int t = 1;
    cin >> t;

    // freopen ("output_gfg.txt", "w", stdout);

    while (t--) {
        // Input

        int n, k;
        cin >> n >> k;

        vector<int> stalls(n);
        for (int i = 0; i < n; i++) {
            cin >> stalls[i];
        }
        // char ch;
        // cin >> ch;

        Solution obj;
        cout << obj.solve(n, k, stalls) << endl;

        // cout << "~\n";
    }
    // fclose(stdout);

    return 0;
}
// } Driver Code Ends