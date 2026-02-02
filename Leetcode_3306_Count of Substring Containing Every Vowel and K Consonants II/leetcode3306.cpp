#include<iostream>
#include<vector>
#include<fstream>
#include<string>
#include<sstream>
#include<unordered_map>

using namespace std;

class Solution {
public:
    long long countOfSubstrings(string word, int k) {
        long long ans = 0;
        int cnt = 0, vowels = 0, l = 0, r = 0, leftContinuousVowels = 0;
        unordered_map<char, int> table;
        table['a'] = table['e'] = table['i'] = table['o'] = table['u'] = 0;
        while(r < word.size()){
            if(isVowel(word[r])){
                if(++table[word[r]] == 1) vowels++;
            } 
            else cnt++;

            while(cnt > k){
                if(isVowel(word[l])){
                    if(--table[word[l]] == 0) vowels--;
                }
                else{
                    // remove the leftmost consonant, so leftContinuousVowels = 0
                    cnt--; 
                    leftContinuousVowels = 0; 
                }
                l++;
            }

            //check valid substring
            while(cnt == k && vowels == 5 && isVowel(word[l]) && table[word[l]] > 1){
                leftContinuousVowels++;
                table[word[l]]--;
                l++;
            }

            if (cnt == k && vowels == 5) {
                ans += (1 + leftContinuousVowels);
            }

            r++;
        }

        return ans;
    }

    bool isVowel(char ch){
        if(ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u') return true;
        return false;
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