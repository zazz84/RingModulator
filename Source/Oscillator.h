/*
  ==============================================================================

    Oscillator.h
    Created: 7 Jan 2024 9:16:01am
    Author:  zazz

  ==============================================================================
*/

#pragma once

class SinSquareOscillator
{
public:
	SinSquareOscillator();

	void init(int sampleRate);
	float process();
	void setFrequency(float frequency);
	void setShape(float shape);

private:
	int NUMBER_OF_HARMONICS_MINUS_ONE = 23;
	int m_sampleRate = 48000;
	float m_shape = 0.0f;
	int m_sampleIndex = 0;
	int m_periodLenghtSamples = 48000;
	double m_frequencyCoeficient = 1.0;
};