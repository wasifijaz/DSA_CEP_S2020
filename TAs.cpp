#include "TAs.h"

TAs TAs:: availableTA(TAs* taa, int day, int totalTAs)
{
    //cout << day<<"\t"<<taa[0].startTimes[day] << "\t" << taa[1].startTimes[day];
    for (int i = 0; i < totalTAs; i++)
    {
        for (int j = i + 1; j < totalTAs; j++)
        {
            //cout<<taa[i].startTimes[day]<<"\n"<<taa[j].startTimes[day]<<endl;
            if (taa[i].startTimes[day] <= taa[j].startTimes[day])
            {
                //cout << "hi";
                return taa[i];
            }
            else
            {
                //cout << "hello";
                return taa[j];
            }
        }
    }
}
