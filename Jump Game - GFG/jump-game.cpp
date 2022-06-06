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
        int sum=0;
        for(int i=0;i<N;i++)
        {
            if(i>sum)
            return 0;
            sum=max(sum,i+A[i]);
        }
        return 1;
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