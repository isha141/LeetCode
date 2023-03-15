class Solution {
public:
    string reorganizeString(string s) {
        int n=s.size();
        map<char,int>mp;
        for(auto itr: s)
            mp[itr]++;
        for(auto itr:mp){
            if(itr.second>(n+1)/2)
                  return "";
        }
        string ans(n,'.');  
        priority_queue<pair<int,char>>pq;
        for(auto itr: mp){
            pq.push({itr.second,itr.first});
        }  
        int k=0;
        int res=2; 
         int j=k; 
        while(!pq.empty()){
            auto itr=pq.top();
            pq.pop();
            char ch=itr.second;
            int m=itr.first;
            bool flag=0;
            while(j<n && m){
                  ans[j]=ch;
                j+=res;
                m--; 
                // cout<<j<<" "<<m<<endl;
                if(j>=n && m>0){
                    j=++k;
                    flag=1;
                }
            }
            if(!flag && j>=n){
                k++; 
                j=k;
            }
        }
        return ans;
    }
};