#include "awgn.h"
#include <vector>
#include <complex>
#include <random>

std::vector<std::complex<double>> AWGN::addNoise(const std::vector<std::complex<double>>& constellation)
{
    std::vector<std::complex<double>> noisyConstellation;
    std::random_device rdI, rdQ;
    std::default_random_engine generatorI(rdI()), generatorQ(rdQ());
    std::normal_distribution<double> distribution(0.0, variance);

    for (std::complex<double> point : constellation) {
        double realPart = point.real() + distribution(generatorI);
        double imagPart = point.imag() + distribution(generatorQ);
        noisyConstellation.push_back(std::complex<double>(realPart, imagPart));
    }

    return noisyConstellation;
}
