#include<iostream>
#include<vector>
#include<fstream>
#include<string>
#include<sstream>

using namespace std;

class Solution {
public:
    vector<int> diffWaysToCompute(string expression) {
        vector<int> frac;
        string curVal = "";
        for(int i = 0; i < expression.length(); i++){
            if(expression[i] >= '0' && expression[i] <= '9') curVal += expression[i];
            else{
                frac.push_back(stoi(curVal));
                curVal = "";
                if(expression[i] == '+') frac.push_back(100);
                else if(expression[i] == '-') frac.push_back(101);
                else frac.push_back(102);
            }
        }
        frac.push_back(stoi(curVal));

        vector<int> ans = Partition(0, frac.size()-1, frac);
        return ans;
    }

    vector<int> Partition(int l, int r, vector<int> frac){
        if(l == r) return vector<int>{frac[l]};

        vector<int> posAns;
        for(int i = l + 1; i < r; i++){
            if(frac[i] > 99){
                vector<int> left = Partition(l, i - 1, frac);
                vector<int> right = Partition(i + 1, r, frac);
                //compute
                for(int j = 0; j < left.size(); j++){
                    for(int k = 0; k < right.size(); k++){
                        switch (frac[i])
                        {
                            case 100:
                                posAns.push_back(left[j] + right[k]);
                                break;
                            case 101:
                                posAns.push_back(left[j] - right[k]);
                                break;
                            case 102:
                                posAns.push_back(left[j] * right[k]);
                                break;
                        }
                    }
                }   
            }
        }
        return posAns;
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
        vector<int> ans = sol.diffWaysToCompute(input);
        for(int n : ans) cout << n << endl;
    }
    testcase.close();
    return 0;
}