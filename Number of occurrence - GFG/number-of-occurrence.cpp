//{ Driver Code Starts
#include<bits/stdc++.h>

using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution{
public:	
	/* if x is present in arr[] then returns the count
		of occurrences of x, otherwise returns 0. */
	int count(int arr[], int n, int x) {
	    // code here 
	    int count=0;
	    int low=0;
	    int high=n-1;
	    while(low<=high){
	        int mid=(low+high)>>1;
	        if(arr[mid]==x){
	            int j=mid;
	            while(j>=0 && arr[j]==x){
	                count+=1;
	                j--;
	            }
	            j=mid+1;
	            while(j<n && arr[j]==x){
	                count+=1;
	                j++;
	            }
	            return count;
	        }
	        else if(arr[mid]<x){
	            low=mid+1;
	        }
	        else{
	            high=mid-1;
	        }
	    }
	    return 0;
	}
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, x;
        cin >> n >> x;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.count(arr, n, x);
        cout << ans << "\n";
    }
    return 0;
}

// } Driver Code Ends