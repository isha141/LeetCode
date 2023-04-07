//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
//User function Template for C++

class Solution{   
    private:
    bool palin(string &s){
        int i=0;
        int j=s.size()-1;
        while(i<=j){
            if(s[i]!=s[j])
             return 0;
             i++;
             j--;
        }
        return 1;
    }
public:
    int addMinChar(string str){    
        //code here 
        if(palin(str)){
            return 0;
        } 
        int j=str.size()-1;
        string ans="";
        int count=0;
        while(j>0){
            if(str[j]==str[0]){
                int i=0; 
                int k=j;
                while(i<=k){
                    if(str[i]!=str[k])
                        break;
                        i++;
                        k--;
                } 
                if(i>k)
                 return count;
                count++;
            }
            else{
                count++;
            } 
            j--;
        }
        return count;
        
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
        cin >> str;
        
        Solution ob;
        cout << ob.addMinChar(str) << endl;
    }
    return 0; 
} 
// } Driver Code Ends