#ifndef Directional_Distribution_H
#define Directional_Distribution_H

template<typename T>
class DirectionalDistribution{
private:
    std::vector<T> theta;
    std::vector<T> f; // spectral density S(omega)

public:
    virtual void computeDistribution() = 0;
    virtual std::vector<T> getDistribution() = 0;
};

#endif
