//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution
{
    public:
    //Function to find maximum of minimums of every window size.
    vector <int> maxOfMin(int arr[], int n)
    {
        // Your code here 
        vector<int>ans(n,0);
        vector<int>pre(n,-1);
        vector<int>suff(n,n);
        stack<int>s;
        for(int i=0;i<n;++i){
            while(!s.empty() && arr[s.top()]>=arr[i]){
                s.pop();
            }
            if(!s.empty()){
                pre[i]=s.top();
            }
            s.push(i);
        }
        while(!s.empty()) s.pop();
        for(int i=n-1;i>=0;--i){
            while(!s.empty() && arr[s.top()]>=arr[i])
               s.pop();
            if(!s.empty()){
                suff[i]=s.top();
            }
            s.push(i);
        }
        for(int i=0;i<n;++i){
            int diff=suff[i]-pre[i]-2;
            ans[diff]=max(ans[diff],arr[i]);
        }
        for(int i=n-2;i>=0;--i){
            ans[i]=max(ans[i],ans[i+1]);
        }
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++) cin >> a[i];
        Solution ob;
        vector <int> res = ob.maxOfMin(a, n);
        for (int i : res) cout << i << " ";
        cout << endl;
    }
    return 0;
}

// } Driver Code Ends