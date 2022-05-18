class Solution {
public:
    string intToRoman(int num) {
    vector<int>dig={1000,900,500,400,100,90,50,40,10,9,5,4,1};
    vector<string>rom={"M","CM","D","CD","C","XC","L","XL","X","IX","V","IV","I"};
        string ans="";
        for(int i=0;i<dig.size();i++)
        {
           while(num>=dig[i])
           {
               ans+=rom[i];
               num-=dig[i];
           }
        }
        return ans;
    }
};