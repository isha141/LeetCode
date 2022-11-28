//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

// } Driver Code Ends
//User function template for C++
class Solution{
public:
	vector<int> findSubarray(int a[], int n) {
	    // code here 
	    int left=0;
	    int i=-1e9;
	    int j=-1e9;
	    int right=0;
	    int sum=0;
	    int maxi=0;
	    while(right<n){
	        if(a[right]>=0)
	        sum+=a[right];
	        else{ 
	            if(sum==0){ 
	                left=right+1;
	                right++;
	                continue;
	            }
	            if(sum>maxi){
	                maxi=sum;
	                i=left;
	                j=right-1;
	            }
	            if(sum!=0 && sum==maxi && (right-left)>(j-i)){
	                i=left;
	                j=right-1;
	            }
	            sum=0;
	            left=right+1;
	        }
	        right++;
	    }
	    if(sum!=0 && sum>maxi){
	        i=left;
	        j=right-1;
	    } 
	    if(i==-1e9 || j==-1e9) return {-1};
	  vector<int>ans;
	  for(int k=i;k<=j;++k)
	  ans.push_back(a[k]);
	  if(ans.size()>0)
	  return ans;
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