#ifndef WAVE_SPECTRUM_H
#define WAVE_SPECTRUM_H

template<typename T>
class WaveSpectrum{
private:
    std::vector<T> omega;
    std::vector<T> S; // spectral density S(omega)
    T Hs;   // Significant wave height
    T Tm;   // Mean period
public:
    virtual T computeSpectrum() = 0;
    virtual T getSpectrum() = 0;
};

#endif
