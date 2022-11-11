class Solution { 
    private:
    void solve(int i,int low,int high,vector<int>&ans,int num,int prev){
        if(num>high)
            return ;
        if(num>=low && num<=high){
        ans.push_back(num);  
            // return ;
        }
        for(int j=i;j<=9;++j){ 
            if(prev==-1 || abs(prev-j)==1)
             solve(j+1,low,high,ans,num*10+j,j); 
            else
                break;
        }
        return ;
    }
public:
    vector<int> sequentialDigits(int low, int high) {
        vector<int>ans; 
        int num=0; 
        int prev=-1;
        solve(1,low,high,ans,num,prev);
        sort(ans.begin(),ans.end());
        return ans;
    }
};