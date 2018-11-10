#include <iostream>
#include <vector>
#include <cmath>
#include "supplemental.h"
#include "WaveSpectrum.h"
#include "Jonswap.h"
#include "DirectionalDistribution.h"
#include "PoissonDirection.h"
#include "Dispersion.h"
#include "DeepWaterDispersion.h"



int main() {
    double Hs = 5.6;
    double Tm = 7.1;
    int nOmega = 1000;
    int nTheta = 1000;
    double para = 0.2;
    Jonswap<double> spectrum(nOmega, Hs, Tm);
    PoissonDirection<double> direction(nTheta, para);
    DeepWaterDispersion<double> dispersion(spectrum.getOmega());

    for (auto val: spectrum.getSpectrum()){
        std::cout << val << '\n';
    }

    std::cout << "-----------------------" << '\n';

    for (auto val: direction.getDistribution()){
        std::cout << val << '\n';
    }

    std::cout << "-----------------------" << '\n';
    for (auto val: dispersion.getWaveNumber()){
        std::cout << val << '\n';
    }



    return 0;
}
