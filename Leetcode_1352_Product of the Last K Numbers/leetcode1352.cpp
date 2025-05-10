#include<iostream>
#include<vector>
#include<fstream>
#include<string>
#include<sstream>

using namespace std;

class ProductOfNumbers {
public:
    vector<int> prefixProduct;

    ProductOfNumbers() {
        prefixProduct = vector<int>{};
    }
    
    void add(int num) {
        if(prefixProduct.size() == 0){
            prefixProduct.push_back(num);
            return;
        }

        if(num == 0){
            prefixProduct = vector<int>{0};
        }
        else{
            if(prefixProduct[prefixProduct.size() - 1] == 0){
                prefixProduct.push_back(num);
            }
            else{
                prefixProduct.push_back(prefixProduct[prefixProduct.size() - 1] * num);
            }
        }
        return;
    }
    
    int getProduct(int k) {
        if(k > prefixProduct.size()) return 0;
        else if(k == prefixProduct.size()){
            if(prefixProduct[0] == 0) return 0;
            else return prefixProduct[prefixProduct.size() - 1];
        }
        else{
            if(prefixProduct[prefixProduct.size() - 1 - k] == 0) return prefixProduct[prefixProduct.size() - 1];
            else return prefixProduct[prefixProduct.size() - 1] / prefixProduct[prefixProduct.size() - 1 - k];
        }
        return -1;
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
    ProductOfNumbers sol;
    while(getline(testcase, input)){

    }
    testcase.close();
    return 0;
}