class Graph { 
    vector<pair<int,int>>adj[103];
    int n;
public:
    Graph(int n, vector<vector<int>>& edges) {
         // adj.resize(n);
        this->n=n;
        for(auto itr: edges){
            adj[itr[0]].push_back({itr[1],itr[2]});
        }
    }
    
    void addEdge(vector<int> edges) {
         adj[edges[0]].push_back({edges[1],edges[2]});
    }
    
    int shortestPath(int n1, int n2) {
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        pq.push({0,n1});
        vector<int>dis(n+1,INT_MAX);
        dis[n1]=0;
        while(!pq.empty()){
            auto itr=pq.top();
            pq.pop();
            int node=itr.second;
            int cost=itr.first;
            if(node==n2)
                  return cost;
            for(auto iit: adj[node]){
                int n=iit.first;
                int weight=iit.second;
                if(dis[n]>dis[node]+weight){
                    dis[n]=dis[node]+weight;
                    pq.push({dis[n],n});
                }
            }
        }
        return -1;
    }
};

/**
 * Your Graph object will be instantiated and called as such:
 * Graph* obj = new Graph(n, edges);
 * obj->addEdge(edge);
 * int param_2 = obj->shortestPath(node1,node2);
 */