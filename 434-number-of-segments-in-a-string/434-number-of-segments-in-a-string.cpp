class Solution {
public:
    int countSegments(string s) {
        stringstream str(s);
        int count=0;
        string word;
        while(str>>word)
        { 
            
            count++;
        }
        return count;
    }
};