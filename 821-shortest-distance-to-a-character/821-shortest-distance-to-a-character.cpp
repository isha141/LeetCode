class Solution { 
    private:
    int find(vector<int>&des,int i){
        int ans=INT_MAX;
        for(auto itr: des){
            ans=min(ans,abs(itr-i));
        }
        return ans;
    }
public:
    vector<int> shortestToChar(string s, char c) { 
        int n=s.size();
        vector<int>ans(n,-1);  
        vector<int>des;
        for(int i=0;i<s.size();++i)
          if(s[i]==c){
              ans[i]=0;
              des.push_back(i);
          }
        sort(des.begin(),des.end());
        for(int i=0;i<n;++i){
            if(ans[i]==0)
                continue;
            else{
                int temp=find(des,i); 
                ans[i]=temp;
            }
        }
        return ans;
        
    }
};