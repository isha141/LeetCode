class Solution {
public:
    vector<int> goodDaysToRobBank(vector<int>& sec, int time) { 
        int n=sec.size();
        vector<int>ans;
        vector<int>pre(n,0);
        vector<int>post(n,0);
        for(int i=0;i<n;++i){
            if(i-1>=0 && sec[i-1]>=sec[i])
                pre[i]=pre[i-1]+1;
        }
        for(int i=n-1;i>=0;--i){
            if(i+1<n && sec[i]<=sec[i+1])
                post[i]=post[i+1]+1;
        }
        // for(auto itr: pre)
        //     cout<<itr<<" ";
        // cout<<endl;
        // for(auto itr: post)
        //     cout<<itr<<" ";
        for(int i=0;i<n;++i){
            if(pre[i]>=time && post[i]>=time)
                ans.push_back(i);
        }
        return ans;
        
    }
};