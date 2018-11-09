#ifndef WAVE_FIELD_H
#define WAVE_FIELD_H

template<typename T>
class WaveField{
private:
    int nx;
    int ny;
    T Lx;
    T Ly;

public:
    WaveField(int nx_in, int, ny_in, T Lx_in, T ly_in, WaveSpectrum<T> &S, DirectionalSpectrum<T> &D);
    void setWaveSpectrum();
    void setDirectionalSpectrum();
    void propagate(T time);
    void printZeta();
};

template<typename T>
WaveField<T>::WaveField(int nx_in, int, ny_in, T Lx_in, T ly_in, WaveSpectrum<T> &S, DirectionalSpectrum<T> &D){
    nx = nx_in;
    ny = ny_in;
    Lx = Lx_in;
    Ly = Ly_in;

    this->setWaveSpectrum(S);
    this->setDirectionalSpectrum(D);
}

template<typename T>
void WaveField<T>::setWaveSpectrum(WaveSpectrum<T> &S){
    
}


#endif
