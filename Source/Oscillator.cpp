/*
  ==============================================================================

    Oscillator.cpp
    Created: 7 Jan 2024 9:16:01am
    Author:  zazz

  ==============================================================================
*/

#include "Oscillator.h"
#include <math.h>

//==============================================================================
SinSquareOscillator::SinSquareOscillator()
{
}

void SinSquareOscillator::init(int sampleRate)
{
	m_sampleRate = sampleRate;
}

float SinSquareOscillator::process()
{
	m_sampleIndex++;
	m_sampleIndex %= m_periodLenghtSamples;

	float fNumberOfHarmonics = 1.0f + NUMBER_OF_HARMONICS_MINUS_ONE * m_shape;
	int numberOfHarmonics = (int)(fNumberOfHarmonics);

	float out = 0.0f;
	for (int i = 1; i <= numberOfHarmonics; i++)
	{
		const double temp = (double)(2 * i - 1);
		out += sin(m_frequencyCoeficient * (double)m_sampleIndex * temp) / temp;
	}

	// Partial harmonics
	const double temp = (double)(2 * numberOfHarmonics + 1);
	const float fraction = fNumberOfHarmonics - numberOfHarmonics;
	out += fraction * sin(m_frequencyCoeficient * (double)m_sampleIndex * temp) / temp;

	return (float)out;
}

void SinSquareOscillator::setFrequency(float frequency)
{
	m_periodLenghtSamples = m_sampleRate / (int)(frequency);
	// Frequency is rounded to period lenght in samples
	const int frequencyRounded = m_sampleRate / m_periodLenghtSamples;
	m_frequencyCoeficient = 2.0 * 3.141592 * (double)frequencyRounded / (double)m_sampleRate;
}

void SinSquareOscillator::setShape(float shape)
{
	m_shape = powf(shape, 3);
}

//==============================================================================
