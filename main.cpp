#include <iostream>
#include <vector>
#include <cmath>
#include "WaveSpectrum.h"
#include "Jonswap.h"



int main() {
    double Hs = 5.6;
    double Tm = 7.1;
    int nOmega = 100;
    Jonswap<double> spectrum(100, Hs, Tm);
    // std::vector<double> v = spectrum.getSpectrum();
    for (auto val: spectrum.getSpectrum()){
        std::cout << val << '\n';
    }



    return 0;
}
