class Solution {
public:
    bool canFinish(int num, vector<vector<int>>& pre) {  
        vector<int>adj[num];
        for(int i=0;i<pre.size();++i){
                adj[pre[i][1]].push_back(pre[i][0]);
        }
        queue<int>q;
        vector<int>indegree(num,0); 
        for(int i=0;i<num;++i){
            for(auto itr: adj[i])
            {
                indegree[itr]++;
            }
        }
        for(int i=0;i<num;++i){
            if(indegree[i]==0)
                q.push(i);
        } 
        // cout<<"hy"<<endl;
        int cnt=0;
        while(!q.empty())
        {
            int temp=q.front();
            q.pop();
            cnt++;
            for(auto itr: adj[temp]){
                indegree[itr]--;
                if(indegree[itr]==0)
                    q.push(itr);
            }
        }
        return cnt==num;
    }
};