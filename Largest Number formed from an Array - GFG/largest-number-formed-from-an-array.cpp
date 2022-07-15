// { Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


 // } Driver Code Ends
//User function template for C++

bool cmp(string a,string b){
 return  a+b> b+a;
}
class Solution{
public:
	string printLargest(vector<string> &arr) {
	    string ans="";  
	    sort(arr.begin(),arr.end(),cmp);
	    for(auto itr: arr)
	    ans+=itr; 
	    if(ans[0]=='0')
	    return "0";
	    else
	    return ans;
	    
	}
};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, i;
        cin >> n;
        vector<string> arr(n);
        for (i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.printLargest(arr);
        cout << ans << "\n";
    }
    return 0;
}  // } Driver Code Ends