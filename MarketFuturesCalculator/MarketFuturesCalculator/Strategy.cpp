#include "Strategy.h"
#include <assert.h>
#include <iostream>

double Strategy::Eval(const Data& data, int start, int end)
{
    double dollars = 100.;
    double ethers = 0.;
    double contracts = 0.;

    assert(start >= 0);
    assert(end < data.Size());


    double avg = 0;

    for (int i = start; i < start + avgNumber; i++)
    {
        avg += data[i].openEthFutures / data[i].openEth;
    }

    avg = avg / avgNumber;

    int currentState = 0;

    for (int i = start + avgNumber; i < end; i++)
    {
        avg += (data[i].openEthFutures / data[i].openEth - data[i - avgNumber].openEthFutures / data[i - avgNumber].openEth) / avgNumber;
        
        //std::cout << avg << std::endl;

        double val = (data[i].openEthFutures / data[i].openEth);

        for (int j = 0; j < splitingNumber; j++)
        {
            if ( val / avg > firstHighThreshold * (splitingNumber-1. -j) / (splitingNumber-1.) + lastHighThreshold * (j/ (splitingNumber - 1.)) && currentState <= j)
            {
                double dollarSell = dollars / (splitingNumber - currentState);

                dollars -= dollarSell;



                //ethers += (dollarSell / data[i].openEth) * (1-tax);

                contracts += dollarSell * val * (1 - tax);

                currentState++;
                //std::cout << "dollarSell " <<currentState << "$=" << dollars << " C=" << contracts << std::endl;
                assert(currentState <= splitingNumber);
            }
        }



        for (int j = 0; j < splitingNumber; j++)
        {
            if (val / avg < firstLowThreshold * (splitingNumber - 1. - j) / (splitingNumber - 1.) + lastLowThreshold * (j / (splitingNumber - 1.)) && currentState > j)
            {
                assert(contracts > 0);
                //assert(ethers > 0);
                assert(j >= 0);


                double contractsSell = contracts / (currentState );
                //double etherSell = ethers / (currentState+1);

                //ethers -= etherSell;

                contracts -= contractsSell;


                dollars += (contractsSell / val)* (1 - tax);

                currentState--;


                //std::cout << "contraSell " << currentState << "$=" << dollars << " C=" << contracts << std::endl;

                assert(currentState >= 0);
            }
        }


    }


    return dollars + contracts * data[end-1].openEth/ data[end - 1].openEthFutures;
}


double Strategy::Eval(const DataSyntetic& data, int start, int end)
{
    double dollars = 100.;
    double ethers = 0.;
    double contracts = 0.;

    assert(start >= 0);
    assert(end <= data.Size());


    double avg = 0;

    for (int i = start; i < start + avgNumber; i++)
    {
        avg +=data[i];
    }

    avg = avg / avgNumber;

    int currentState = 0;

    for (int i = start + avgNumber; i < end; i++)
    {
        avg += (data[i] - data[i - avgNumber]) / avgNumber;

        //std::cout << avg << std::endl;

        double val = data[i];

        for (int j = 0; j < splitingNumber; j++)
        {
            if (val / avg > firstHighThreshold * (splitingNumber - 1. - j) / (splitingNumber - 1.) + lastHighThreshold * (j / (splitingNumber - 1.)) && currentState <= j)
            {
                double dollarSell = dollars / (splitingNumber - currentState);

                dollars -= dollarSell;



                //ethers += (dollarSell / data[i].openEth) * (1-tax);

                contracts += dollarSell * val * (1 - tax);

                currentState++;
              //  std::cout << "dollarSell " <<currentState << "$=" << dollars << " C=" << contracts <<" v=" << val  <<std::endl;
                assert(currentState <= splitingNumber);
            }
        }



        for (int j = 0; j < splitingNumber; j++)
        {
            if (val / avg < firstLowThreshold * (splitingNumber - 1. - j) / (splitingNumber - 1.) + lastLowThreshold * (j / (splitingNumber - 1.)) && currentState > j)
            {
                assert(contracts > 0);
                //assert(ethers > 0);
                assert(j >= 0);


                double contractsSell = contracts / (currentState);
                //double etherSell = ethers / (currentState+1);

                //ethers -= etherSell;

                contracts -= contractsSell;


                dollars += (contractsSell / val) * (1 - tax);

                currentState--;


                //std::cout << "contraSell " << currentState << "$=" << dollars << " C=" << contracts << " v=" << val << std::endl;

                assert(currentState >= 0);
            }
        }


    }


    return dollars + contracts /data[end - 1];
}
