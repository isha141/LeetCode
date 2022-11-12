//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
	public:
		int characterReplacement(string s, int k){
		    // Code here 
		    int n=s.size();
		    int ans=0;
		    vector<int>ds(26,0);
		    int i=0;
		    int j=0;
		    int maxi=0;
		    while(j<n){   
		        ds[s[j]-'A']++;
		        maxi=max(maxi,ds[s[j]-'A']); 
		        int len=j-i+1;
		        if(len-maxi<=k){
		        ans=max(ans,len);
		        j++; 
		        }
		        else { 
		            ans=0;
		            ds[s[i]-'A']-=1;
		            for(int L=0;L<26;++L)
		            maxi=max(maxi,ds[L]);
		            i++;  
		            len=j-i+1;
		            if(len-maxi<=k){
		              ans=max(ans,len);
		            }
		          //  j++;
		             j++;
		        } 
		       
		    }
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
		int k;
		cin >> k;
		Solution obj;
		int ans = obj.characterReplacement(s, k);
		cout << ans << "\n";
	}
	return 0;
}
// } Driver Code Ends