class Solution {
public:
    int jump(vector<int>& nums) {
        int n=nums.size();
        int count=0;
        int start=0;
        int end=0;
        int maxreach=0;
        while(end<n-1){
            count++;
            for(int i=start;i<=end;++i){
                maxreach=max(maxreach,nums[i]+i);
            } 
            if(maxreach>=n-1)
                return count;
            start=end+1;
            end=maxreach;
        }
        return count;
    }
};