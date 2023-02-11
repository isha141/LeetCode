//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends


class Solution
{ 
    private: 
    int n;
     string ans="";
    void solve(int ind,int k,string str){
        ans=max(ans,str); 
        if(k==0 || ind>n) return  ;
        for(int i=ind;i<n-1;++i){
         for(int j=i+1;j<n;++j){
             if(str[i]<str[j]){
                 swap(str[i],str[j]);
                 solve(i+1,k-1,str);
                 swap(str[i],str[j]);
             }
         }
      }
      return ;
    }
    public:
    //Function to find the largest number after k swaps.
    string findMaximumNum(string str, int k)
    {  
         int n=str.size();
         this->n=n;
        
       // code here. 
      
       solve(0,k,str);
       return ans;
    }
};

//{ Driver Code Starts.

int main()
{
    int t, k;
    string str;

    cin >> t;
    while (t--)
    {
        cin >> k >> str;
        Solution ob;
        cout<< ob.findMaximumNum(str, k) << endl;
    }
    return 0;
}

// } Driver Code Ends