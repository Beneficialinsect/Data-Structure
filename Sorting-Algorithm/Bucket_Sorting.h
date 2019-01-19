// this is just for interger , others still have no idea
#ifndef __BUCKET__SORTING__H__
#define __BUCKET__SORTING__H__

#ifndef __BUCKET__SIZE
#define __BUCKET__SIZE 10
#endif

template<class T> void BucketSorting(vector<T> &vSource)
{
    if(vSource.empty())
        return;
    T tMax=vSource[0],tMin= vSource[0];
    for(auto tValue:vSource)
    {
        if(tMax < tValue)
            tMax = tValue;
        if(tMin > tValue)
            tMin = tValue;;
    }

    //per bucket split bound
    size_t tSize = __BUCKET__SIZE || 10;
    size_t sBucketSize=(tMax - tMin)/tSize;
    vector<T> vMid;
    vector<vector<T> > vBucket(sBucketSize,vMid);
    for(auto tValue:vSource)
    {
        vBucket[tValue/sBucketSize].push_back(tValue);
    }
    int iLac = 0;
    for(auto vCheck:vBucket)
    {
        if(!vCheck.empty())
        {
            sort(vCheck.begin(),vCheck.end());
            for(auto tValue:vCheck)
                vSource[iLac++]=tValue;
        }
    }

}




#endif
