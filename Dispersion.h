#ifndef DISPERSION_H
#define DISPERSION_H

template<typename T>
class Dispersion{
public:
    virtual void computeWaveNumber(std::vector<T> omega_in) = 0;
    virtual std::vector<T> getWaveNumber() = 0;
};

#endif
