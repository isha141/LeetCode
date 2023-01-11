class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        vector<int>ans;
        int n=nums.size();
        int count1=0;
        int first=INT_MAX;
        int second=INT_MAX;
        int count2=0;
        for(int i=0;i<n;++i){
            if(count1==0 && nums[i]!=second){
                first=nums[i];
            }
            if(first==nums[i]){ count1++; continue;}
           else if(count2==0){
                second=nums[i];
            }
            if(second==nums[i]){
                count2++; 
                continue;
            }
            else{
                count1--; //[2,2,1,3]
                count2--;
            }
        }
         count1=0;
        count2=0;
        for(auto itr: nums){
            if(itr==first) count1++;
            if(itr==second) count2++;
        }  
        // cout<<first<<" "<<second<<endl;
        if(count1>n/3)
            ans.push_back(first);
        if(count2>n/3)
            ans.push_back(second);
        sort(ans.begin(),ans.end());
        return ans;
    }
};