//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
	public:
		string FirstNonRepeating(string a){
		    // Code here 
		   string ans="";
		   int n=a.size(); 
		   queue<char>q; 
		   ans+=a[0];  
		   map<char,int>mp;
		  mp[a[0]]++; 
		  q.push(a[0]);
		  for(int i=1;i<n;++i){ 
		      mp[a[i]]++;
		     while(!q.empty() && mp[q.front()]>1){
		         q.pop();
		     }
		     if(q.empty() && mp[a[i]]<=1){
		         ans+=a[i]; 
		         //continue;
		     }
		     else if (q.empty()){
		       ans+='#';
		      // continue;
		     }
		     else{
		     ans+=q.front();  
		  //   continue;
		     }
		     if(mp.find(a[i])==mp.end()|| mp[a[i]]<=1)
		      q.push(a[i]);
		  }
		  return ans;
	}

};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		string A;
		cin >> A;
		Solution obj;
		string ans = obj.FirstNonRepeating(A);
		cout << ans << "\n";
	}
	return 0;
}
// } Driver Code Ends