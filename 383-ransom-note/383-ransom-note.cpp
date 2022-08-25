class Solution {
public:
    bool canConstruct(string rans, string mag) {
        int m=rans.size();
        int n=mag.size();
        map<char,int>s1;
        for(auto it: mag)
            s1[it]++;
        for(auto itr: rans){
            if(s1.count(itr)==0)
                return 0; 
            else{
                s1[itr]--; 
                if(s1[itr]<=0)
                    s1.erase(itr);
            }       
        }
        return 1;
    }
};