//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
    private:
    bool ok(int mid,vector<int>&stalls,int n,int k){
        int c=1;
        int sum=0;
        for(int i=1;i<n;++i){
           int a=stalls[i]-stalls[i-1];
           sum+=a;
           if(sum>=mid){
               c+=1;
               sum=0;
           }
        }
        if(c<k)
        return 0;
        return 1;
    }
public:

    int solve(int n, int k, vector<int> &stalls) {
        sort(stalls.begin(),stalls.end());
        int low=0;
        int ans=0;
        int high=stalls[n-1];
        while(low<=high){
            int mid=(low+high)>>1;
            if(ok(mid,stalls,n,k)){
                ans=mid;
                low=mid+1;
            }
            else{
                high=mid-1;
            }
        }
        return ans;
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