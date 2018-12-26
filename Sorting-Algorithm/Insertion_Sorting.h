#ifndef __INSERTION__SORTING__H__
#define __INSERTION__SORTING__H__

template<class T> void InsertionSort(vector<T> &vSort)
{
	if (vSort.size() <= 1)
		return;
	for (int iSentry = 0 ; iSentry < (vSort.size() - 1); ++iSentry)
	{
		T tCheckValue = vSort[iSentry + 1];
		int iCheckIndex = iSentry;
		while (iCheckIndex >= 0 && tCheckValue < vSort[iCheckIndex])
		{
			vSort[iCheckIndex + 1] = vSort[iCheckIndex];
			--iCheckIndex;
		}
		vSort[iCheckIndex + 1] = tCheckValue;

	}
	return;
}

template<class T> void ShellSort(vector<T> &vSort)
{
	int iMidValue = 0;
	for (int iGap = vSort.size() >> 1; iGap > 0; iGap >>= 1)
	{
		for (int iSentry = iGap; iSentry < vSort.size(); ++iSentry)
		{
			iMidValue = vSort[iSentry];
			int iCheckLac = iSentry - iGap;
			for (; iCheckLac >= 0 && vSort[iCheckLac] > iMidValue; iCheckLac -= iGap)
				vSort[iCheckLac + iGap] = vSort[iCheckLac];
			vSort[iCheckLac + iGap] = iMidValue;
		}
	}
	return;
}




#endif
