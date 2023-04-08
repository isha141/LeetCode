//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
public:
    vector<vector<string>> findSequences(string begin, string end, vector<string>& word) {
        // code here 
        vector<vector<string>>ans;
        queue<vector<string>>q;
        q.push({begin});  
        map<string,int>mp;
        for(auto itr: word)
        mp[itr]++;
        while(!q.empty()){
            int t=q.size();
             set<string>s;
            while(t--){
                auto itr=q.front();
                q.pop();
                string temp=itr.back();
                if(temp==end){
                  ans.push_back(itr);
                  continue;
                }
                for(auto itm: mp){
                    string itt=itm.first;
                     int c=0;
                    for(int i=0;i<itt.size();++i){
                        if(itt[i]!=temp[i])
                        c++;
                    }
                    if(c==1){
                        itr.push_back(itt);
                        q.push(itr);
                       itr.pop_back();
                       s.insert(itt);
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