//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
    //Function to find a continuous sub-array which adds up to a given number.
    vector<int> subarraySum(vector<int>arr, int n, long long s)
    {
        // Your code here 
        vector<int>ans;
        long long sum=0;
        int left=-1;
        int right=-1;  
        int j=0;
        unordered_map<long , int>mp;
        for(int i=0;i<n;++i){
            sum+=arr[i];
            if(sum==s){
                if(left==-1){
                    return {j+1,i+1};
                }
                else{
                    return {j+1,i+1};
                }
            }
            if(sum>s){
               while(j<i && sum>s){
                   sum-=arr[j];
                   j++;
               } 
               if(sum==s){
                   return {j+1,i+1};
               }
            }
            // mp[sum]=i;
        }
        return {-1};
    }
};

//{ Driver Code Starts.

int main()
 {
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        long long s;
        cin>>n>>s;
        vector<int>arr(n);
        // int arr[n];
        const int mx = 1e9;
        for(int i=0;i<n;i++)
        {
            cin>>arr[i];
        }
        Solution ob;
        vector<int>res;
        res = ob.subarraySum(arr, n, s);
        
        for(int i = 0;i<res.size();i++)
            cout<<res[i]<<" ";
        cout<<endl;
        
    }
	return 0;
}
// } Driver Code Ends