class Solution {
public:
    int uniqueMorseRepresentations(vector<string>& words) {
     vector<string>ds={".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."};
        map<string,int>mp;
        for(auto itr: words){
            string temp="";
            for(auto itt: itr)
                temp+=ds[itt-'a'];
            mp[temp]++;
        }
        return mp.size();
    }
};