#include<iostream>
#include<vector>
#include<fstream>
#include<string>
#include<sstream>
#include<unordered_map>
#include<iterator>

using namespace std;

class Solution {
public:
    int countTrapezoids(vector<vector<int>>& points) {
        unordered_map<long long, long long> coordinateY;
        long long m = 1000000007, ans = 0;
        for(int i = 0; i < points.size(); i++){
            coordinateY[points[i][1]]++;
        }

        //(a + b + c)? = a? + b? + c? + 2(ab + bc + ca)
        //ab + bc + ca = ((a + b + c)? - (a? + b? + c?)) / 2
        unordered_map<long long, long long>::iterator iter;
        long long sum = 0, squareSum = 0;
        for(iter = coordinateY.begin(); iter != coordinateY.end(); iter++){
            long long cnt = Count((*iter).second);
            sum += cnt;
            squareSum += cnt * cnt;
        }
        ans = (sum * sum - squareSum) / 2;
        return ans % m;
    }

    long long Count(long long n){
        return n * (n - 1) / 2;
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