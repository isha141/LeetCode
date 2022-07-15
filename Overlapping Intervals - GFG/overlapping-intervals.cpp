// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
public:
    vector<vector<int>> overlappedInterval(vector<vector<int>>& in) {
         // Code here 
         vector<vector<int>>ans;
         sort(in.begin(),in.end());
         int first=in[0][0];
         int second=in[0][1];
         for(int i=1;i<in.size();++i){
             if(second>=in[i][0])
             {
                 first=min(first,in[i][0]);
                 second=max(second,in[i][1]);
             }
             else{ 
                 vector<int>ds;
                 ds.push_back(first);
                 ds.push_back(second);
                 ans.push_back(ds);
                 first=in[i][0];
                 second=in[i][1];
             }
         } 
               vector<int>ds;
                 ds.push_back(first);
                 ds.push_back(second);
                 ans.push_back(ds);
        //  ans.push_back
         return ans;
    }
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<vector<int>>Intervals(n);
		for(int i = 0; i < n; i++){
			int x, y;
			cin >> x >> y;
			Intervals[i].push_back(x);
			Intervals[i].push_back(y);
		}
		Solution obj;
		vector<vector<int>> ans = obj.overlappedInterval(Intervals);
		for(auto i: ans){
			for(auto j: i){
				cout << j << " ";
			}
		}
		cout << "\n";
	}
	return 0;
}  // } Driver Code Ends