#include <iostream>
#include "waveforms.h"
#include "DSPTools.h"
#include "stdio.h"

using namespace std;

const int SIG_LENGTH = 320;

double MEAN = 0.0;
double VARIANCE = 0.0;

int main()
{
    DSPTools m_DSP;
    MEAN = m_DSP.calc_signal_mean(InputSignal_f32_1kHz_15kHz, SIG_LENGTH);
    VARIANCE = m_DSP.calc_signal_variance(InputSignal_f32_1kHz_15kHz, MEAN, SIG_LENGTH);

    printf("\n\n Mean = %f\n variance=%f\n\n", MEAN, VARIANCE);
    return 0;
}
