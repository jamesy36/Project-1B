#include "rwlock.h"
#include "system.h" //for currentThread->Yield()

//in case you want to insert yields for testing
#define YIELD() currentThread->Yield()
#ifndef P1_RWLOCK
#ifdef P1_SEMAPHORE
//Task 1 code (using semaphore in place of mutex)
RWLock::RWLock() {
    sem = new Semaphore("sem", 1);
}
RWLock::~RWLock() {
    delete sem;
}
void RWLock::startRead() {
    sem->P();
} //NOTE that for Task 1, startRead should be the same as startWrite
void RWLock::startWrite() {
    sem->P();
}
void RWLock::doneRead() {
    sem->V();
} //NOTE that for Task 1, doneRead should be the same as doneWrite
void RWLock::doneWrite() { 
    sem->V();
}
#else
//Task 2 code (using NACHOS Lock)
RWLock::RWLock() { }
RWLock::~RWLock() { }
void RWLock::startRead() { } //NOTE that for Task 2, startRead should be the same as startWrite
void RWLock::startWrite() { }
void RWLock::doneRead() { } //NOTE that for Task 2, doneRead should be the same as doneWrite
void RWLock::doneWrite() { }
#endif
#else
//Task 3 code (full rwlock)
RWLock::RWLock() {}
RWLock::~RWLock() { }
void RWLock::startRead() { }
void RWLock::doneRead() { }
void RWLock::startWrite() { }
void RWLock::doneWrite() { }
#endif
