#include <iostream>
#include <vector>
#include <cmath>
#include "supplemental.h"
#include "WaveSpectrum.h"
#include "Jonswap.h"
#include "DirectionalDistribution.h"
#include "PoissonDirection.h"
#include "SimpleDirection.h"
#include "Dispersion.h"
#include "DeepWaterDispersion.h"
#include "Domain.h"
#include "RectangleDomain.h"



int main() {
    double Hs = 6.6;
    double Tm = 7.1;
    int nOmega = 1000;
    int nTheta = 1000;
    Jonswap<double> spectrum(nOmega, Hs, Tm);
    SimpleDirection<double> direction(nTheta);
    DeepWaterDispersion<double> dispersion(spectrum.getOmega());
    RectangleDomain<double> domain((int)10, (int)10, (double)1, (double)1);

    for (auto val: domain.getX()){
        std::cout << val << '\n';
    }
    std::cout << "-----------------------" << '\n';
    std::cout << domain.getX().size() << '\n';

    // for (auto val: spectrum.getSpectrum()){
    //     std::cout << val << '\n';
    // }
    //
    // std::cout << "-----------------------" << '\n';
    //
    // for (auto val: direction.getDistribution()){
    //     std::cout << val << '\n';
    // }
    //
    // std::cout << "-----------------------" << '\n';
    // for (auto val: dispersion.getWaveNumber()){
    //     std::cout << val << '\n';
    // }



    return 0;
}
