// { Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function Template for C++

class Solution { 
    private:
    int solve(int ind,int A[],int N)
    {
        if(ind+1>=N) return 1;
        if(A[ind]==0) return 0;
        for(int i=1;i<=A[ind];i++)
        {
            if(solve(ind+i,A,N))
            return 1; 
        }
        return 0;
    }
  public:
    int canReach(int A[], int N) {
        // code here 
        return solve(0,A,N);
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin>>N;
        
        int A[N];
        
        for(int i=0; i<N; i++)
            cin>>A[i];

        Solution ob;
        cout << ob.canReach(A,N) << endl;
    }
    return 0;
}  // } Driver Code Ends