bool cmp(pair<int,int>a,pair<int,int>b){
    if(a.first==b.first)
        return a.second<b.second;
    return a.first<b.first;
};
class Solution { 
public:
    int minGroups(vector<vector<int>>& in){
        int n=in.size();
        sort(in.begin(),in.end());
        int ans=0; 
        priority_queue<int,vector<int>,greater<int>>pq;
        for(auto it: in){
            if(!pq.empty() && pq.top()<it[0])
                pq.pop();
            pq.push(it[1]);
        }
        return pq.size();
    }
};