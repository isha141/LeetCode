class Solution { 
    private:
    int count=0;
    void solve(int ind,vector<int>&ans,int n)
    {
        if(ind==ans.size()){ 
            for(auto itr: ans)
                cout<<itr<<" ";
            cout<<endl;
            count++;
            return ;
        }
        for(int i=ind;i<n;++i)
        {
            if(ans[i]%(ind+1)==0 || (ind+1)%ans[i]==0)
            {
                swap(ans[i],ans[ind]);
                solve(ind+1,ans,n);
                swap(ans[i],ans[ind]);
            }
        }
    }
public:
    int countArrangement(int n) { 
        vector<int>ans;
        for(int i=1;i<=n;++i)
            ans.push_back(i);
        solve(0,ans,n);
        return count;
        
    }
};