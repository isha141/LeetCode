//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution {
public:
    int findMidSum(int ar1[], int ar2[], int n) {
            // code here  
            priority_queue<int,vector<int>,greater<int>>mini;
            for(int i=0;i<n;++i){
                mini.push(ar1[i]);
                mini.push(ar2[i]);
            }
            while(--n){
                mini.pop();
            }
            int temp1=mini.top(); 
            mini.pop();
            int temp2=mini.top();
            mini.pop(); 
            // cout<<temp1<<";;"<<temp2<<endl;
            return (temp1+temp2);
            
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, i;
        cin >> n;
        int ar1[n], ar2[n];
        for (i = 0; i < n; i++) {
            cin >> ar1[i];
        }
        for (i = 0; i < n; i++) {
            cin >> ar2[i];
        }
        Solution ob;
        auto ans = ob.findMidSum(ar1, ar2, n);
        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends