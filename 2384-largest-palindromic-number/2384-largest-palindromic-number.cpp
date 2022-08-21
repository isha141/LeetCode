class Solution {
public:
    string largestPalindromic(string num) {
        int n=num.size();
        string ans=""; 
        map<int,int>mp;
        for(auto itr:  num)
            mp[itr-'0']++;
        priority_queue<pair<int,int>>pq;
        for(auto [x,y]: mp){
            pq.push({x,y});
        } 
        int maxi=0;
        while(!pq.empty()){
            auto itr=pq.top();
              pq.pop();
                string ch=to_string(itr.first);
                if(ans.size()==0 && ch=="0")
                       continue;
                    int t=itr.second/2;
                  for(int i=0;i<t;++i)
                      ans+=ch; 
            if(itr.second%2)
                maxi=max(itr.first,maxi);
        }
        string temp=ans; 
        reverse(temp.begin(),temp.end());
        ans+=to_string(maxi);
        int s=ans.size()-1; 
        if(s*2==n){
            ans.pop_back();
        }
        ans+=temp; 
        return ans;
    }
};