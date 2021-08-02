#include "Data.h"
#include <fstream>
#include <iostream>
#include <sstream>
#include <assert.h>

Data::Data(std::string pathEth, std::string pathEthFutures)
{    
    std::string line1;
    std::ifstream myfile1(pathEth);
    std::string line2;
    std::ifstream myfile2(pathEthFutures);
    std::vector<std::string> row1,row2;
    std::string line, word, temp;
    if (myfile1.is_open() && myfile2.is_open())
    {
        while (getline(myfile1, line1))
        {
            getline(myfile2, line2);
            
            std::stringstream s1(line1);
            std::stringstream s2(line2);

            row1.clear();
            row2.clear();

            while (std::getline(s1, word, ',')) {

                row1.push_back(word);
            }

            while (std::getline(s2, word, ',')) {

                row2.push_back(word);
            }

            if (row1[0] != "time")
                this->array.push_back(dataRow(std::stoi(row1[0]), std::stod(row1[1]), std::stod(row1[2]), std::stod(row1[3]), std::stod(row1[4]), std::stod(row1[5]), std::stod(row1[6]),
                    std::stod(row2[1]), std::stod(row2[2]), std::stod(row2[3]), std::stod(row2[4]), std::stod(row2[5]), std::stod(row2[6])));
        }

        myfile1.close();
        myfile2.close();
    }
}

double Data::getAvgDiff()
{
    return (-array[0].openEthFutures / array[0].openEth +  array[Size() - 1].openEthFutures/ array[Size() - 1].openEth)/(Size()-1);
}

double Data::getStdDevDiff()
{
    double avg = getAvgDiff();
    double sum = 0;

    for (int i = 1; i < Size(); i++)
    {
        sum += (array[i].openEthFutures / array[i].openEth - array[i - 1].openEthFutures / array[i - 1].openEth -avg) *
            (array[i].openEthFutures / array[i].openEth - array[i - 1].openEthFutures / array[i - 1].openEth -avg);
    }

    return sqrt(sum/(Size()-2));
}

double Data::getPSameSign()
{
    int sames = 0;

    for (int i = 3; i < Size(); i++)
    {
        if ((array[i].openEthFutures / array[i].openEth - array[i - 1].openEthFutures / array[i - 1].openEth) *
            (array[i - 1].openEthFutures / array[i - 1].openEth - array[i - 2].openEthFutures / array[i - 2].openEth) > 0)
            if ((array[i].openEthFutures / array[i].openEth - array[i - 1].openEthFutures / array[i - 1].openEth) *
                (array[i - 2].openEthFutures / array[i - 2].openEth - array[i - 3].openEthFutures / array[i - 3].openEth) > 0)

            sames++;
    }

    return ((double)(sames))/(Size()-2);
}
