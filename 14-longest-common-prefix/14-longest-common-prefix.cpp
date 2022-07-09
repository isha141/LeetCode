class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        
        string ans="";  
        sort(strs.begin(),strs.end());
        string a=strs[0];
        string b=strs[strs.size()-1]; 
        // cout<<a<<" "<<b<<endl;
         int n=a.size();
        for(int i=0;i<n;++i){ 
            if(a[i]==b[i])
                ans+=a[i];
            else
                break;
            // cout<<"hy"<<endl;
        }
        return ans;
        
    }
};
// class Solution {
// public:
//     string longestCommonPrefix(vector<string>& strs) {
//         sort(strs.begin(),strs.end());
//         string ans="";
//         string a=strs[0];
//         string b=strs[strs.size()-1];
//         int n=a.size(); 
//         cout<<a<<" hy"<<b<<endl;
//         for(int i=0;i<n;i++)
//         {
//             if(a[i]==b[i])
//                 ans+=a[i];
//             else
//                 break;
//         }
//         return ans;
//     }
// };