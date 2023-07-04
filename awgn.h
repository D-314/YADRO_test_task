#ifndef AWGN_H
#define AWGN_H
#include <vector>
#include <complex>
#include <iostream>
#define SIGNAL_POWER_DB 0 //equal to 1 W

class AWGN {
private:
    double variance;
public:
    AWGN() : variance(1) {};
    AWGN(double SNR_dB) : variance(powf(10,(double)(SIGNAL_POWER_DB-SNR_dB)/10)*sqrt(2)/2) {};
    void set_SNR_dB(double SNR_dB) {variance = powf(10,(double)(SIGNAL_POWER_DB-SNR_dB)/10)*sqrt(2)/2;std::cout << std::endl << variance;};
    std::vector<std::complex<double>> addNoise(const std::vector<std::complex<double>>& constellation);
};

#endif // AWGN_H
