#include<iostream>
#include<vector>
#include<fstream>
#include<string>
#include<sstream>

using namespace std;

class LUPrefix {
public:
    int prefix = 0, size = 0;
    vector<bool> uploaded;
    LUPrefix(int n) {
        size = n;
        uploaded.resize(n + 1, false);
        uploaded[0] = true;
    }
    
    void upload(int video) {
        uploaded[video] = true;
    }
    
    int longest() {
        while(prefix < size && uploaded[prefix + 1]){
            prefix++;
        }
        return prefix;
    }
};

int main(){

    return 0;
}