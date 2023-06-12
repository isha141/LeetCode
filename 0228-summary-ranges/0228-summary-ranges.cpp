class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string>ans;
         int n=nums.size();
        if(n==0) return{};
          int first=nums[0];
          int last=nums[0];
          for(int i=1;i<n;++i){
              if(last+1==nums[i]){
                 last=nums[i];
                 continue;
             }
              else{
                  if(first!=last){
                        string temp="";
                      temp+=to_string(first);
                       temp+="->";
                       temp+=to_string(last); 
                      ans.push_back(temp); 
                  }
                  else{
                      string temp="";
                       temp+=to_string(first);
                       ans.push_back(temp);
                  }  
                  first=nums[i];
                  last=nums[i];
              }
          } 
        if(first!=INT_MIN){
             if(first!=last){
                        string temp="";
                      temp+=to_string(first);
                       temp+="->";
                       temp+=to_string(last); 
                      ans.push_back(temp); 
                  }
                  else{
                      string temp="";
                       temp+=to_string(first);
                       ans.push_back(temp);
                  }  
        }
        return ans;
    }
};