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
        int curr=0;
        sort(start,start+n);
        sort(end,end+n);
        int k=0;
        int i=0;
        int j=0;
        while(i<n && j<n){
            if(start[i]<end[j]){
                curr++;
                i++;
            }
            else {
                j++;
                curr--;
            }
        ans=max(ans,curr);
        }
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