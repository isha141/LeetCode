// { Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function Template for C++

class Solution { 
    private:
    bool solve(int ind,int A[],int N){
        if(ind>=N) return 0;
        if(ind==N-1) return 1; 
        if(A[ind]==0) return 0;
        for(int i=1;i<=A[ind];++i){
          if(solve(i+ind,A,N))
          return 1;
        }
        return 0;
    }
  public:
    int canReach(int A[], int N) {
        // code here 
        if(A[0]==0) return 0;
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