#include "qammodulator.h"
#include <iostream>

std::vector<std::complex<double>> QAMModulator::modulate(const std::vector<bool>& bits)
{
    std::vector<std::complex<double>> constellation;

    for (unsigned long long i = 0; i < bits.size(); i += bitsPerSymbol) {
        int symbol = 0;
        for (unsigned int j = 0; j < bitsPerSymbol; j++) {
            symbol = (symbol << 1) | bits[i + j];
        }
        //std::cout << '\t' << std::complex<double>(symbol / numAmpLevels, symbol % numAmpLevels);
        int GrayCodeI = BinaryToGray(symbol / numAmpLevels);
        int GrayCodeQ = BinaryToGray(symbol % numAmpLevels);
        //std::cout << '\t' << std::complex<double>(GrayCodeI, GrayCodeQ);
        double I = (double)(2 * GrayCodeI - (numAmpLevels - 1)) /  (sqrt(2)*(numAmpLevels-1));
        double Q = -(double)(2 * GrayCodeQ - (numAmpLevels - 1)) / (sqrt(2)*(numAmpLevels-1));
        constellation.push_back(std::complex<double>(I, Q));
    }

    return constellation;
}

unsigned int QAMModulator::BinaryToGray(unsigned int num)
{
    return num ^ (num >> 1); // The operator >> is shift right. The operator ^ is exclusive or.
}
