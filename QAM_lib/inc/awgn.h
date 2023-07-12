#ifndef AWGN_H
#define AWGN_H

#include <vector>
#include <complex>
#include <iostream>

class AWGN {
private:
    long double sigma_noise;
public:
    AWGN():sigma_noise (1){};
    AWGN(double SNR_dB);
    AWGN(double Es, double SNR_dB);

    void set_SNR_dB(double SNR_dB);
    void set_SNR_dB(double Es, double SNR_dB);

    std::vector<std::complex<double>> addNoise(const std::vector<std::complex<double>>& constellation);
private:
    double SNR_dB_2_SNR_lin(double SNR_dB);
};

#endif // AWGN_H
