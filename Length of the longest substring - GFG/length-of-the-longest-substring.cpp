//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
    public:
    int longestUniqueSubsttr(string s){
        //code
        int n=s.size();
        int ans=0;
        int i=0;
        int j=0; 
        vector<int>ds(26,-1);
        while(j<n){
            if(ds[s[j]-'a']==-1)
              ds[s[j]-'a']=j;
              else if(ds[s[j]-'a']<i)
                  ds[s[j]-'a']=j;
              else{
                  i=ds[s[j]-'a']+1;
                 ds[s[j]-'a']=j;
              }
              ans=max(ans,j-i+1);
              j++;
        }
        return ans;
    }
};

//{ Driver Code Starts.
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		string str;
		cin>>str;
		Solution ob;
		cout<<ob.longestUniqueSubsttr(str)<<endl;
	}
	return 0;
}
// } Driver Code Ends