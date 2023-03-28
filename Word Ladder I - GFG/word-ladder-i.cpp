//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
    int wordLadderLength(string start, string target, vector<string>& word) {
        // Code here
         queue<pair<string, int>>q;
         q.push({start,0});
         map<string ,int>mp; 
         int ans=1e9; 
         mp[start]=0;
         while(!q.empty()){
             auto itr=q.front();
             q.pop(); 
             string temp=itr.first;
             int count=itr.second;
             if(temp==target){
                 ans=min(ans,count);
             }
             for(auto it: word){
                  int c=0;
                 for(auto i=0;i<it.size();++i){
                     if(temp[i]!=it[i]) 
                     c++;
                 }
                 if(c==1){
                     if(mp.find(it)!=mp.end() && mp[it]>count+1){
                         mp[it]=count+1; 
                         q.push({it,count+1});
                     } 
                     else if(mp.find(it)==mp.end()){ 
                         q.push({it,count+1});
                         mp[it]=count+1;
                     }
                 }
             }
         } 
         if(ans==1e9) return 0;
         return ans+1;
    }
};

//{ Driver Code Starts.
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
		int ans = obj.wordLadderLength(startWord, targetWord, wordList);
		cout << ans << "\n";
	}
	return 0;
}
// } Driver Code Ends