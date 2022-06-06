// { Driver Code Starts
//Initial template for C++
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function template in C++

class Solution
{ 
    private:
    int f(int i,int j,int a,int b)
    {
        if(i==a-1 && j==b-1)
         return 1;
        if(i>=a||  j>=b) return 0;
        int l=f(i+1,j,a,b);
        int r=f(i,j+1,a,b);
        return l+r;
    }
    public:
    //Function to find total number of unique paths.
    int NumberOfPath(int a, int b)
    {
        //code here
        return f(0,0,a,b);
    }
};


// { Driver Code Starts.
int main()
{
    //taking total testcases
    int t;
    cin>>t;
    while(t--)
    {
        //taking dimensions of the matrix
        int a,b;
        cin>>a>>b;
        Solution ob;
        //calling NumberOfPath() function
        cout << ob.NumberOfPath(a,b) << endl;
    }
}

  // } Driver Code Ends