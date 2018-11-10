#ifndef WAVE_FIELD_H
#define WAVE_FIELD_H

template<typename T>
class WaveField{
private:
    int nx;     // number of vertices in the x-direction
    int ny;     // number of vertices in the y-direction
    T Lx;
    T Ly;
    std::vector<T> zeta;


public:
    WaveField(int nx_in, int, ny_in, T Lx_in, T ly_in, WaveSpectrum<T> &S, DirectionalSpectrum<T> &D);
    // void setWaveSpectrum();
    // void setDirectionalSpectrum();
    void propagate(T time);
    void printZeta();
};

template<typename T>
WaveField<T>::WaveField(int nx_in, int, ny_in, T Lx_in, T ly_in, WaveSpectrum<T> &S, DirectionalSpectrum<T> &D){
    nx = nx_in;
    ny = ny_in;
    Lx = Lx_in;
    Ly = Ly_in;
    zeta.reserve(nx*ny);

    // this->setWaveSpectrum(S);
    // this->setDirectionalSpectrum(D);
}

// template<typename T>
// void WaveField<T>::setWaveSpectrum(WaveSpectrum<T> &S){
//
// }


#endif
