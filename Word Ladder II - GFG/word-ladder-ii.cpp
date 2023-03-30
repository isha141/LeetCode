//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
public:
    vector<vector<string>> findSequences(string begin, string end, vector<string>& word) {
        map<string,int>mp;
        for(auto itr: word)
        mp[itr]++;
        queue<vector<string>>q;
        q.push({begin});
        vector<vector<string>>ans;
        while(!q.empty()){
              int n=q.size(); 
              set<string>s;
              while(n--){
                  auto itr=q.front();
                  q.pop();
                  string w=itr.back(); 
                  s.insert(w);
                  if(w==end){
                      ans.push_back(itr);
                      continue;
                  }
                  for(auto itt: mp){ 
                      int c=0;
                      string s1=itt.first;
                      for(int i=0;i<s1.size();++i){
                          if(w[i]!=s1[i])
                          c++;
                      }
                      if(c>1 || c<1)
                      continue;
                      else{
                        s.insert(s1);
                      itr.push_back(s1); 
                      q.push(itr); 
                      itr.pop_back();
                      }
                  }  
              }
              for(auto itr=s.begin();itr!=s.end();++itr)
                  mp.erase(*itr);
        } 
        return ans;
    }
};

//{ Driver Code Starts.

bool comp(vector<string> a, vector<string> b)
{
    string x = "", y = "";
    for(string i: a)
        x += i;
    for(string i: b)
        y += i;
    
    return x<y;
}

int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<string>wordList(n);
		for(int i = 0; i < n; i++)cin >> wordList[i];
		string startWord, targetWord;
		cin >> startWord >> targetWord;
		Solution obj;
		vector<vector<string>> ans = obj.findSequences(startWord, targetWord, wordList);
		if(ans.size()==0)
		    cout<<-1<<endl;
		else
		{
		    sort(ans.begin(), ans.end(), comp);
            for(int i=0; i<ans.size(); i++)
            {
                for(int j=0; j<ans[i].size(); j++)
                {
                    cout<<ans[i][j]<<" ";
                }
                cout<<endl;
            }
		}
	}
	return 0;
}
// } Driver Code Ends