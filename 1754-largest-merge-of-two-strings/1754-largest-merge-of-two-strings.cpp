class Solution {
    private:
    string solve(string a,string b){
        if(a.size()==0 || b.size()==0)
             return a+b;
        if(a>b){
            return a[0]+solve(a.substr(1),b);
        }
        return b[0]+solve(a,b.substr(1));
    }
public:
    string largestMerge(string w1, string w2) {
         return solve(w1,w2);
    }
};