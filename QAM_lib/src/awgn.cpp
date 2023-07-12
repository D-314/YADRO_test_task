#include "../inc/awgn.h"
#include <vector>
#include <complex>
#include <cmath>
#include <random>

AWGN::AWGN(double SNR_dB) {
    set_SNR_dB(1, SNR_dB);
}


// sigma_noise = (Es/N0)*(Fb/B);
//Es = E|S^2|;
AWGN::AWGN(double Es, double SNR_dB)
{
    set_SNR_dB(Es,SNR_dB);
}

void AWGN::set_SNR_dB(double SNR_dB) {
    set_SNR_dB(1, SNR_dB);
}


// SNR_lin = (Es/N0)*(Fb/B);
// SNR_lin = (Es/N0)
void AWGN::set_SNR_dB(double Es, double SNR_dB)
{
    sigma_noise = (Es/SNR_dB_2_SNR_lin(SNR_dB))/sqrt(2);
}

std::vector<std::complex<double>> AWGN::addNoise(const std::vector<std::complex<double>>& constellation)
{
    std::vector<std::complex<double>> noisyConstellation;
    std::random_device rdI, rdQ;
    std::default_random_engine generatorI(rdI()), generatorQ(rdQ());
    std::normal_distribution<double> distribution(0.0, sigma_noise );

    for (std::complex<double> point : constellation) {
        double realPart = point.real() + distribution(generatorI);
        double imagPart = point.imag() + distribution(generatorQ);
        noisyConstellation.push_back(std::complex<double>(realPart, imagPart));
    }

    return noisyConstellation;
}

double AWGN::SNR_dB_2_SNR_lin(double SNR_dB)
{
    return powf(10,SNR_dB/10);
}
