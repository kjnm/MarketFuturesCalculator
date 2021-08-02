// MarketFuturesCalculator.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "Data.h"
#include "Strategy.h"

int main()
{
    Data data("C:\\Users\\krzys\\source\\repos\\MarketFuturesCalculator\\Debug\\eth.csv", "C:\\Users\\krzys\\source\\repos\\MarketFuturesCalculator\\Debug\\ethFut.csv");


    double avg = data.getAvgDiff();
    double stdDiff = data.getStdDevDiff();
    double Psame = data.getPSameSign();

    //for(int i=0;i<100;i++)
    //std::cout << Strategy(1.005, 1.01, 0.995, 0.99, 10,13).Eval(DataSyntetic (avg, stdDiff, 1000, 0.5), 0 ,1000)<<std::endl;

    for (int i = 0; i < 100; i++)
    {
        DataSyntetic ds(avg, stdDiff, 1000, 0.5);

        std::cout << ds.getAvgDiff() << " " << ds.getStdDevDiff() << std::endl;

        ds.saveToFile("ds.txt");
    }
    double sum = 0;

    double diff = 0.001;

    
    double maxt1, maxt2, maxt3, maxt4;

    int maxt5, maxt6;

    double t1, t2, t3, t4;

    int t5, t6;

    t1 = 1.005;
    t2 = 1.01;
    t3 = 0.995;
    t4 = 0.99;

    t5 = 10;
    t6 = 13;
    /*
    //for (int time = 0; time < 4; time++)
    for (int i= 0 ; i < 10; i ++)
    {

        double max = 0;

        int time = 0;
        sum = 0;

        DataSyntetic ds(avg, stdDiff, 1000, 0.5);

        for (int i1 = -2; i1 <= 2; i1++)
            for (int i2 = -2; i2 <= 2; i2++)
                for (int i3 = -2; i3 <= 2; i3++)
                    for (int i4 = -2; i4 <= 2; i4++)
                        for (int i5 = -1; i5 <= 1; i5++)
                            for (int i6 = -1; i6 <= 1; i6++)
                    {
                        //int i5 = 0, i6 = 0;
                        //std::cout << 1.005 + i1 * 0.0005 << " " << 1.01 + i2 * 0.0005 << " " << 0.995 + i3 * 0.0005 << " " << 0.99 + i4 * 0.0005 <<" = ";

                        //double val = Strategy(t1 + i1 * diff, t2 + i2 * diff, t3 + i3 * diff, t4 + i4 * diff).Eval(data, 0, (data.Size() - 1)/2);
                        double val = Strategy(t1 + i1 * diff, t2 + i2 * diff, t3 + i3 * diff, t4 + i4 * diff, t5 + i5, t6 + i6).Eval(ds, 0, ds.Size() - 1);
                        sum += val;
                        time++;
                        //std::cout << val <<std::endl;

                        if (max < val)
                        {
                            max = val;

                            maxt1 = t1 + i1 * diff;
                            maxt2 = t2 + i2 * diff;
                            maxt3 = t3 + i3 * diff;
                            maxt4 = t4 + i4 * diff;

                            maxt5 = t5 + i5;
                            maxt6 = t6 + i6;
                        }
                    }

        t1 = maxt1;
        t2 = maxt2;
        t3 = maxt3;
        t4 = maxt4;

        t5 = maxt5;
        t6 = maxt6;

        diff = diff / 2;
        std::cout <<"avg="<< sum / time << std::endl;
        std::cout << "max=" << max << std::endl;
        std::cout << maxt1<< " " << maxt2 << " " << maxt3 << " " << maxt4 << " " <<maxt5 << " "<< maxt6 << " " << std::endl;


        //std::cout << "test=" <<  Strategy(maxt1, maxt2, maxt3, maxt4).Eval(data, (data.Size() - 1) / 2, data.Size() - 1) << std::endl;
        std::cout << "test=" << Strategy(maxt1, maxt2, maxt3, maxt4,maxt5, maxt6).Eval(data, 0, data.Size() - 1) << std::endl;

    }
    */
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
