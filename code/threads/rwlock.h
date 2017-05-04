#ifndef __RWLOCK_H__
#define __RWLOCK_H__

#include "synch.h"

class RWLock{
  private:
#ifndef P1_RWLOCK
#ifdef P1_SEMAPHORE
    Semaphore* sem; 
#else
    Lock* lock;
#endif
#else
    int reading;
    int read_wait;
    int writing;
    int write_wait;
    Condition* read;
    Condition* write;
    Lock* lock;    
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
