class Solution {
public:
    int ladderLength(string begin, string end, vector<string>& word) {
        set<string>s;
        for(auto itr: word){
            s.insert(itr);
        }
        if(s.find(end)==s.end())
              return 0;
        queue<string>q;
        q.push(begin);
        int ans=0;
        while(q.size()){
            int t=q.size();
            while(t--){
                auto itr=q.front();
                q.pop();
                if(itr==end)
                     return ans+1;
                for(int i=0;i<itr.size();++i){
                    string temp=itr;
                    for(char ch='a';ch<='z';++ch){
                        temp[i]=ch;
                        if(s.find(temp)!=s.end()){
                            q.push(temp);
                            s.erase(temp);
                        }
                    }
                }
            }
            ans+=1;
        }
         return 0;
    }
};