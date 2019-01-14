#ifndef __MERGE__SORTING__H__
#define __MERGE__SORTING__H__



template<class T> void OperMerge(T* tSourceArr,T* tLeft, int iLeftCnt,T* tRight,int iRightCnt)
{
    int iLeftLoc=0,iRightLoc = 0, iSourceLoc = 0;
    while(iLeftLoc < iLeftCnt && iRightLoc < iRightCnt)
        if(tLeft[iLeftLoc] > tRight[iRightLoc])
            tSourceArr[iSourceLoc++] = tRight[iRightLoc++];
        else
            tSourceArr[iSourceLoc++] = tLeft[iLeftLoc++];
    while(iLeftLoc < iLeftCnt)
        tSourceArr[iSourceLoc++] = tLeft[iLeftLoc++];
    while(iRightLoc < iRightCnt)
        tSourceArr[iSourceLoc++] = tRight[iRightLoc++];
    return;
}


template<class T> void MergeSort(T* tArray, int iElementCnt)
{
    if(iElementCnt < 2)
        return;

    int iMidLocation = iElementCnt/2;

    T* tLeft=new T[iMidLocation];
    T* tRight=new T[iElementCnt-iMidLocation];

    for(int iLacPre = 0; iLacPre < iMidLocation;++iLacPre)
        tLeft[iLacPre] = tArray[iLacPre];
    for(int iLacLast=iMidLocation;iLacLast < iElementCnt;++iLacLast)
        tRight[iLacLast-iMidLocation]=tArray[iLacLast];

    MergeSort(tLeft,iMidLocation);
    MergeSort(tRight,iElementCnt-iMidLocation);

    OperMerge(tArray,tLeft,iMidLocation,tRight,iElementCnt - iMidLocation);
    delete []tLeft;
    delete []tRight;
    return;
}



#endif
