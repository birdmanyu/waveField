#include<iostream>
#include<vector>
#include<cmath>
using namespace std;

int main(int argc, char const *argv[]) {
    // std::vector<int> a{1,2,3,4};
    // std::vector<int> b;
    //
    // b = a;
    // for (int val: b){
    //     std::cout << val << std::endl;
    // }
    //
    // std::cout << pow(double(3), double(-4)) << std::endl;


    auto linspace = [=](double a, double b, int n){
        vector<double> arr;
        double step = (b-a) / (n-1);
        while (a<=b){
            arr.push_back(a);
            a += step;
        }
        return arr;
    };
    vector<double> arr;
    arr = linspace(0.1, 10, 20);
    for (auto val: arr){
        cout << val << endl;
    }



    return 0;
}
