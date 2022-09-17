class Solution { 
    private:
    int n,m;
public:
    int maximumScore(vector<int>& nums, vector<int>& mul) {
         n=nums.size();
         m=mul.size(); 
        vector<int>prev(m+1,0);
       vector<int>curr(m+1,0);
        for(int i=n-1;i>=0;--i){
            for(int j=m-1;j>=i;--j){
                int pick=0;
                int not_pick=0; 
                pick=nums[i]*mul[j]+prev[j+1];
                not_pick=nums[n-(j-i)-1]*mul[j]+curr[j+1];
                curr[j]=max(pick,not_pick);
            } 
            prev=curr;
        }
        return prev[0];
    }
};