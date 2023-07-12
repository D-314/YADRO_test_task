#include "../inc/qammodulator.h"

std::vector<std::complex<double>> QAMModulator::modulate(const std::vector<bool>& bits)
{
    std::vector<std::complex<double>> constellation;
    unsigned int bitsPerSymbol = bitsPerSymbolI + bitsPerSymbolQ;
    for (unsigned long long i = 0; i < bits.size(); i += bitsPerSymbol) {
        int symbol = 0;
        for (unsigned int j = 0; j < bitsPerSymbol; j++) {
            symbol = (symbol << 1) | bits[i + j];
        }
        constellation.push_back(modulate(symbol));
    }
    return constellation;
}

std::complex<double> QAMModulator::modulate(unsigned int symbol_idx) {
    double I = (double)PAMmod(symbol_idx / NModLevelsI, bitsPerSymbolI);
    double Q = -(double)(PAMmod(symbol_idx % NModLevelsQ, bitsPerSymbolQ));
    return std::complex<double>(I, Q);
}

int QAMModulator::PAMmod(unsigned int bits, unsigned int Nbits) {
    return (GrayToBinary(bits) << 1) - ((1 << Nbits) - 1);
}

// This function converts a reflected binary Gray code number to a binary number.
unsigned int QAMModulator::GrayToBinary(unsigned int  num)
{
    unsigned int  mask = num;
    while (mask) {           // Each Gray code bit is exclusive-ored with all more significant bits.
        mask >>= 1;
        num   ^= mask;
    }
    return num;
}
