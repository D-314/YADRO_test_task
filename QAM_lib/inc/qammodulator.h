#ifndef QAMMODULATOR_H
#define QAMMODULATOR_H

#include "../inc/QAM.h"
#include <vector>
#include <complex>

class QAMModulator:QAM {
public:

    QAMModulator(int size):QAM(size) {};
    /// modulate vector of bits
    std::vector<std::complex<double>> modulate(const std::vector<bool> &bits);
    /// modulate single byte to one symbol
    std::complex<double> modulate(unsigned int symbol_idx);

protected:

    int PAMmod(unsigned int bits, unsigned int Nbits);
    unsigned int GrayToBinary(unsigned int num);
};

#endif // QAMMODULATOR_H
