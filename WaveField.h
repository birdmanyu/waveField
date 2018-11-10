#ifndef WAVE_FIELD_H
#define WAVE_FIELD_H

template<typename T>
class WaveField{
private:
    int nx;     // number of vertices in the x-direction
    int ny;     // number of vertices in the y-direction
    T Lx;
    T Ly;
    std::vector<T> x;
    std::vector<T> y;
    std::vector<T> zeta;
    T tend;
    int numT;

public:
    WaveField(int nx_in, int, ny_in, T Lx_in, T Ly_in, T tend_in, int numT_in, WaveSpectrum<T> &S, DirectionalSpectrum<T> &D);
    // void setWaveSpectrum();
    // void setDirectionalSpectrum();
    void propagate();
    //void printZeta();
};

template<typename T>
WaveField<T>::WaveField(int nx_in, int, ny_in, T Lx_in, T Ly_in, T tend_in, int numT_in, WaveSpectrum<T> &S, DirectionalSpectrum<T> &D){
    nx = nx_in;
    ny = ny_in;
    Lx = Lx_in;
    Ly = Ly_in;
    tend = tend_in;
    numT = numT_in;
    zeta.reserve(nx*ny);
    x = linspace<T>((T)-Lx/2, Lx/2, nx);
    std::vector<T> v_temp;
    for (int i = 0; i < ny-1; i++){
        v_temp = linspace<T>((T)-Lx/2, Lx/2, nx);
        x = x.insert(x.end(), v_temp.begin(), v_temp.end());
    }



    x = linspace<T>((T)-Lx/2, Lx/2, nx);
    y = linspace<T>((T)0, Ly, ny);



    // this->setWaveSpectrum(S);
    // this->setDirectionalSpectrum(D);
}

template<typename T>
WaveField<T>::propagate(){
    t = linspace<T>((T)0, tend, numT);

}

// template<typename T>
// void WaveField<T>::setWaveSpectrum(WaveSpectrum<T> &S){
//
// }


#endif
