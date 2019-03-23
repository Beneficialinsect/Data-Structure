#ifndef __BISEARCH__H__
#define __BISEARCH__H__

bool BiSearchNoRecursion(vector<int> &vSource,int iValue)
{
    if(vSource.empty())
        return false;
    int iLowLac=0, iHighLac=vSource.size() - 1;
    while(iLowLac <= iHighLac)
    {
        int iMidLac = (iLowLac + iHighLac)/2;
        if(vSource[iMidLac] == iValue)
            return true;
        else if(vSource[iMidLac] > iValue)
            iHighLac = iMidLac-1;
        else
            iLowLac = iMidLac +1;
    }
    return false;
}

bool BiSearchRecursion(vector<int> &vSource,int iLowLac, int iHighLac,int iValue)
{
    if(vSource.empty() || iLowLac > iHighLac)
        return false;
    int iMidLac = (iLowLac+iHighLac)/2;

    if(vSource[iMidLac]==iValue)
        return true;
    else if(vSource[iMidLac]>iValue)
        return BiSearchRecursion(vSource,iLowLac,iMidLac-1,iValue);
    else
        return BiSearchRecursion(vSource,iMidLac+1,iHighLac,iValue);
}


#endif
