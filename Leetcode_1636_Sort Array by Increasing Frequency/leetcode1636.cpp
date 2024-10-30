#include<iostream>
#include<vector>
#include<fstream>
#include<string>
#include<sstream>
#include<algorithm>

using namespace std;
struct Freq{
    int id, freq;
    Freq(int i){
        id = i;
        freq = 0;
    }
};

bool cmp(Freq f1, Freq f2){
    if(f1.freq != f2.freq){
        return f1.freq < f2.freq;
    }
    else{
        return f1.id > f2.id;
    }
}

class Solution {
public:
    vector<int> frequencySort(vector<int>& nums) {
        vector<Freq> freq;
        for(int i = -100; i < 101; i++){
            Freq f(i);
            freq.push_back(f);
        }
        for(int n : nums){
            freq[n + 100].freq++;
        }
        sort(freq.begin(), freq.end(), cmp);
        vector<int> ans;
        for(Freq q : freq){
            if(q.freq != 0){
                for(int i = 0; i < q.freq; i++) ans.push_back(q.id);
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
        stringstream ss(input);
        int num;
        vector<int> arr, ans;
        while(ss >> num) arr.push_back(num);
        ans = sol.frequencySort(arr);
        for(int n : ans) cout << n << " "; cout << endl;
    }
    testcase.close();
    return 0;
}