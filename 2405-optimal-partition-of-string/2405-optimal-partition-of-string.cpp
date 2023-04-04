class Solution {
public:
    int partitionString(string s) {
        int c=0;
        int i=0;
        int n=s.size();
        while(i<n){
            map<char,int>mp;
            int j=i;
            while(j<n){
                if(mp.find(s[j])!=mp.end()){
                    break;
                }
                else{
                    mp[s[j]]++;
                }
                j++;
            }
            c++;
            i=j;
        }
        return c;
    }
};