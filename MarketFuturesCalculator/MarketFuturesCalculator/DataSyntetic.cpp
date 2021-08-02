#include "DataSyntetic.h"
#include <random>
#include <iostream>
#include <fstream>
#include <chrono>

DataSyntetic::DataSyntetic(double avg, double std_dev, int size, double p_same_sign)
{
	unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
	std::default_random_engine generator(seed);
	std::normal_distribution<double> distribution(avg, std_dev);

	
	double val = 1.07;

	double lastSign = 1;

	for (int i = 0; i < size; i++)
	{
		double rand = distribution(generator);


		//std::cout <<rand << std::endl;;

		if (std::rand() > p_same_sign)
			lastSign = -lastSign;

		val += abs(rand) * lastSign;

		array.push_back(val);
	}

	//std::cout << (array[Size() - 1]) << std::endl;;
}

void DataSyntetic::saveToFile(std::string name)
{
	std::ofstream myfile;
	myfile.open(name);

	for (int i = 0; i < Size(); i++) {

		myfile << array[i] << std::endl;
	}

	myfile.close();
}

double DataSyntetic::getAvgDiff()
{
	return (-array[0] + array[Size() - 1]) / (Size() - 1);
}

double DataSyntetic::getStdDevDiff()
{
	double avg = getAvgDiff();
	double sum = 0;

	for (int i = 1; i < Size(); i++)
	{
		sum += (array[i] - array[i - 1] - avg) *
			(array[i] - array[i - 1] - avg);
	}

	return sqrt(sum / (Size() - 2));
}
