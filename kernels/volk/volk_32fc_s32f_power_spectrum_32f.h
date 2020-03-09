/* -*- c++ -*- */
/*
 * Copyright 2012, 2014 Free Software Foundation, Inc.
 *
 * This file is part of GNU Radio
 *
 * GNU Radio is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 3, or (at your option)
 * any later version.
 *
 * GNU Radio is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with GNU Radio; see the file COPYING.  If not, write to
 * the Free Software Foundation, Inc., 51 Franklin Street,
 * Boston, MA 02110-1301, USA.
 */

/*!
 * \page volk_32fc_s32f_power_spectrum_32f
 *
 * \b Overview
 *
 * Calculates the log10 power value for each input point.
 *
 * <b>Dispatcher Prototype</b>
 * \code
 * void volk_32fc_s32f_power_spectrum_32f(float* logPowerOutput, const lv_32fc_t* complexFFTInput, const float normalizationFactor, unsigned int num_points)
 * \endcode
 *
 * \b Inputs
 * \li complexFFTInput The complex data output from the FFT point.
 * \li normalizationFactor: This value is divided against all the input values before the power is calculated.
 * \li num_points: The number of fft data points.
 *
 * \b Outputs
 * \li logPowerOutput: The 10.0 * log10(r*r + i*i) for each data point.
 *
 * \b Example
 * \code
 * int N = 10000;
 *
 * volk_32fc_s32f_power_spectrum_32f();
 *
 * volk_free(x);
 * \endcode
 */

#ifndef INCLUDED_volk_32fc_s32f_power_spectrum_32f_a_H
#define INCLUDED_volk_32fc_s32f_power_spectrum_32f_a_H


#ifdef LV_HAVE_GENERIC

static inline void
volk_32fc_s32f_power_spectrum_32f_generic(float* logPowerOutput, const lv_32fc_t* complexFFTInput,
                                          const float normalizationFactor, unsigned int num_points)
{
  // Calculate the Power of the complex point
  const float normFactSq = 1.0 / (normalizationFactor * normalizationFactor);

  // Calc mag^2
  volk_32fc_magnitude_squared_32f(logPowerOutput, complexFFTInput, num_points);

  // Finish ((real * real) + (imag * imag)) calculation:
  volk_32f_s32f_multiply_32f(logPowerOutput, logPowerOutput, normFactSq, num_points);

  // The following calculates 10*log10(x) = 10*log2(x)/log2(10) = (10/log2(10))
  // * log2(x)
  volk_32f_log2_32f(logPowerOutput, logPowerOutput, num_points);
  volk_32f_s32f_multiply_32f(logPowerOutput, logPowerOutput, volk_log2to10factor,
                             num_points);
}
#endif /* LV_HAVE_GENERIC */

#endif /* INCLUDED_volk_32fc_s32f_power_spectrum_32f_a_H */
