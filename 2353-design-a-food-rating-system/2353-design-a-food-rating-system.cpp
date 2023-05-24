class FoodRatings {
    private:
    map<string,int>ratings; 
    map<string,set<pair<int,string>>>mp;
    map<string,string>food;
public:
    FoodRatings(vector<string>& foods, vector<string>& cui, vector<int>& rat) {
            int n=foods.size();
            for(int i=0;i<n;++i){
                ratings[foods[i]]=rat[i];   // foods->rating 
                mp[cui[i]].insert({-rat[i],foods[i]}); 
                food[foods[i]]=cui[i];
            } 
    }
    void changeRating(string f, int newr) {
           int currentrating=ratings[f];  
           string q=food[f];
           mp[q].erase(mp[q].find({-currentrating,f}));
           ratings[f]=newr;
           mp[q].insert({-newr,f});
           
    }
    
    string highestRated(string cuisine) {
        string temp=mp[cuisine].begin()->second;
         return temp;
    }
};

/**
 * Your FoodRatings object will be instantiated and called as such:
 * FoodRatings* obj = new FoodRatings(foods, cuisines, ratings);
 * obj->changeRating(food,newRating);
 * string param_2 = obj->highestRated(cuisine);
 */

// map==>   food->rating;
// set<string,