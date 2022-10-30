class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& n1, vector<int>& n2) {
        vector<int>ans;
        int m=n1.size(); 
        int n=n2.size();
        stack<int>s;
        map<int,int>mp;
        for(int i=n-1;i>=0;--i){
            while(!s.empty() && s.top()<n2[i])
                s.pop();
            if(s.empty())
                mp[n2[i]]=-1;
            else
                mp[n2[i]]=s.top(); 
            s.push(n2[i]);
        }
        for(int i=0;i<m;++i){
            ans.push_back(mp[n1[i]]);
        }
        return ans;
    }
};