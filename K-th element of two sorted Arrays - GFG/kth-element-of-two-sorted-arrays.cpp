// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution{
    public:
    int kthElement(int arr1[], int arr2[], int n, int m, int k)
    {
        int l1=0; 
        int count=0;
        int l2=0;
        int ans=-1;
        while(l1<n && l2<m)
        { 
            
            if(arr1[l1]<=arr2[l2])
            {
                count++; 
                if(count==k) 
                ans=arr1[l1];
                l1++;
            }
            else 
            {
                count++; 
                if(count==k) 
                ans=arr2[l2];
                l2++;
            }
        } 
        while(l1<n)
        {
            count++; 
            if(count==k) 
                ans=arr1[l1];
            l1++;
            
        }
        while(l2<m)
        {
            count++; 
            if(count==k) 
                ans=arr2[l2];
            l2++;
            
        }
        return ans;
    }
};

// { Driver Code Starts.
 
// Driver code
int main()
{
	int t;
	cin>>t;
	while(t--){
		int n,m,k;
		cin>>n>>m>>k;
		int arr1[n],arr2[m];
		for(int i=0;i<n;i++)
			cin>>arr1[i];
		for(int i=0;i<m;i++)
			cin>>arr2[i];
		
		Solution ob;
        cout << ob.kthElement(arr1, arr2, n, m, k)<<endl;
	}
    return 0;
}  // } Driver Code Ends