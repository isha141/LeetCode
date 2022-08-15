class Solution {
public:
    int ladderLength(string begin, string end, vector<string>& list) {
        set<string>st;
        for(auto itr: list)
            st.insert(itr);
        queue<string>q;
        q.push(begin);
        int c=0; 
        if(st.count(end)==0)
            return 0;
        while(!q.empty()){
            int n=q.size();
            c++;
            while(n--){
                auto itr=q.front();
                q.pop();
                for(int i=0;i<itr.size();++i){
                    string temp=itr;
                for(char s='a';s<='z';++s){
                    temp[i]=s;
                    if(temp.compare(itr)==0)
                        continue;
                    if(temp.compare(end)==0)
                        return c+1;
                    if(st.count(temp)){
                        q.push(temp);
                        st.erase(temp);
                    }
                }
                }
            }
        }
        return 0;
    }
};