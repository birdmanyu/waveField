#ifndef WAVE_SPECTRUM_H
#define WAVE_SPECTRUM_H

template<typename T>
class WaveSpectrum{
private:
    std::vector<T> omega;
    std::vector<T> S; // spectral density S(omega)

public:
    virtual void computeSpectrum() = 0;
    virtual std::vector<T> getSpectrum() = 0;
};

#endif
