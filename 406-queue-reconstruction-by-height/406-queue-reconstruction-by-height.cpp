  bool cmp(vector<int>&p1,vector<int>&p2){
        if(p1[0]!=p2[0])
            return p1[0]>p2[0];
        return p1[1]<p2[1];
    }
class Solution { 
  
public:
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
         vector<vector<int>>ans; 
        int n=people.size();
        sort(people.begin(),people.end(),cmp); 
        for(int i=0;i<n;++i){
            ans.insert(ans.begin()+ people[i][1],people[i]);
        }
        return ans;
    }
};