#include<iostream>
#include<vector>
#include<fstream>
#include<string>
#include<sstream>
#include<algorithm>

using namespace std;

class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
        while(count(students.begin(), students.end(), sandwiches[0]) != 0){
            while(students[0] != sandwiches[0]){
                students.push_back(students[0]);
                students.erase(students.begin());
            }
            students.erase(students.begin());
            sandwiches.erase(sandwiches.begin());
        }
        return students.size();
    }
};

int main(){
    ifstream testcase;
    testcase.open("test.txt");
    if(testcase.fail()){
        cout << "input file cannot open." << endl;;
        exit(1);
    }

    string input;
    Solution sol;
    while(getline(testcase, input)){
        stringstream ss(input);
        vector<int> stu, sand;
        int num;
        while(ss >> num) stu.push_back(num);
        ss.clear();
        ss.str("");
        getline(testcase, input);
        ss << input;
        while(ss >> num) sand.push_back(num);
        cout << "Ans: " << sol.countStudents(stu, sand) << endl;
    }
    testcase.close();
    return 0;
}