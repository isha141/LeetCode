//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
    private:
    long mod=1e9+7;
  public:
    int nthFibonacci(int n){
        // code here 
        long long first=0;
        long long second=1;
        if(n==1)
         return 0;
        if(n==2)
         return 1;
        // n-=2;
        while(n){
            long  long temp=(first+second)%mod;
            first=second;
            second=temp;
            n-=1;
        }
        return first;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        Solution ob;
        cout << ob.nthFibonacci(n) << endl;
    }
    return 0;
}

// } Driver Code Ends