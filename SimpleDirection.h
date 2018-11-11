#ifndef SIMPLE_DIRECTION_H
#define SIMPLE_DIRECTION_H
#define PI 3.14159265358979323846

template<typename T>
class SimpleDirection: public DirectionalDistribution<T>{
private:
    std::vector<T> theta;   // wave angle
    std::vector<T> f; // Directional distribution function

public:
    SimpleDirection(int nTheta);
    void computeDistribution();
    std::vector<T> getDistribution();
    std::vector<T> getTheta(){return theta;}
};


// Implementations
template<typename T>
SimpleDirection<T>::SimpleDirection(int nTheta){
    theta = linspace<T>(-PI/2, PI/2, nTheta);
    this->computeDistribution();
}

template<typename T>
void SimpleDirection<T>::computeDistribution(){
    T f_temp;
    f.reserve(theta.size());    // reserve places for vector
    for (int i=0; i<theta.size(); i++){
        f_temp = (T)2/PI*pow(cos(theta[i]), (T)2);
        f.push_back(f_temp);
    }
}

template<typename T>
std::vector<T> SimpleDirection<T>::getDistribution(){
    return f;
}

#endif
