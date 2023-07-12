#include "../inc/qamdemodulator.h"

std::vector<bool> QAMDemodulator::demodulate(const std::vector<std::complex<double>>& constellation)
{
    std::vector<bool> demodulatedBits;
    unsigned int bitsPerSymbol = bitsPerSymbolI + bitsPerSymbolQ;
    for (std::complex<double> symbol : constellation) {

        int symbol_idx = demodulate(symbol);

        for (unsigned int i = 0; i < bitsPerSymbol; i++) {
            bool bit = (symbol_idx >> (bitsPerSymbol - 1 - i)) & 1;
            demodulatedBits.push_back(bit);
        }
    }

    return demodulatedBits;
}

unsigned int QAMDemodulator::demodulate(std::complex<double> symbol) {
    double I = symbol.real();
    double Q = - symbol.imag();

    //return PAMdemod(I, bitsPerSymbolI) * NModLevelsI + PAMdemod(Q, bitsPerSymbolQ);
    return (PAMdemod(I, NModLevelsI) << bitsPerSymbolI) | PAMdemod(Q, NModLevelsQ);
}

int QAMDemodulator::PAMdemod(double symbol, unsigned int NModLevels) {
    return BinaryToGray((unsigned int)(round((NModLevels+symbol-1)/2)));
}

// This function converts an unsigned binary number to reflected binary Gray code.
unsigned int QAMDemodulator::BinaryToGray(unsigned int num)
{
    return num ^ (num >> 1); // The operator >> is shift right. The operator ^ is exclusive or.
}
