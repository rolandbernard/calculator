#include "WProgram.h"

serialPort Serial;
void analogWriteDAC0(int in) { std::cout << "Set DAC0 to " << refrenceVoltage * in / 4096 << "V.\n"; }