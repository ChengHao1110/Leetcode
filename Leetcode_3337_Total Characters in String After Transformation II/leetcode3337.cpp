#include<iostream>
#include<vector>
#include<fstream>
#include<string>
#include<sstream>

using namespace std;

class Solution {
public:
int m = 1000000007;
    int lengthAfterTransformations(string s, int t, vector<int>& nums) {
        vector<long long> freq(26, 0);
        for (char c : s)
        {
            freq[c - 'a']++;
        }

        //build transformation
        vector<vector<long long>> mat(26, vector<long long>(26, 0));
        for(int i = 0; i <26 ; i++){
            for(int j = 1; j <= nums[i]; j++){
                int idx = (i + j) % 26;
                mat[i][idx]++;
            }
        }

        vector<vector<long long>> powerMat = PowerMatrix(mat, t);
        vector<long long> result(26, 0);
        for (int i = 0; i < 26; ++i)
        {
            for (int j = 0; j < 26; ++j)
            {
                result[j] = (result[j] + freq[i] * powerMat[i][j]) % m;
            }
        }

        long long total = 0;
        for (long long val : result)
        {
            total = (total + val) % m;
        }
        
        return (int)total;
    }

    vector<vector<long long>> PowerMatrix(vector<vector<long long>> &mat, int pow){
        int n = mat.size();
        vector<vector<long long>> res(n, vector<long long>(n, 0));
        for(int i = 0; i < n; i++) res[i][i] = 1;

        while (pow > 0) 
        {
            if (pow & 1) res = Mutiply(res, mat);
            mat = Mutiply(mat, mat);
            pow >>= 1;
        }

        return res;
    }

    vector<vector<long long>> Mutiply(vector<vector<long long>> &m1, vector<vector<long long>> &m2){
        int m1Row = m1.size(), m1Col = m1[0].size(), m2Col = m2[0].size();
        vector<vector<long long>> res(m1Row, vector<long long>(m2Col, 0));
        for(int i = 0; i < m1Row; i++){
            for(int k = 0; k < m2Col; k++){
                if(m1[i][k] != 0){
                    for(int j = 0; j < m1Col; j++){
                        res[i][j] = (res[i][j] + m1[i][k] * m2[k][j]) % m;
                    }
                }
            }
        }
        return res;
    }

    /* TLE
    int lengthAfterTransformations(string s, int t, vector<int>& nums) {
        vector<long long> freq(26, 0);
        int m = 1000000007;
        for(char c : s) freq[c - 'a']++;
        while(t){
            vector<long long> temp(26, 0);
            for(int i = 0; i < 26; i++){
                if(freq[i] == 0) continue;
                for(int j = 1; j <= nums[i]; j++){
                    int idx = (i + j) % 26;
                    temp[idx] = (temp[idx] + freq[i]) % m;
                }
            }
            freq = temp;
            t--;
        }
        int ans = 0;
        for(int n : freq) ans = (ans + n) % m;
        return ans;
    }
    */
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