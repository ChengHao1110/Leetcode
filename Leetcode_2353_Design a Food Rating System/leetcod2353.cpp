#include<iostream>
#include<vector>
#include<fstream>
#include<string>
#include<sstream>
#include<unordered_map>
#include<algorithm>
#include<queue>

using namespace std;

class CMP{
public:
    bool operator()(const pair<int, string> &p1, const pair<int, string> &p2){
        if(p1.first < p2.first) return true;
        else if(p1.first > p2.first) return false;
        else{
            if(p1.second >= p2.second) return true;
            else return false;
        }
    }
};

class FoodRatings {
public:
    unordered_map< string, priority_queue<pair<int, string>, vector<pair<int, string>>, CMP> > table;
    unordered_map<string, int> curFoodRatings;
    unordered_map<string, string> type;

    FoodRatings(vector<string>& foods, vector<string>& cuisines, vector<int>& ratings) {
        for(int i = 0; i < foods.size(); i++){
            if(table.find(cuisines[i]) == table.end()){
                priority_queue<pair<int, string>, vector<pair<int, string>>, CMP> q;
                q.push({ratings[i], foods[i]});
                table.insert({cuisines[i], q});
            }
            else{
                table[cuisines[i]].push({ratings[i], foods[i]});
            }
            type.insert({foods[i], cuisines[i]});
            curFoodRatings.insert({foods[i], ratings[i]});
        }
    }
    
    void changeRating(string food, int newRating) {
        curFoodRatings[food] = newRating;
        table[type[food]].push({newRating, food});
    }
    
    string highestRated(string cuisine) {
        priority_queue q = table[cuisine];
        
        // if not equal -> obsolete
        while(q.top().first != curFoodRatings[q.top().second]){
            q.pop();
        }

        return q.top().second;
    }
};

/*
class FoodRatings {
    // Map food with its rating.
    unordered_map<string, int> foodRatingMap;
    // Map food with the cuisine it belongs to.
    unordered_map<string, string> foodCuisineMap;

    // Store all food of cuisine in set (to sort them on ratings/name)
    // Set element -> Pair: (-1 * foodRating, foodName)
    unordered_map<string, set<pair<int, string>>> cuisineFoodMap;

public:
    FoodRatings(vector<string>& foods, vector<string>& cuisines, vector<int>& ratings) {
        for (int i = 0; i < foods.size(); ++i) {
            // Store 'rating' and 'cuisine' of current 'food' in 'foodRatingMap' and 'foodCuisineMap' maps.
            foodRatingMap[foods[i]] = ratings[i];
            foodCuisineMap[foods[i]] = cuisines[i];
            // Insert the '(-1 * rating, name)' element in current cuisine's set.
            cuisineFoodMap[cuisines[i]].insert({ -ratings[i], foods[i] });
        }
    } 

    void changeRating(string food, int newRating) {
        // Fetch cuisine name for food.
        auto cuisineName = foodCuisineMap[food];

        // Find and delete the element from the respective cuisine's set.
        auto oldElementIterator = cuisineFoodMap[cuisineName].find({ -foodRatingMap[food], food });
        cuisineFoodMap[cuisineName].erase(oldElementIterator);

        // Update food's rating in 'foodRating' map.
        foodRatingMap[food] = newRating;
        // Insert the '(-1 * new rating, name)' element in respective cuisine's set.
        cuisineFoodMap[cuisineName].insert({ -newRating, food });
    }
    
    string highestRated(string cuisine) {
        auto highestRated = *cuisineFoodMap[cuisine].begin();
        // Return name of the highest rated 'food' of 'cuisine'.
        return highestRated.second;
    }
};
*/

int main(){

    return 0;
}