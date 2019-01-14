#include "Merge_Sorting.h"
#include <boost/random.hpp>
#include <boost/random/random_device.hpp>
boost::random::mt19937 gen;
using namespace boost;

int main()
{
    boost::uniform_int<> distribution(1, 100) ;
    variate_generator<mt19937, uniform_int<> > myrandom (gen, distribution);
    int iLength = 0;
#ifdef __CHECKMOUNT__
    iLength=__CHECKMOUNT__;
#else
    iLength=1000;
#endif
      int *tArray = new int[iLength];
      int *tCheck=new int[iLength];

      for(int iLac =0 ;iLac <  iLength;++iLac)
      {
            int iValue = myrandom();
            tArray[iLac] = iValue;
            tCheck[iLac] = iValue;
      }
      

      MergeSort(tArray,iLength);
      sort(tCheck,tCheck+iLength);
      while(1)
     {
          bool bFind = false;
      for(int iLac =0 ; iLac < iLength;++iLac)
      {
        if(tArray[iLac] != tCheck[iLac])
        {
            cout << "not same" << endl;
            cout << tArray[iLac] << "---" << tCheck[iLac] << endl;
            bFind = true;
          break;
        }
      }
      if(bFind)
          break;
      }
      delete []tArray;
      delete []tCheck;
    return 0;
}


