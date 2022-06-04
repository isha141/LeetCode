// { Driver Code Starts
// Initial template for C++

#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function template in C++

class Solution 
{ 
    private:
    bool isvalid(int A[],int mid,int M,int N)
    { 
        int sum=0;
        int count=1;
        for(int i=0;i<N;i++)
        { 
            if(A[i]>mid)return 0;
            if(sum+A[i]<=mid)
            sum+=A[i];
            else
            {
                count++;
                sum=A[i];
            } 
           // cout<<sum<<" ";
        }
        return count<=M;
    }
    public:
    //Function to find minimum number of pages.
    int findPages(int A[], int N, int M) 
    {
        //code here  
        int ans=INT_MAX;
        sort(A,A+N); 
        int sum=0;
         int low=A[0];
        for(int i=0;i<N;i++)
            {
              sum+=A[i];
              low=min(low,A[i]);
            }
         int high=sum;
        while(low<=high)
           {
               int mid=(low+high)>>1;
               if(isvalid(A,mid,M,N))
               {
                   ans=min(ans,mid);
                      high=mid-1;  
               }
               else 
               low=mid+1;
               
           

           }
           return ans;
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