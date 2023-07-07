class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int ele1=0; 
        int n=nums.size();
        int ele2=0;
        int n1=0;
        int n2=0;
        for(int i=0;i<n;++i){
             if(ele1==0 || n1==nums[i]){
                 ele1+=1;
                 n1=nums[i];
             }
             else{
                  ele1-=1;
             }
        }
        return n1;
    }
};