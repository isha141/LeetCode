class Solution {
    private:
    int m;
    bool solve(int i,vector<int>&target,vector<string>&ans,int n,int count,int flag){
         if(i>=m){
             return 1;
         }
        // cout<<i<<"-->"<<count<<endl;
         if(target[i]==count && (flag==0 || flag==-1)){
             ans.push_back("Push");
              if(solve(i+1,target,ans,n,count+1,flag))
                   return 1;
         }
         else{
           ans.push_back("Push");
           ans.push_back("Pop");
           if(solve(i,target,ans,n,count+1,flag))
                return 1;
         }
        return 0;
    }
public:
    vector<string> buildArray(vector<int>& target, int n) {
        vector<string>ans;
         m=target.size();
        stack<int>s;
        solve(0,target,ans,n,1,-1);
        return ans;
    }
};