#include<iostream>
#include<vector>
#include<fstream>
#include<string>
#include<sstream>
#include<unordered_map>
#include<queue>

using namespace std;

class NumberContainers {
public:
    unordered_map<int, priority_queue< int, vector<int>, greater<int> >> numberToIndex;
    unordered_map<int, int> indexToNumber;
    NumberContainers() {
        numberToIndex = unordered_map<int, priority_queue< int, vector<int>, greater<int> >>();
        indexToNumber = unordered_map<int, int>();
    }
    
    void change(int index, int number) {
        indexToNumber[index] = number;
        numberToIndex[number].push(index);
    }
    
    int find(int number) {
        if(numberToIndex.find(number) != numberToIndex.end()){
            while(!numberToIndex[number].empty()){
                if(indexToNumber[numberToIndex[number].top()] == number){
                    return numberToIndex[number].top();
                }
                else{
                    numberToIndex[number].pop();
                }
            }
        }
        return -1;
    }
};
