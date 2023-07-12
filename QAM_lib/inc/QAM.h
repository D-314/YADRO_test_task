#ifndef QAM_H
#define QAM_H

#include <cmath>

class QAM {
protected:
    unsigned int constellationSize; // количество точек в созвездии
    unsigned int bitsPerSymbolI,bitsPerSymbolQ; // количество бит отдельно для каждой составляющей
    unsigned int NModLevelsI,NModLevelsQ; // количество уровней амплитуд отдельно для каждой составляющей
public:
    QAM(int constellationSize);
    // get
    unsigned int get_constellationSize();
    unsigned int get_bitsPerSymbolI();
    unsigned int get_bitsPerSymbolQ();
    unsigned int get_NModLevelsI();
    unsigned int get_NModLevelsQ();

    /// mean energy per bit Es = E|S^2|;
    double Es();
    /// mean energy per bit (without loop)
    double Es_fast();

    //set
    void set_constellationSize(unsigned int new_constellationSize);
    void set_bitsPerSymbolI(unsigned int new_bitsPerSymbolI);
    void set_bitsPerSymbolQ(unsigned int new_bitsPerSymbolQ);

private:
    double Es_fast(unsigned int Nbits);
};

#endif // QAM_H
