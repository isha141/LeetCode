class Solution {
public:
    string orderlyQueue(string s, int k) {
        int n=s.size();
        if(k>1){
            sort(s.begin(),s.end());
        return s;
        }
        else{
            string temp=s;
            for(int i=1;i<s.size();++i){
                temp=min(temp,s.substr(i)+s.substr(0,i));
            }
            return temp;
        }
        return s;
    }
};