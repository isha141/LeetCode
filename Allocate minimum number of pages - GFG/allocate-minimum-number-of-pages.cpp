// { Driver Code Starts
// Initial template for C++

#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function template in C++

class Solution 
{ 
    bool isvalid(int A[],int mid,int n,int m,int ans)
    { 
        int count=1; 
        int res=0;
        int sum=0;
        for(int i=0;i<n;i++)
        { 
           if( A[i]>mid)
           return 0;
            if(sum+A[i]<=mid)
             sum+=A[i];
            else{
                res=max(res,sum);
                count++; 
                sum=0;
                sum=A[i];
            }
        }
        if(count>m)
        return 0;
        else
        return 1;
    }
    private:
    int solve(int A[],int low,int high,int n,int m)
    { 
        int ans=-1;
        while(low<=high)
        {
            int mid=(low+high)/2;
            if(isvalid(A,mid,n,m,ans))
            { 
                ans=mid;
              high=mid-1;
            } 
            else
            low=mid+1;
        }
        return ans;
    }
    public:
    //Function to find minimum number of pages.
    int findPages(int A[], int N, int M) 
    {
        //code here 
        int low=A[0];
        int high=0;
        for(int i=0;i<N;i++)
        high+=A[i];
        return solve(A,low,high,N,M);
    }
};

// { Driver Code Starts.

int main() {
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int A[n];
        for(int i=0;i<n;i++){
            cin>>A[i];
        }
        int m;
        cin>>m;
        Solution ob;
        cout << ob.findPages(A, n, m) << endl;
    }
    return 0;
}
  // } Driver Code Ends