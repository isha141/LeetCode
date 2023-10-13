class Solution {
public:
    vector<int> fullBloomFlowers(vector<vector<int>>& flowers, vector<int>& people) {
        vector<int>ans;
        vector<int>pp(people.begin(),people.end());
        sort(people.begin(),people.end());
        sort(flowers.begin(),flowers.end());
        int i=0;
        int n=flowers.size();
        int m=people.size();
        map<int,int>mp;
        priority_queue<int,vector<int>,greater<int>>pq;
        for(int j=0;j<m;++j){
            while(i<n && flowers[i][0]<=people[j]){
                pq.push({flowers[i][1]});
                i++;
            }
            while(!pq.empty() && pq.top()<people[j])
                pq.pop();
            mp[people[j]]=pq.size();
        }
        for(auto i=0;i<m;++i){
            ans.push_back(mp[pp[i]]);
        }
         return ans;
    }
};