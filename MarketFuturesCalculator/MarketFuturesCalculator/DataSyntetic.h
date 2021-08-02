#pragma once

#include <string>
#include <vector>

class DataSyntetic
{
public:
	DataSyntetic(double avg, double std_dev, int size, double p_same_sign);

	int Size() const { return array.size(); }
	double operator[](const int idx) const { return array[idx]; }

	void saveToFile(std::string name);


	double getAvgDiff();
	double getStdDevDiff();

	std::vector<double> array;

};

