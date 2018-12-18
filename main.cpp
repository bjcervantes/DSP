#include <iostream>
#include "waveforms.h"
#include "DSPTools.h"
#include "stdio.h"

using namespace std;

double MEAN = 0.0;
double VARIANCE = 0.0;
double STD;

int main()
{
    DSPTools m_DSP;
    /*
    MEAN = m_DSP.calc_signal_mean(InputSignal_f32_1kHz_15kHz, SIG_LENGTH);
    VARIANCE = m_DSP.calc_signal_variance(InputSignal_f32_1kHz_15kHz, MEAN, SIG_LENGTH);
    STD = m_DSP.calc_signal_std(VARIANCE);
    printf("\n\n Mean = %lf\n variance=%lf\n Standard-Deviation=%lf\n\n", MEAN, VARIANCE, STD);
    */

    FILE *input_sig_fptr = nullptr, *imp_rsp_fptr = nullptr, *output_sig_fptr = nullptr;
    double Output_signal[SIG_LENGTH + IMP_RES_LENGTH];

    m_DSP.convolution(InputSignal_f32_1kHz_15kHz, Output_signal, Impulse_response, SIG_LENGTH, IMP_RES_LENGTH);

    input_sig_fptr = fopen("input_signal.dat", "w");
    imp_rsp_fptr = fopen("impulse_response.dat", "w");
    output_sig_fptr = fopen("output_signal.dat", "w");

    for (int i = 0; i<SIG_LENGTH; i++)
    {
        fprintf(input_sig_fptr, "\n%f", InputSignal_f32_1kHz_15kHz[i]);
    }
    fclose(input_sig_fptr);

    for (int i = 0; i<IMP_RES_LENGTH; i++)
    {
        fprintf(imp_rsp_fptr, "\n%f", Impulse_response[i]);
    }
    fclose(imp_rsp_fptr);

    for (int i = 0; i<SIG_LENGTH + IMP_RES_LENGTH; i++)
    {
        fprintf(output_sig_fptr, "\n%f", Output_signal[i]);
    }
    fclose(output_sig_fptr);
    return 0;
}
