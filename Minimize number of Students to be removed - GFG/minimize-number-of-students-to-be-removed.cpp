//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution { 
    // int lcs(int i,int h[],int n,int last){
    //     if(i>=n) return 0;
    //     int take=0;
    //     int not_take=0;
    //     if(h[i]>last)
    //     take=lcs(i+1,h,n,h[i])+1;
    //     not_take=lcs(i+1,h,n,last);
    //     return max(take,not_take);
    // }
  public:
    int removeStudents(int h[], int n) {
        // code here
        int ans=1;
         vector<int>dp;  
         dp.push_back(h[0]);
         for(int i=1;i<n;++i){ 
             if(dp.size() && dp[dp.size()-1]<h[i]){
                 dp.push_back(h[i]);
             }
             else{
             auto itr=lower_bound(dp.begin(),dp.end(),h[i])-dp.begin();
               dp[itr]=h[i];
             }
         }
        return n-(int)dp.size();
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin>>N;
        
        int H[N];
        for(int i=0; i<N; i++)
            cin>>H[i];

        Solution ob;
        cout << ob.removeStudents(H,N) << endl;
    }
    return 0;
}
// } Driver Code Ends