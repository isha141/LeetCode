//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends



class Solution{
	public:
		vector<string> AllPossibleStrings(string s){
                 vector<string>ans;
                  int n=s.size();
                  int subset_size=(1<<n);
                for(int i=0;i<subset_size;++i){
                      string ds="";
                      for(int j=0;j<n;++j){
                          if((1<<j) & i){
                              ds+=s[j];
                          }
                      }
                      if(ds.size()>0)
                      ans.push_back(ds);
                }
                sort(ans.begin(),ans.end());
            return ans;
		}
};






//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		string s;
		cin >> s;
		Solution ob;
		vector<string> res = ob.AllPossibleStrings(s);
		for(auto i : res)
			cout << i <<" ";
		cout << "\n";

	}
	return 0;
}
// } Driver Code Ends