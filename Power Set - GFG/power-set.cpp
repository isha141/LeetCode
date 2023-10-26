//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
    private:
    vector<string>ans;
    int n;
    void solve(int i,string &s,string &temp){
           if(i>=n){
               if(temp.size()>0)
             ans.push_back(temp);
             return ;
           }
           temp+=s[i];
           solve(i+1,s,temp);
           temp.pop_back();
           solve(i+1,s,temp);
           return;
    }
	public:
		vector<string> AllPossibleStrings(string s){
		      n=s.size();
		      string temp="";
		      solve(0,s,temp);
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