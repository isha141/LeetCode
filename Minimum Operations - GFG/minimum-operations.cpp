//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
  public:
    int minOperation(int n)
    { 
        if(n==0) return 0;
        if(n==1) return 1;
        if(n==2) return 2;
        int temp=n;
        int ans=0;
        while(temp!=0){
            if(temp &1){
                temp-=1;
            }
            else{
                temp/=2;
            }
            ans+=1;
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
	        int n;
	        cin>>n;
	        Solution ob;
	        cout<<ob.minOperation(n)<<endl;
	    }
}
// } Driver Code Ends