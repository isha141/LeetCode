//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{ 
     int d=256;
    public:
        vector <int> search(string pat, string txt)
        {
            //code here. 
            int n=txt.size();
            int m=pat.size();
            vector<int>ans;
            int low=1;
            int h=1;
            int p=0;
            int t=0; 
            int q=INT_MAX;
            for(int i=0;i<m-1;++i){
                h=(h*d)%q;
            }
            for(int i=0;i<m;++i){
                p=(d*p+pat[i]-'a')%q;
                t=(d*t+txt[i]-'a')%q;
            }
            for(int i=0;i<=n-m;++i){
                if(p==t){ 
                    int j=0;
                    for( j=0;j<m;++j){
                        if(pat[j]!=txt[i+j]){
                            break;
                        }
                    }
                    if(j==m){
                        ans.push_back(i+1);
                    }
                }
                if(i<(n-m)){
                    t=(d*(t- (txt[i]-'a')*h)+ txt[i+m]-'a')%q;
                } 
                if(t<0){
                    t=(t+q);
                }
            }
            if(ans.size()==0) 
            return {-1};
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