//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// Function to return minimum number of jumps to end of array

class Solution{
  public:
    int minJumps(int arr[], int n){
        // Your code here
        if(arr[0]==-1)
          return -1;
        int ans=0;
        int maxi=arr[0];
        int start=0;
        for(int i=0;i<n;++i){
            if(maxi<i) 
            return -1;
            maxi=max(maxi,arr[i]+i);
            if(i<n-1 && i==start){
                ans+=1;
                start=maxi;
            }
        }
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
        int n,i,j;
        cin>>n;
        int arr[n];
        for(int i=0; i<n; i++)
            cin>>arr[i];
        Solution obj;
        cout<<obj.minJumps(arr, n)<<endl;
    }
    return 0;
}

// } Driver Code Ends