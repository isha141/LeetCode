//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution { 
    private:
    void solve(int arr[],int n,vector<int>&ans){
        stack<int>s; 
        s.push(arr[0]);
        for(int i=1;i<n;++i){ 
         if(s.empty() || arr[i]<s.top()){
             s.push(arr[i]);
         }
         else{
            int temp=s.top();
            bool flag=0;
            s.pop();
            while(!s.empty() && s.top()<arr[i])
            {
                flag=1;
                s.pop();
            }
            if(flag)
            ans.push_back(temp); 
            s.push(arr[i]);
        }
    } 
    ans.push_back(arr[n-1]);
    // reverse(ans.begin(),ans.end());
    }
  public:
    vector<int> leafNodes(int arr[],int n) {
        // code here 
        vector<int>ans;
        if(n==0)
        return {};
        if(n==1)
        return {arr[0]};
        solve(arr,n,ans);
        return ans;
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int N;
        cin >> N;
        int arr[N];
        for(int i=0;i<N;i++)cin>>arr[i];
        Solution ob;
        vector<int>ans=ob.leafNodes(arr,N);
        for(int i=0;i<ans.size();i++)cout<<ans[i]<<" ";
        cout<<endl;
    }
    return 0;
}
// } Driver Code Ends