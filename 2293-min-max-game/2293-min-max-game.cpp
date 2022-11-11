class Solution {
public:
    int minMaxGame(vector<int>& nums) {
        int n=nums.size(); 
          vector<int>ds;
        while(nums.size()!=1){
            for(int i=0;i<nums.size()/2;i++){
                if(i%2==0){
                    ds.push_back(min(nums[2*i],nums[2*i+1]));  
                }
                else{
                    ds.push_back(max(nums[2*i],nums[2*i+1]));
                }
            }
                nums=ds; 
                for(auto itr: nums)
                    cout<<itr<<" ";
                ds.clear();
                cout<<endl;
        }
        return nums[0];
    }
};