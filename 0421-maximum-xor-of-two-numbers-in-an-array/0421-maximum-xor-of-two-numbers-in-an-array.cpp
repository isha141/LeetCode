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
    int findMaximumXOR(vector<int>& nums) {
        int n=nums.size();
        for(int i=0;i<n;++i){
            insert(nums[i]);
        }
        int ans=0;
        for(auto itr: nums){
            int temp=get_max(itr);
            // cout<<temp<<" "<<itr<<endl;
            ans=max(ans,temp);
        }
        return ans;
    }
};