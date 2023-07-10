//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
    //Function to find the smallest window in the string s consisting
    //of all the characters of string p.
    string smallestWindow (string s, string p)
    {
        // Your code here 
       vector<char>mp1(26,0),mp2(26,0); 
        for(auto itr: p){
            mp2[itr-'a']++;
        }
        int n=s.size(); 
        int count=0; 
        int m=p.size();
        int j=0; 
        string ans="";
        for(int i=0;i<n;++i){
             mp1[s[i]-'a']++;
            if(mp2[s[i]-'a']>0){
                if(mp1[s[i]-'a']<=mp2[s[i]-'a']){
                    count+=1;
                }
            } 
            // cout<<i<<";;"<<count<<endl;
            if(count==m){ 
                 if(ans.size()==0){
                     ans=s.substr(j,i-j+1);
                    //  cout<<ans<<":::"<<endl;
                 }
                while(j<=i && count==m){ 
                    if(ans.size()==m) return ans;
                    if(ans.size()>(i-j+1)){
                        ans=s.substr(j,i-j+1); 
                        // cout<<ans<<";;"<<endl;
                    }
                mp1[s[j]-'a']--;
                if(mp2[s[j]-'a']>0){
                    if(mp1[s[j]-'a']<mp2[s[j]-'a']){
                        count--;
                    }
                }
                j++;
            }
        }
        }
        return ans.size()>0?ans:"-1";
    }
};

//{ Driver Code Starts.
int main()
 {
    int t;
    cin>>t;
    while(t--)
    {
        string s;
        cin>>s;
        string pat;
        cin>>pat;
        Solution obj;
        cout<<obj.smallestWindow(s, pat)<<endl;
        
    }
	return 0;
}
// } Driver Code Ends