#include "../inc/QAM.h"

//constructor
QAM::QAM(int constellationSize) : constellationSize(constellationSize),
    bitsPerSymbolI(floor(log2(constellationSize)/2)),
    bitsPerSymbolQ( ceil(log2(constellationSize)/2)),
    NModLevelsI(1<<bitsPerSymbolI),  //2^bitsPerSymbol
    NModLevelsQ(1<<bitsPerSymbolQ)  //2^bitsPerSymbol
{}

//getters
unsigned int QAM::get_constellationSize() {return constellationSize;}

unsigned int QAM::get_bitsPerSymbolI() {return bitsPerSymbolI;}

unsigned int QAM::get_bitsPerSymbolQ() {return bitsPerSymbolQ;}

unsigned int QAM::get_NModLevelsI() {return NModLevelsI;}

unsigned int QAM::get_NModLevelsQ() {return NModLevelsQ;}

double QAM::Es() { //O(n^2)
    double sumSquared = 0.0; // Сумма квадратов символов
    for (int i = (1 - NModLevelsI); i < (int)NModLevelsI; i += 2) {
        for (int q = (1 - NModLevelsQ); q < (int)NModLevelsQ; q += 2) {
            sumSquared += (i*i+q*q); // Добавление квадрата символа к сумме
        }
    }
    double meanSquared = sumSquared / constellationSize; // Среднее значение квадратов символов
    return meanSquared; // Возвращаем значение средней энергии сигнала Es
}

double QAM::Es_fast() { //O(n)
    return Es_fast(bitsPerSymbolI+bitsPerSymbolQ);
}

double QAM::Es_fast(unsigned int Nbits) {
    if (Nbits == 0)
        return 0;
    else
        return (1<<((Nbits-1)& ~(1UL << 0))) + Es_fast(Nbits-1);
}

//setters
void QAM::set_constellationSize(unsigned int new_constellationSize) {
    this->operator=(QAM(new_constellationSize));
}

void QAM::set_bitsPerSymbolI(unsigned int new_bitsPerSymbolI) {
    bitsPerSymbolI = new_bitsPerSymbolI;
    NModLevelsI = 1<<bitsPerSymbolI;
    constellationSize = NModLevelsI*NModLevelsQ;
}

void QAM::set_bitsPerSymbolQ(unsigned int new_bitsPerSymbolQ) {
    bitsPerSymbolQ = new_bitsPerSymbolQ;
    NModLevelsQ = 1<<bitsPerSymbolQ;
    constellationSize = NModLevelsI*NModLevelsQ;
}
