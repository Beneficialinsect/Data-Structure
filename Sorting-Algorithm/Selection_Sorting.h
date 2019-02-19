#ifndef __SELECTION__SORTING__H__
#define __SELECTION__SORTING__H__
#include <vector>
using namespace std;

template<class T> void Selection_Sort(vector<T> &vSort)
{
    for (int iChangePos = 0 ; iChangePos < vSort.size(); ++iChangePos)
    {
        int iMinPos = iChangePos;
        for (int iCheckPos = iChangePos + 1; iCheckPos < vSort.size(); ++iCheckPos)
            if (vSort[iCheckPos] < vSort[iMinPos])
                iMinPos = iCheckPos;
        if (iMinPos != iChangePos)
        {
            T tValue = vSort[iChangePos];
            vSort[iChangePos] = vSort[iMinPos];
            vSort[iMinPos] = tValue;
        }
    }
    return;
}

template<class T> void AdustHeap(vector<T> &vSort, int iCheckLac, int iEndLac)
{
    T tValue = vSort[iCheckLac];
    for (int iCompLac = iCheckLac * 2 + 1; iCompLac < iEndLac; iCompLac = iCompLac * 2 + 1)
    {
        if (iCompLac + 1 < iEndLac && vSort[iCompLac] < vSort[iCompLac + 1])
        {
            iCompLac++;
        }
        if (vSort[iCompLac] > tValue)
        {
            vSort[iCheckLac] = vSort[iCompLac];
            iCheckLac = iCompLac;
        }
        else
            break;
    }
    vSort[iCheckLac] = tValue;

    return;
}

template<class T> void BuildMaxHeap(vector<T> &vSort)
{
    if (vSort.empty())
        return;
    int iTotalLen = vSort.size();
    for (int iLac = floor(iTotalLen / 2); iLac >= 0; --iLac)
        AdustHeap(vSort, iLac, iTotalLen);

    return;
}




template<class T> void HeapSort(vector<T> &vSort)
{
    if (vSort.empty())
        return;
    BuildMaxHeap(vSort);

    for (int iLac = vSort.size() - 1; iLac > 0; --iLac)
    {
        T tValue = vSort[0] ;
        vSort[0] = vSort[iLac];
        vSort[iLac] = tValue;
        AdustHeap(vSort, 0, iLac);
    }

    return;
}



#endif
