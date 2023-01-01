//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
  public:
    int minLaptops(int n, int start[], int end[]) {
        // Code here 
        int ans=1;
        int curr=1;
        sort(start,start+n);
        sort(end,end+n);
        int k=0;
        // int last=end[0];
        for(int i=1;i<n;++i){
            if(end[k]<=start[i]){
                k++;
            }
            else{
                curr++;
            }
            ans=max(ans,curr);
        }
        ans=max(ans,curr);
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        int start[N], end[N];
        for(int i=0; i<N; i++)
            cin>>start[i];
        for(int i=0; i<N; i++)
            cin>>end[i];
            
        Solution ob;
        cout << ob.minLaptops(N, start, end) << endl;
    }
}
// } Driver Code Ends