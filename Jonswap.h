#ifndef JONSWAP_H
#define JONSWAP_H

template<typename T>
class Jonswap: public WaveSpectrum<T>{
private:
    std::vector<T> omega;
    std::vector<T> S; // spectral density S(omega)
    T Hs;   // Significant wave height
    T Tm;   // Mean period
public:
    Jonswap(std::vector<T> omega_in, T Hs_in, T Tm_in);
    T computeSpectrum();
    T getSpectrum();
};

#endif
