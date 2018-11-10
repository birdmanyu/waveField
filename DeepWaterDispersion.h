#ifndef DEEPWATER_DISPERSION_H
#define DEEPWATER_DISPERSION_H
#define G 9.81

template<typename T>
class DeepWaterDispersion: public Dispersion<T>{
private:
    std::vector<T> k;

public:
    DeepWaterDispersion(std::vector<T> omega_in);
    void computeWaveNumber(std::vector<T> omega_in);
    std::vector<T> getWaveNumber();
};

// Implementations
template<typename T>
DeepWaterDispersion<T>::DeepWaterDispersion(std::vector<T> omega_in){
    // omega = omega_in;
    this->computeWaveNumber(omega_in);
}

template<typename T>
void DeepWaterDispersion<T>::computeWaveNumber(std::vector<T> omega_in){
    k.reserve(omega_in.size());
    for (auto val: omega_in){
        k.push_back(pow(val, (T)2)/G);
    }
}

template<typename T>
std::vector<T> DeepWaterDispersion<T>::getWaveNumber(){
    return k;
}


#endif
