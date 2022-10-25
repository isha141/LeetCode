class Solution {
public:
    bool arrayStringsAreEqual(vector<string>& w1, vector<string>& w2) {
        string a="";
        string b="";
        for(auto it: w1)
            a+=it;
        for(auto it: w2)
            b+=it;
        //sort(a.begin(),a.end());
        //sort(b.begin(),b.end());
        return a==b;
    }
};