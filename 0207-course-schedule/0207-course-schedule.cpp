class Solution {
public:
    bool canFinish(int num, vector<vector<int>>& pre) {
        queue<int>q;
        vector<int>indegree(num,0);
        vector<int>adj[num];
        for(int i=0;i<pre.size();++i){
            adj[pre[i][1]].push_back(pre[i][0]);
        }
        //calculate the indregree of the node
        for(int i=0;i<num;++i){
             for(auto it: adj[i]){
                 indegree[it]++;
             }
        }
        for(int i=0;i<num;++i){
            if(indegree[i]==0)
                q.push(i);
        }
        vector<int>ans;
        while(!q.empty()){
            int temp=q.front();
            q.pop();
            ans.push_back(temp);
            for(auto itr: adj[temp]){
                indegree[itr]--;
                if(indegree[itr]==0){
               q.push(itr);                    
            }
            }
        }
        if(ans.size()==num)
            return 1;
        return 0;
    }
};