class Solution {
public:
    string intToRoman(int num) {
        string ans="";
        vector<int>v1={1000,900,500,400,100,90,50,40,10,9,5,4,1};
        vector<string>v2={"M","CM","D","CD","C","XC","L","XL","X","IX","V","IV","I"};
        int n=v1.size();
        for(int i=0;i<n;++i){ 
               // cout<<i<<" "<<v1[i]<<endl; 
               // cout<<num<<" #"<<v1[i]<<endl;
            while(num>=v1[i]){ 
                // cout<<"ijs";
                ans+=v2[i];
                num-=v1[i];
            }
        }
        return ans;
        
    }
};