class Solution { 
    private:
    int n;
public:
    int minimumCost(vector<int>& s, vector<int>& target, vector<vector<int>>&sp) {
         n=sp.size();
         priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq; 
        int x=s[0];
        int y=s[1];
        vector<int>dis(n,INT_MAX);
        for(int i=0;i<n;++i){
            dis[i]=abs(x-sp[i][0])+abs(y-sp[i][1])+sp[i][4];
            pq.push({dis[i],i});
        }
         int ans=abs(target[0]-x)+abs(target[1]-y);
        while(!pq.empty()){
            auto itr=pq.top();
            pq.pop();
            int node=itr.second;
            ans=min(ans,itr.first+abs(sp[node][2]-target[0])+abs(sp[node][3]-target[1]));
            for(int j=0;j<n;++j){ 
                if(node==j) continue;
                int d=abs(sp[node][2]-sp[j][0])+abs(sp[node][3]-sp[j][1])+sp[j][4];
                if(dis[j]>d+itr.first){
                    dis[j]=d+itr.first;
                    pq.push({dis[j],j});
                }
            }
        }
        return ans;
    }
};