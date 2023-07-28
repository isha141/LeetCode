class Solution { 
    private:
    int n;
    int sum=0; 
    bool ans=0;
    int solve(int i,int tot,vector<int>&nums,int j,bool flag){
        if(i==j){ 
            return nums[i];
        } 
        int l1=0;
        int l=0;
        int r=0; 
        int r1=0;
         l=nums[i]-solve(i+1,tot,nums,j,!flag);
         r=nums[j]-solve(i,tot+nums[j],nums,j-1,!flag);
        return max(l,r);
        // return 0;
    }
public:
    bool PredictTheWinner(vector<int>& nums) {
         n=nums.size();  
        if(n==1) return 1;
        sum=accumulate(nums.begin(),nums.end(),0);
         int temp= solve(0,0,nums,n-1,0);  
        if(temp>=0) return 1;
        return 0;
    }
};