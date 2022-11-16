//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{

	public:
	int findSwapValues(int a[], int n, int b[], int m)
	{
        // Your code goes here 
      long long suma=0;
      long long sumb=0;
      for(int i=0;i<n;++i)
      suma+=a[i];
      for(int j=0;j<m;++j)
      sumb+=b[j];
      sort(a,a+n);
      sort(b,b+m); 
      if((suma-sumb)%2)
      return -1;
      long long temp=(suma-sumb)/2;
      int i=0;
      int j=0;
      while(i<n && j<m){
          if((a[i]-b[j])<temp)
          i++;
          else if((a[i]-b[j])>temp)
           j++;
           else 
           return 1;
          
      }
      return -1;
	}
 

};

//{ Driver Code Starts.

int main() 
{
   	
   	int t;
    cin >> t;
    while (t--)
    {
    	int n,m;
        cin>>n>>m;
        int a[n];
        int b[m];
        for(int i=0;i<n;i++)
            cin>>a[i];
        for(int i=0;i<m;i++)
            cin>>b[i];
        

        Solution ob;
        cout <<  ob.findSwapValues(a, n, b, m);
	    cout << "\n";
	     
    }
    return 0;
}






// } Driver Code Ends