class Solution { 
    private:
    void solve(int ind,vector<int>& nums,int &orr, vector<int>&ds,int &count)
    { 
        if( ind==nums.size())
        { 
            if(ds.size()){
            int t=0;
            for(auto itr: ds)
            { 
                t=t|itr;
            }
            if(t==orr)
            { 
                orr=t;
                count++;
            } 
            else if(t>orr){
                count=1;
                orr=t;
            } 
            }
        }
         if(ind>=nums.size())
            return ;
        ds.push_back(nums[ind]);
        solve(ind+1,nums,orr,ds,count);
        ds.pop_back();
        solve(ind+1,nums,orr,ds,count);
        
    }
public:
    int countMaxOrSubsets(vector<int>& nums) {
        int orr=0;
        int count=0; 
        vector<int>ds;
         solve(0,nums,orr,ds,count);
        return count;
    }
};