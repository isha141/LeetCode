class Solution {
public:
    vector<string> cellsInRange(string s) {
        vector<string>ans;
        int maxi=max(s[1]-'0',s[4]-'0');
        int mini=min(s[1]-'0',s[4]-'0');
        char start=s[0];
        char end=s[3];
        int count=0;
        while(start<=end){
            for(int i=mini;i<=maxi;++i){
                string temp="";
                temp+=start;
                temp+=(i+'0');
                ans.push_back(temp);
            }
            // start=end;
            // count++;
            start++;
        }
        return ans;
    }
};