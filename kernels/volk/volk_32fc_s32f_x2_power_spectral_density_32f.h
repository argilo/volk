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
 * \page volk_32fc_s32f_x2_power_spectral_density_32f
 *
 * \b Overview
 *
 * Calculates the log10 power value divided by the RBW for each input point.
 *
 * <b>Dispatcher Prototype</b>
 * \code
 * void volk_32fc_s32f_x2_power_spectral_density_32f(float* logPowerOutput, const lv_32fc_t* complexFFTInput, const float normalizationFactor, const float rbw, unsigned int num_points)
 * \endcode
 *
 * \b Inputs
 * \li complexFFTInput The complex data output from the FFT point.
 * \li normalizationFactor: This value is divided against all the input values before the power is calculated.
 * \li rbw: The resolution bandwidth of the fft spectrum
 * \li num_points: The number of fft data points.
 *
 * \b Outputs
 * \li logPowerOutput: The 10.0 * log10((r*r + i*i)/RBW) for each data point.
 *
 * \b Example
 * \code
 * int N = 10000;
 *
 * volk_32fc_s32f_x2_power_spectral_density_32f();
 *
 * volk_free(x);
 * \endcode
 */

#ifndef INCLUDED_volk_32fc_s32f_x2_power_spectral_density_32f_a_H
#define INCLUDED_volk_32fc_s32f_x2_power_spectral_density_32f_a_H

#include <math.h>


#ifdef LV_HAVE_GENERIC

static inline void
volk_32fc_s32f_x2_power_spectral_density_32f_generic(float* logPowerOutput, const lv_32fc_t* complexFFTInput,
                                                     const float normalizationFactor, const float rbw,
                                                     unsigned int num_points)
{
  volk_32fc_s32f_power_spectrum_32f(logPowerOutput, complexFFTInput, normalizationFactor * sqrt(rbw), num_points);
}
#endif /* LV_HAVE_GENERIC */

#endif /* INCLUDED_volk_32fc_s32f_x2_power_spectral_density_32f_a_H */
