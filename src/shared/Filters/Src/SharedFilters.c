/******************************************************************************
 * Includes
 ******************************************************************************/
#include "SharedFilters.h"
#include "arm_math.h"

/******************************************************************************
 * Module Preprocessor Constants
 ******************************************************************************/

/******************************************************************************
 * Module Preprocessor Macros
 ******************************************************************************/

/******************************************************************************
 * Module Typedefs
 ******************************************************************************/

/******************************************************************************
 * Module Variable Definitions
 ******************************************************************************/

/******************************************************************************
 * Private Function Prototypes
 *******************************************************************************/

/******************************************************************************
 * Private Function Definitions
 ******************************************************************************/

/******************************************************************************
 * Function Definitions
 ******************************************************************************/
void SharedFilters_LowPassFilter(
    float32_t *input,
    float32_t *output,
    uint32_t   sampling_time,
    uint32_t   rc)
{
    uint32_t smoothing_factor;

    smoothing_factor = sampling_time / (rc + sampling_time);

    // The pseudo-code for this LPF implementation is as follows:
    // y[i] = y[i-1] + SmoothingFactor * ( x[i] - y[i-1] ), where y =
    // output, x = input. That is, the change from one filter output
    // to the next is proportional to the difference between the previous
    // output and the next input.
    for (uint32_t i = 0; i < sizeof(output) / sizeof(output[0]); i++)
    {
        output[i] = output[i] + smoothing_factor * (input[i] - output[i]);
    }
}