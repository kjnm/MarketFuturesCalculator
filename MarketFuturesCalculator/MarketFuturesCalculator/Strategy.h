#pragma once

#include "Data.h"
#include "DataSyntetic.h"

class Strategy
{
public:

	Strategy(double firstHighThreshold  =  1.005, double lastHighThreshold = 1.01, 
		double firstLowThreshold = 0.995, double lastLowThreshold = 0.99, int splitingNumber = 10, int avgNumber = 13)
	{
		this->firstHighThreshold = firstHighThreshold;
		this->lastHighThreshold = lastHighThreshold;
		this->firstLowThreshold = firstLowThreshold;
		this->lastLowThreshold = lastLowThreshold;

		if (splitingNumber <= 0)
			splitingNumber = 0;

		if (avgNumber <= 0)
			avgNumber = 0;

		this->splitingNumber = splitingNumber;
		this->avgNumber = avgNumber;
	}

	double Eval(const Data& data, int start, int end);
	double Eval(const DataSyntetic& data, int start, int end);

	double firstHighThreshold;
	double lastHighThreshold;
	double firstLowThreshold;
	double lastLowThreshold;


	int splitingNumber = 10; // number of part of capital (first used on fistThreshold and last used on lastThreshold
	int avgNumber = 13; // range of last datapoint to get avg
	double tax = 0.0009; // tax of one operation
};

