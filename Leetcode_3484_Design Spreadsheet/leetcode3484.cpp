#include<iostream>
#include<vector>
#include<fstream>
#include<string>
#include<sstream>

using namespace std;

class Spreadsheet {
public:
    vector<vector<int>> table;

    Spreadsheet(int rows) {
        table.resize(rows + 1, vector<int>(26, 0));
    }
    
    void setCell(string cell, int value) {
        int r, c;
        getPosition(cell, r, c);
        table[r][c] = value;
    }
    
    void resetCell(string cell) {
        int r, c;
        getPosition(cell, r, c);
        table[r][c] = 0;
    }
    
    int getValue(string formula) {
        vector<string> arr;
        bool numeric = true;
        string s = "";
        for(int i = 1; i < formula.length(); i++){
            if(formula[i] == '+'){
                arr.push_back(s);
                s = "";
            }
            else{
                s += formula[i];
            }
        }
        arr.push_back(s);

        int sum = 0;
        for(int i = 0; i < 2; i++){
            if(arr[i][0] >= 'A' && arr[i][0] <= 'Z'){
                int r, c;
                getPosition(arr[i], r, c);
                sum += table[r][c];
            }
            else{
                sum += stoi(arr[i]);
            }
        }
        
        return sum;
    }

    void getPosition(string cell, int &r, int &c){
        c = cell[0] - 'A';
        r = stoi(cell.substr(1));
    }
};

int main(){
    return 0;
}