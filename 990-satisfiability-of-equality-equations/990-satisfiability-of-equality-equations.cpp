class Solution { 
    private:
    vector<int>par;
    vector<int>rank; 
 private:
    int findparent(int a) 
    {
        if(par[a]==a)
            return a;
        return par[a]=findparent(par[a]);
    }
    void Union(int a,int  b)
    {
        int u=findparent(a);
        int v=findparent(b); 
        if(u==v)
            return;
        if(rank[u]<rank[v]){
            par[u]=v; 
            // rank[u]++;
        }
        else if(rank[v]<rank[u]) {
            par[v]=u;
            // rank[v]++;
        }
        else{
          par[u]=v; 
            // we are attaching the v to the parent of u  then teh rank of v will increase 
            rank[v]++;
        }
    }
public:
    bool equationsPossible(vector<string>& e) {
        int n=e.size(); 
        par.resize(26);
        rank.resize(26); 
        for(int i=0;i<26;++i)
        {
            par[i]=i ;
            rank[i]=0;
        }
        for(auto itr: e){
            if(itr[1]=='='){
                Union(itr[0]-'a',itr[3]-'a');
            }
        }
        for(auto itr: e){
            if(itr[1]=='!'){ 
            if(findparent(itr[0]-'a')==findparent(itr[3]-'a'))
                return 0; 
        }
        }
        return 1;
    }
};