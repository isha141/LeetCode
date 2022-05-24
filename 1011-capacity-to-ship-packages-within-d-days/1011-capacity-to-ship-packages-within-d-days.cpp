class Solution { 
private:
    int solve(int low,int mid,vector<int>&we,int days)
    {
        int sum=0; 
        int count=1;
        for(auto itr: we)
        {
            sum+=itr;  
            if(sum>mid)
            {
                count++;
                sum=itr;
            }
            if(count>days)
                return false;
        }
        return count;
    } 
public:
    int shipWithinDays(vector<int>& we, int days) {
       // sort(we.begin(),we.end());
        int low=0;
        int high=0;
        for(auto itr: we){
            low=max(low,itr);
            high+=itr;
        }
        int ans=0;
        while(low<=high)
        {
            int mid=(low+high)/2;
             if(solve(low,mid,we,days)){
                 ans=mid; 
                 high=mid-1;
             }
            else
                low=mid+1;
        }
        return ans;
    }
};