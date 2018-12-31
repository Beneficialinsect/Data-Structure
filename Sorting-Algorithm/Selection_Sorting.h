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

template<class T> void Max_heapfy(vector<T> &vSort, int iStart, int iEnd)
{
    int iParentLac = iStart;
    int iChildLac = iParentLac * 2 + 1;
    while (iChildLac <= iEnd)
    {
        if (iChildLac + 1 <= iEnd && vSort[iChildLac] < vSort[iChildLac + 1])
            ++iChildLac;
        if (vSort[iParentLac] > vSort[iChildLac])
            return;
        else
        {
            T tValue = vSort[iParentLac];
            vSort[iParentLac] = vSort[iChildLac];
            vSort[iChildLac] = tValue;
            iChildLac = iParentLac * 2 + 1;
        }
    }
    return;
}

template<class T> void HeapSort(vector<T> &vSort)
{
    int iStartLac = 0;
    for (iStartLac = vSort.size() / 2 - 1; iStartLac >= 0; --iStartLac)
        Max_heapfy(vSort, iStartLac, vSort.size() - 1);

    for (iStartLac = vSort.size() - 1; iStartLac > 0; iStartLac--)
    {
        T tValue = vSort[0];
        vSort[0] = vSort[iStartLac];
        Max_heapfy(vSort, 0, iStartLac - 1);
    }

    return;
}



#endif
