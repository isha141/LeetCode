//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

class Solution
{
  public:
    //Function to find maximum of each subarray of size k.
    vector <int> max_of_subarrays(int *arr, int n, int k)
    {
        // your code here
        vector<int>ans;  
        deque<int>q;
        for(int i=0;i<n;++i){
            while(!q.empty() && q.front()<=i-k)
                q.pop_front();
            if(!q.empty() && arr[q.front()]<arr[i]){
                q.push_front(i);
            }
            else
            {
                while(!q.empty() && arr[q.back()]<arr[i])
                          q.pop_back();
            q.push_back(i);
            }
            if(i>=k-1){
                ans.push_back(arr[q.front()]);
            }
           
        }
        return ans;
        
        
    }
};

//{ Driver Code Starts.

int main() {
	
	int t;
	cin >> t;
	
	while(t--){
	    
	    int n, k;
	    cin >> n >> k;
	    
	    int arr[n];
	    for(int i = 0;i<n;i++) 
	        cin >> arr[i];
	    Solution ob;
	    vector <int> res = ob.max_of_subarrays(arr, n, k);
	    for (int i = 0; i < res.size (); i++) 
	        cout << res[i] << " ";
	    cout << endl;
	    
	}
	
	return 0;
}
// } Driver Code Ends