class Solution {
public:
    int longestPalindrome(vector<string>& words) {
        map<string,int>mp;
        for(auto itr: words)
            mp[itr]++;
         int c=0;
        int flag=0; 
        set<string>s;
        for(auto itr: mp){
            string temp=itr.first; 
            // cout<<temp<<" ";
            reverse(temp.begin(),temp.end());
            int len=temp.length();
            if(temp==itr.first && s.find(temp)==s.end()){
                if(itr.second>1){
                c+=(itr.second/2)*len*2;
                }
                if(itr.second%2){
                    flag=max(flag,len);
                }
                s.insert(temp);
                continue;
            }
            if(mp.find(temp)!=mp.end() && s.find(temp)==s.end()){
                int t=min(mp[temp],mp[itr.first]);
                c+=t*2*temp.length();
                // mp.erase(itr.first);
                // mp.erase(temp); 
                // cout<<c<<endl;
                s.insert(itr.first);
                s.insert(temp);
            } 
            
        }
        // cout<<flag<<" ";
        return c+flag;
    }
};