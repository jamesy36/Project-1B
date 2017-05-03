#ifndef __RWLOCK_H__
#define __RWLOCK_H__

#include "synch.h"

class RWLock{
  private:
#ifndef P1_RWLOCK
#ifdef P1_SEMAPHORE
	Semaphore* sem;
#else
	
#endif
#else

#endif	
  public:
    RWLock();
    ~RWLock();
    //Reader
    void startRead();
    void doneRead();
    // Writer
    void startWrite();
    void  doneWrite();
};

#endif
