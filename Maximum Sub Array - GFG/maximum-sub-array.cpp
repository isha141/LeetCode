//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

// } Driver Code Ends
//User function template for C++
class Solution{
public:
	vector<int> findSubarray(int a[], int n) {
	    // code here 
	    vector<int>ans;
	    int sum=0;
	    int maxi=0;
	    vector<int>ds;
	    for(int i=0;i<n;++i){
	     if(a[i]>=0){
	    sum+=a[i];
	     ds.push_back(a[i]);
	   }
	   else{
	        if(sum>maxi){
	          maxi=sum;
	          ans=ds;
	      }
	      else if(sum==maxi && ds.size()>ans.size()){
                ans=ds;
                maxi=sum;
	      }	   
	       sum=0;
	       ds.clear();
	   }
	}
	if(sum>maxi) ans=ds;
	if(sum==maxi && ans.size()>ds.size())
	ans=ds;
    if(ans.size()>0) return ans;
    return {-1};
	}
};

//{ Driver Code Starts.

void printAns(vector<int> &ans) {
    for (auto &x : ans) {
        cout << x << " ";
    }
    cout << "\n";
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, i;
        cin >> n;
        int a[n];
        for (i = 0; i < n; i++) {
            cin >> a[i];
        }
        Solution ob;
        auto ans = ob.findSubarray(a, n);
        printAns(ans);
    }
    return 0;
}

// } Driver Code Ends