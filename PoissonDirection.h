#ifndef POSSION_DIRECTION_H
#define POSSION_DIRECTION_H
#define PI 3.14159265358979323846

template<typename T>
class PoissonDirection: public DirectionalDistribution<T>{
private:
    std::vector<T> theta;   // wave angle
    std::vector<T> f; // Directional distribution function
    T para; // controlling parameter of wave angel distribution

public:
    PoissonDirection(int nTheta, T para_in);
    void computeDistribution();
    std::vector<T> getDistribution();
};


// Implementations
template<typename T>
PoissonDirection<T>::PoissonDirection(int nTheta, T para_in){
    para = para_in;
    theta = linspace<T>(0, 2*PI, nTheta);
    this->computeDistribution();
}

template<typename T>
void PoissonDirection<T>::computeDistribution(){
    T f_temp;
    f.reserve(theta.size());    // reserve places for vector
    for (int i=0; i<theta.size(); i++){
        f_temp = (T)1/((T)2*PI)*(1 - pow(para, (T)2))/(1 - 2*para*cos(theta[i]) + pow(para,(T)2));
        f.push_back(f_temp);
    }
}

template<typename T>
std::vector<T> PoissonDirection<T>::getDistribution(){
    return f;
}

#endif
