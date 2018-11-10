// Linspace function
template<typename T>
std::vector<T> linspace(T a, T b, int n){
    std::vector<T> arr;
    T step = (b-a) / (n-1);
    while (a<=b){
        arr.push_back(a);
        a += step;
    }
    return arr;
};
