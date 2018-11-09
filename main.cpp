#include <iostream>
#include <vector>
#include <cmath>
#include "supplemental.h"
#include "WaveSpectrum.h"
#include "Jonswap.h"
#include "DirectionalDistribution.h"
#include "PoissonDirection.h"



int main() {
    double Hs = 5.6;
    double Tm = 7.1;
    int nOmega = 100;
    int nTheta = 100;
    double para = 0.2;
    Jonswap<double> spectrum(nOmega, Hs, Tm);
    PoissonDirection<double> direction(nTheta, para);

    for (auto val: spectrum.getSpectrum()){
        std::cout << val << '\n';
    }

    std::cout << "-----------------------" << '\n';

    for (auto val: direction.getDistribution()){
        std::cout << val << '\n';
    }



    return 0;
}
