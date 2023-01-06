class Solution {  
    long long ans=0;  
    int n;
    void merge(int low,int mid,int high,vector<int>&nums,int diff){
        int i=low; 
        int j=mid+1;
        int k=low;
        while(i<=mid && j<=high){
            if(nums[i]<=nums[j]+diff){
                ans+=high-j+1;
                i++;
            }
            else{
                j++;
            }
        }
        vector<int>temp;
        for(int i=low;i<=high;++i)
            temp.push_back(nums[i]);
        sort(temp.begin(),temp.end());
        for(auto itr: temp){
            nums[low++]=itr;
        }
        return ;
    }
    private:
    void solve(int low,int high,vector<int>&nums,int diff){
        if(low<high){
            long long mid=(low+high)>>1;
            solve(low,mid,nums,diff);
            solve(mid+1,high,nums,diff);
            merge(low,mid,high,nums,diff);
        }
    }
public:
    long long numberOfPairs(vector<int>& n1, vector<int>& n2, int diff) {
        this->n=n1.size(); 
        vector<int>nums(n,0);
        for(int i=0;i<n;++i){
            nums[i]=n1[i]-n2[i];
        }
        solve(0,n-1,nums,diff); 
        for(auto itr: nums)
            cout<<itr<<" ";
        return ans;
    }
};