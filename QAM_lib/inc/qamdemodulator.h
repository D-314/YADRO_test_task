#ifndef QAMDEMODULATOR_H
#define QAMDEMODULATOR_H

#include "../inc/QAM.h"
#include <vector>
#include <complex>

class QAMDemodulator:QAM {
public:

    QAMDemodulator(int size):QAM(size) {};

    std::vector<bool> demodulate(const std::vector<std::complex<double>>& constellation);
    unsigned int demodulate(std::complex<double> symbol);

private:

    int PAMdemod(double symbol, unsigned int Nbits);
    unsigned int BinaryToGray(unsigned int  num);
};

#endif // QAMDEMODULATOR_H
