//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
    //Function to find largest rectangular area possible in a given histogram.
    long long getMaxArea(long long arr[], int n)
    {
        // Your code here 
        vector<int>left(n,0),right(n,n-1); 
        stack<int>s;
        for(int i=0;i<n;++i){
            while(!s.empty() && arr[s.top()]>=arr[i])
            s.pop();
            
            if(s.empty())
             left[i]=0;
             else
              left[i]=s.top()+1; 
              s.push(i);
        } 
        while(!s.empty())
        s.pop();
        for(int i=n-1;i>=0;--i){
            while(!s.empty() && arr[s.top()]>=arr[i])
            s.pop();
            if(s.empty())
            right[i]=n-1;
            else
            right[i]=s.top()-1;
            s.push(i);
        }
        long long ans=0;
        for(int i=0;i<n;++i){
            ans=max(ans,(right[i]-left[i]+1)*arr[i]);
        }
        return ans;
    }
};


//{ Driver Code Starts.

int main()
 {
    long long t;

    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        
        long long arr[n];
        for(int i=0;i<n;i++)
            cin>>arr[i];
        Solution ob;
        cout<<ob.getMaxArea(arr, n)<<endl;
    
    }
	return 0;
}

// } Driver Code Ends