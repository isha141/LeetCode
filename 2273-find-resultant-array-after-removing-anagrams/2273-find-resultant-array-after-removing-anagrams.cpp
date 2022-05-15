class Solution {
public:
    vector<string> removeAnagrams(vector<string>& words) {
        for(int i=0;i<words.size()-1;i++)
        {
            if(multiset<char>(words[i].begin(),words[i].end())==multiset<char>(words[i+1].begin(),words[i+1].end()))
            {
                words.erase(words.begin()+i+1);
                i--;
            }
        }
        return words;
    }
};