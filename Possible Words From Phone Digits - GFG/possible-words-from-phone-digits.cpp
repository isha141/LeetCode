//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
#include <string>

using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution
{ 
    private:
    void solve(int i,string &num,map<int,string>&mp,vector<string>&ans,string &res){
        // cout<<"hyhd";
        if(res.size()>=num.size()){
            // cout<<"isha";
            ans.push_back(res);
            return ;
        }
        string p=mp[num[i]-'0']; 
        // cout<<p<<endl;
        for(int j=0;j<p.size();++j){
            res+=p[j];
            // cout<<res<<",";
            solve(i+1,num,mp,ans,res);
            res.erase(res.size()-1);
        }
    }
    public:
    //Function to find list of all words possible by pressing given numbers.
    vector<string> possibleWords(int a[], int n)
    {
        //Your code here 
        // cout<<"isha";
         vector<string>ans; 
         string num;
         for(int i=0;i<n;++i)
         num+=to_string(a[i]);
        //  cout<<num<<" ";
         map<int,string>mp;
         mp[2]="abc";
         mp[3]="def";
         mp[4]="ghi";
         mp[5]="jkl";
         mp[6]="mno";
         mp[7]="pqrs";
         mp[8]="tuv";
         mp[9]="wxyz";
         string res="";
        //  vector<string>ans;
         solve(0,num,mp,ans,res);
         return ans;
    }
};


//{ Driver Code Starts.

int main() {
  
	int T;
	
	cin >> T; //testcases
	
	while(T--){ //while testcases exist
	   int N;
	    
	   cin >> N; //input size of array
	   
	   int a[N]; //declare the array
	   
	   for(int i =0;i<N;i++){
	       cin >> a[i]; //input the elements of array that are keys to be pressed
	   }
	   
	   Solution obj;
	   
	  vector <string> res = obj.possibleWords(a,N);
	  for (string i : res) cout << i << " ";
	   cout << endl;
	}
	
	return 0;
}
// } Driver Code Ends