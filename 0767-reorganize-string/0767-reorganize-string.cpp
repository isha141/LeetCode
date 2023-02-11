class Solution {
public:
    string reorganizeString(string s) {
        int n=s.size();
        map<char,int>mp;
        for(auto itr: s){ 
            mp[itr]++;
        if(mp[itr]>(n+1)/2)
                return "";
        }
        priority_queue<pair<int,char>>pq; 
        for(auto itr: mp){
            pq.push({itr.second,itr.first});
        }
        string ans(n,'.'); 
             auto itr=pq.top();
             pq.pop();
        int val=itr.first;
        char ch=itr.second;
        int i=0;
            while(pq.size() || val){ 
               if(ans[i]=='.'){
                   ans[i]=ch;
                   i=(i+2)%n;
                   val--;
                if(val==0) {
                    if(pq.size()){
                        auto itr=pq.top();
                        pq.pop();
                        ch=itr.second;
                        val=itr.first;
                    }
                    else break;
                }
               }
                else
                    i=(i+1)%n;
            }  
        return ans;
    }
};