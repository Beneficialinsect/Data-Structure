#ifndef __COUNT__SORTING__H__
#define __COUNT__SORTING__H__

void CountSorting(vector<int> &vSource, vector<int> &vResult)
{
    if (vSource.empty())
        return;
    int iMax = vSource[0], iMin = vSource[0];
    for (auto iValue : vSource)
    {
        if (iValue > iMax)
            iMax = iValue;
        if (iValue < iMin)
            iMin = iValue;
    }
    size_t kSize = iMax - iMin + 1;
    vector<int > vCount(kSize, 0);
    for (int iLac = 0; iLac < vSource.size(); ++iLac)
        ++vCount[vSource[iLac] - iMin];

    for (int iLac = 1; iLac < kSize; ++iLac)
        vCount[iLac] += vCount[iLac - 1] ;

    vResult.clear();
    vResult.resize(vSource.size());
    for (int iLac = 0 ; iLac < vSource.size(); ++iLac)
    {
        vResult[vCount[vSource[iLac] -  iMin] - 1] = vSource[iLac];
        --vCount[vSource[iLac] - iMin];
    }

    return;

}



#endif
