#include<iostream>
#include<vector>
#include<fstream>
#include<string>
#include<sstream>
#include<queue>
#include<unordered_map>

using namespace std;

class Material{
public:
    vector<string> egde;
    int connected;
    bool target;

    Material(){
        egde.clear();
        connected = 0;
        target = false;
    }
};

class Solution {
public:
    vector<string> findAllRecipes(vector<string>& recipes, vector<vector<string>>& ingredients, vector<string>& supplies) {
        unordered_map<string, Material> table;
        for(string s : supplies){
            Material m;
            table.insert({s, m});
        } 
        for(string s : recipes){
            Material m;
            m.target = true;
            table.insert({s, m});
        }
        for(int i = 0; i < recipes.size(); i++){
            for(int j = 0; j < ingredients[i].size(); j++){
                table[recipes[i]].connected++;
                table[ingredients[i][j]].egde.push_back(recipes[i]);
            }
        }
        queue<Material> q;
        vector<string> ans;
        for(int i = 0; i < supplies.size(); i++) q.push(table[supplies[i]]);
        while(!q.empty()){
            Material curFood = q.front();
            q.pop();
            for(int i = 0; i < curFood.egde.size(); i++){
                table[curFood.egde[i]].connected--;
                if(table[curFood.egde[i]].connected == 0){
                    if(table[curFood.egde[i]].target) ans.push_back(curFood.egde[i]);
                    q.push(table[curFood.egde[i]]);
                }
            }
        }

        return ans;
    }
};

int main(){
    ifstream testcase;
    testcase.open("test.txt");
    if(testcase.fail()){
        cout << "input file cannot open." << endl;
        exit(1);
    }

    string input;
    Solution sol;
    while(getline(testcase, input)){

    }
    testcase.close();
    return 0;
}