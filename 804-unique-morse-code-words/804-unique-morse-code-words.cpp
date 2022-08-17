class Solution {
public:
    int uniqueMorseRepresentations(vector<string>& words) {
        map<char,string>mp;
        mp['a']=".-";
        mp['b']="-...";
        mp['c'] =       "-.-.";
        mp['d']= "-..";
        mp['e']= ".";
        mp['f']=        "..-.";
        mp['g']="--.";
        mp['h']=  "....";
                mp['i'] =    "..";
         mp['j']=         ".---";
        mp['k']=  "-.-"; 
        mp['l']=".-..";
        mp['m']="--";
        mp['n']="-.";
        mp['o']="---";
        mp['p']=".--.";
        mp['q']="--.-";
        mp['r']=".-.";
        mp['s']= "...";
        mp['t']="-";
        mp['u']="..-";
        mp['v']="...-";
        mp['w']=".--";
        mp['x']="-..-";
        mp['y']="-.--";
        mp['z']= "--.."; 
        map<string,int>mpp;
        for(auto itr: words){
            string temp="";
            for(auto itt: itr)
                temp+=mp[itt];
            mpp[temp]++;
        }
       return mpp.size();
    }
};