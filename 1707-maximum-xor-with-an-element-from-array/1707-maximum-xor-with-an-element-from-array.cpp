class trie{
    public:
    trie *links[2];
    public:
    bool containskey(int i){
        return links[i]!=NULL;
        
    }
    trie *refrenced(int i){
        return links[i];
    }
    void create(int i,trie * root){
       links[i]=root;
    } 
};
class Solution {
    trie *root;
    
    private: 
    void insert(int nums){
           trie *node=root; 
        for(int i=31;i>=0;--i){
            int set=(nums>>i)&1;
            if(node->containskey(set))
            {
                node=node->refrenced(set);
            }
            else{
                node->create(set,new trie());
                node=node->refrenced(set);
            }
        }   
    } 
    int get_max(int num){
        int ans=0; 
        trie * node=root;
        if(node==NULL) return -1;
        for(int i=31;i>=0;--i){
            int set=(num>>i)&1;
            if(node->containskey(!set)){
                ans=ans|(1<<i); 
                node=node->refrenced(!set);
            }
            else
            node=node->refrenced(set);
        }
        return ans;
    }
    
public:
     Solution(){
        root=new trie();
     }
    vector<int> maximizeXor(vector<int>& nums, vector<vector<int>>& q) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        int i=0;
        vector<vector<int>>ds;
        int m=q.size();
        for(auto itr: q){
            ds.push_back({itr[1],itr[0],i++});
        }
        sort(ds.begin(),ds.end());
        vector<int>ans(m,-1);
        i=0;
        for(auto itr: ds){
            int val=itr[1];
            int maxi=itr[0];
            int ind=itr[2];
            while(i<n && maxi>=nums[i]){
                insert(nums[i]);
                i++;
            } 
            if(i==0){
                ans[ind]=-1;
                continue;
            }
            int res=get_max(val);
            ans[ind]=res;
        }
         return ans;
    }
};