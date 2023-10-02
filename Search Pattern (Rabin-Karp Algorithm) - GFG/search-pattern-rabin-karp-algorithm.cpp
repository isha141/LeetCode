//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{ 
    private:
    int d=256;
    public:
        vector <int> search(string pat, string txt)
        {
            int n=txt.size();
            int m=pat.size();
            int hashvalue=1;
            vector<int>ans;
            int q=INT_MAX;
            for(int i=0;i<m-1;++i){
                hashvalue=(hashvalue*d)%q;
            }
            int patternval=0;
            int textval=0;
            for(int i=0;i<m;++i){
                patternval=(d*patternval+pat[i]-'a')%q;
                textval=(d*textval+txt[i]-'a')%q;
            }
            for(int i=0;i<=n-m;++i){
                if(patternval==textval){
                    int j=0;
                    for(j=0;j<m;++j){
                        if(txt[i+j]!=pat[j]){
                            break;
                        }
                    }
                    if(j==m){
                        ans.push_back(i+1);
                    }
                }
                if(i<=(n-m)){
                    textval=(d*(textval-(txt[i]-'a')*hashvalue)+ txt[i+m]-'a')%q;
                }
                if(textval<0){
                    textval=(textval+q);
                }
            }
            if(ans.size()==0) return {-1};
            return ans;
        } 
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string S, pat;
        cin >> S >> pat;
        Solution ob;
        vector <int> res = ob.search(pat, S);
        for (int i : res) cout << i << " ";
        cout << endl;
    }
    return 0;
}

// Contributed By: Pranay Bansal

// } Driver Code Ends