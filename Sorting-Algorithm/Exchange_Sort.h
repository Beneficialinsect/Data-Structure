#ifndef __EXCHANGE__SORT__H__
#define __EXCHANGE__SORT__H__
template<class T> void BubbleSort(vector<T> &vArray)
{
    if(vArray.empty())
        return;
    for(int iEnd = vArray.size()-1;iEnd>0;--iEnd)
    {    
        for(int iBegin = 0; iBegin < iEnd;++iBegin)
        {
            if(vArray[iBegin] > vArray[iBegin+1])
            {
                T tValue_Smaller =vArray[iBegin+1];
                vArray[iBegin+1]=vArray[iBegin];
                vArray[iBegin]=tValue_Smaller;
            }
        }
    }
}


template<class T> void QuikSort(vector<T> &vArray,int iLowBound,int iHighBound)
{
    if(vArray.empty() || iLowBound >= iHighBound || iHighBound > vArray.size() || iLowBound<0)
        return;

    int iSentry=vArray[iLowBound];
    int iLeftCheckPoint = iLowBound, iRightCheckPoint=iHighBound;
    while(iLeftCheckPoint < iRightCheckPoint)
    {
        while(vArray[iRightCheckPoint] >= iSentry && iLeftCheckPoint < iRightCheckPoint)
            --iRightCheckPoint;
        while(vArray[iLeftCheckPoint] <= iSentry && iLeftCheckPoint<iRightCheckPoint)
            ++iLeftCheckPoint;
        if(iLeftCheckPoint < iRightCheckPoint)
        {
            T tValue_Smaller =vArray[iRightCheckPoint];
            vArray[iRightCheckPoint]=vArray[iLeftCheckPoint];
            vArray[iLeftCheckPoint]=tValue_Smaller;
        }
    }
    if(vArray[iLeftCheckPoint] < iSentry)
    {
        vArray[iLowBound]=vArray[iLeftCheckPoint];
        vArray[iLeftCheckPoint] = iSentry;
    }
    QuikSort(vArray,iLowBound,iLeftCheckPoint-1);
    QuikSort(vArray,iLeftCheckPoint+1,iHighBound);
    return;
}


#endif
