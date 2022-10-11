//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
    public:
    int findSubString(string str)
    {
        // Your code goes here   
        int n=str.size();
        int ans=n;
        set<char>s;
        for(auto itr: str)
        s.insert(itr); 
        map<char,int>mp;
        int i=0;
        int j=0;
        while(j<n){
             mp[str[j]]++;
            if(mp.size()==s.size()) {
                ans=min(ans,j-i+1); 
                // cout<<j<<" ";
                while(i<j && mp.size()==s.size()){
                    mp[str[i]]--;
                    if(mp[str[i]]<=0)
                    mp.erase(str[i]);
                    if(mp.size()==s.size()){ 
                        // cout<<i<<" "<<j<<endl;
                        ans=min(ans,(j-i));
                    }
                    i++;
                }
              } 
            j++;
        } 
        return ans;
    }
};

//{ Driver Code Starts.
// Driver code
int main() {
    int t;
    cin >> t;
    while (t--) {

        string str;
        cin >> str;
        Solution ob;
        cout << ob.findSubString(str) << endl;
    }
    return 0;
}
// } Driver Code Ends