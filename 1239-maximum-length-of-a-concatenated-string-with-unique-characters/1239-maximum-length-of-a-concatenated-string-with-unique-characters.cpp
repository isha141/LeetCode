class Solution { 
    int n;
    private:
    int solve(vector<string>&arr,int i=0,string temp=""){
        // if(i>=n)
            // return 0;
        int pick=0;
        int not_pick=0;
        // string t=arr[i]; 
        
        unordered_set<char>s(temp.begin(),temp.end());
        if(s.size()!=temp.size())
            return 0; 
        int ans=temp.length();
        for(int j=i;j<n;++j){
            ans=max(ans,solve(arr,j+1,temp+arr[j]));
        }
        return ans;
        
    }
public:
    int maxLength(vector<string>& arr) {
         n=arr.size();
        int ans=0; 
        string temp="";
        // map<char,int>mp;
        return solve(arr);
    }
};