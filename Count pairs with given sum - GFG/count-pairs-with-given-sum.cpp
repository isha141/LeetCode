//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution{   
public:
    int getPairsCount(int arr[], int n, int k) {
        // code here 
        map<int,int>mp;
        int c=0;
        for(int i=0;i<n;++i){
            mp[arr[i]]++;
        }
        for(int i=0;i<n;++i){
            if(mp.find(k-arr[i])!=mp.end())
            {
                if(k-arr[i]!=arr[i]){
                int temp=mp[k-arr[i]];
                int temp2=mp[arr[i]];
                 c+=(temp*temp2);  
                 mp.erase(arr[i]);
                 mp.erase(k-arr[i]);
                }
                else {
                    int temp=mp[k-arr[i]];
                    c+=(temp*(temp-1))/2;
                    mp.erase(k-arr[i]);
                }
            }
        }
        return c;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.getPairsCount(arr, n, k);
        cout << ans << "\n";
    }
    
    return 0;
}
// } Driver Code Ends