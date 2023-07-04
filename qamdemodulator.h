#ifndef QAMDEMODULATOR_H
#define QAMDEMODULATOR_H
#include <QAM.h>
#include <vector>
#include <complex>

class QAMDemodulator:QAM {
public:
    QAMDemodulator(int size):QAM(size) {};
    std::vector<bool> demodulate(const std::vector<std::complex<double>>& constellation);
private:
    unsigned int GrayToBinary(unsigned int  num);
};

#endif // QAMDEMODULATOR_H
