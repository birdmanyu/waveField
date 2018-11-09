#ifndef JONSWAP_H
#define JONSWAP_H
#define PI 3.14159265358979323846

template<typename T>
class Jonswap: public WaveSpectrum<T>{
private:
    std::vector<T> omega;
    std::vector<T> S; // spectral density S(omega)
    T Hs;   // Significant wave height
    T Tm;   // Mean period
public:
    Jonswap(int nOmega, T Hs_in, T Tm_in);
    void computeSpectrum();
    std::vector<T> getSpectrum();
};

/*--------------------  Implementation -----------------*/
template<typename T>
Jonswap<T>::Jonswap(int nOmega, T Hs_in, T Tm_in){
    Hs = Hs_in;
    Tm = Tm_in;

    // Compute omega
    omega = linspace<T>(0.0001, 2*PI, nOmega);

    this->computeSpectrum();
}

template<typename T>
void Jonswap<T>::computeSpectrum(){
    T omegaP = (T)5.24/Tm;
    T Gamma = 3.3;
    T sigma;
    T A;
    T S_temp;

    // std::cout << pow(omega[0], -(T)5) << '\n';
    for (int i=0; i<omega.size(); i++){
        if (omega[i] < omegaP){
            sigma = (T)0.07;
        }else{
            sigma = (T)0.09;
        }
        A = exp(- pow( (omega[i]/omegaP - 1)/(sigma*sqrt((T)2)), (T)2) );
        S_temp = (T)155*Hs*Hs*pow(omega[i], -5)*pow(Tm, -4)
        *exp(-(T)944*pow(omega[i], -4)*pow(Tm, -4))*pow(Gamma, A);
        S.push_back(S_temp);

    }
}

template<typename T>
std::vector<T> Jonswap<T>::getSpectrum(){
    return S;
}

#endif
