#ifndef QAMMODULATOR_H
#define QAMMODULATOR_H

#include <QAM.h>
#include <vector>
#include <complex>
#include <random>
#include <cmath>

class QAMModulator:QAM {
public:
    QAMModulator(int size):QAM(size) {};
    std::vector<std::complex<double>> modulate(const std::vector<bool> &bits);
protected:
    unsigned int BinaryToGray(unsigned int num);
};

#endif // QAMMODULATOR_H
