class disjoint{
    public:
    vector<int>parent;
    vector<int>rank; 
    int size;
    disjoint(int n){
        parent.resize(n,0);
        rank.resize(n,0);
        for(int i=0;i<n;++i){
            parent[i]=i;
        }
        size=n;
    }
    int findparent(int n){
        if(parent[n]==n)
             return n;
        return parent[n]=findparent(parent[n]);
    }
    void unionbyrank(int u,int v){
        u=findparent(u);
        v=findparent(v);
        if(u==v) return;
        if(rank[u]<rank[v])
            swap(rank[u],rank[v]);
        rank[u]+=1;
        parent[u]=v;
        size--;
    }
};
class Solution {
public:
    bool canTraverseAllPairs(vector<int>& nums) { 
         int n=nums.size();
        vector<int>prime(1e5+5);
         for(int i=0;i<=1e5;++i){
             prime[i]=i;
         }
        for(int i=2;i<=1e5;i+=2){
            prime[i]=2;
        }
        for(int i=3;i*i<=1e5;++i){
            if(prime[i]==i){
                for(int j=i*i;j<=1e5;j+=i)
                    prime[j]=i;
            }
        }
         disjoint ds(n);  
        map<int,int>mp;
         for(int i=0;i<n;++i){
             int ele=nums[i];
             while(ele>1){ 
                 // cout<<ele<<";;"<<endl;
                 int temp=prime[ele];
                 if(mp.find(temp)!=mp.end()){
                     ds.unionbyrank(mp[temp],i);
                 }
                 mp[temp]=i;
                 ele/=temp;
             }
         }
         return ds.size==1;
    }
};