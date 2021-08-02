#pragma once

#include <vector>
#include <string>

class Data
{
public:

	Data(std::string pathEth, std::string pathEthFutures);


	struct dataRow {

	public:

		dataRow(int time, double openEth, double highEth, double lowEth, double closeEth, double volumne1Eth, double volumne2Eth,
			double openEthFutures, double highEthFutures, double lowEthFutures, double closeEthFutures, double volumne1EthFutures, double volumne2EthFutures)
		{
			this->time = time;
			this->openEth = openEth;
			this->highEth = highEth;
			this->lowEth = lowEth;
			this->closeEth = closeEth;
			this->volumne1Eth = volumne1Eth;
			this->volumne2Eth = volumne2Eth;

			this->openEthFutures = openEthFutures;
			this->highEthFutures = highEthFutures;
			this->lowEthFutures = lowEthFutures;
			this->closeEthFutures = closeEthFutures;
			this->volumne1EthFutures = volumne1EthFutures;
			this->volumne2EthFutures = volumne2EthFutures;
		}

		int time;
		double openEth;
		double highEth;
		double lowEth;
		double closeEth;
		double volumne1Eth;
		double volumne2Eth;

		double openEthFutures;
		double highEthFutures;
		double lowEthFutures;
		double closeEthFutures;
		double volumne1EthFutures;
		double volumne2EthFutures;
	};

	int Size() const { return array.size(); }
	dataRow operator[](const int idx) const { return array[idx]; }

	double getAvgDiff();
	double getStdDevDiff();
	double getPSameSign();

	std::vector<dataRow> array;
};

