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
RWLock::RWLock() {
    lock = new Lock("lock");
}
RWLock::~RWLock() {
    delete lock;
}
void RWLock::startRead() {
    lock->Acquire();
} //NOTE that for Task 2, startRead should be the same as startWrite
void RWLock::startWrite() {
    lock->Acquire();
}
void RWLock::doneRead() {
    lock->Release();
} //NOTE that for Task 2, doneRead should be the same as doneWrite
void RWLock::doneWrite() {
    lock->Release();
}
#endif
#else
//Task 3 code (full rwlock)
RWLock::RWLock() {
    reading = 0;
    read_wait = 0;
    writing = 0;
    write_wait = 0;
    read = new Condition("read");
    write = new Condition("write");
    lock = new Lock("lock");
}
RWLock::~RWLock() {
    delete read;
    delete write;
    delete lock;
}
void RWLock::startRead() {
    lock->Acquire();
    read_wait++;
    while(write_wait!=0 || writing!= 0){
	read->Wait(lock);
    }

    read_wait--;
    reading++;
    lock->Release();
}
void RWLock::doneRead() {
    lock->Acquire();
    reading--;
    if(reading == 0 && write_wait > 0){
	write->Signal(lock);
    }
    lock->Release(); 
}
void RWLock::startWrite() {
    lock->Acquire();
    write_wait++;
    while(writing!=0 || reading!=0){
	write->Wait(lock);
    }

    write_wait--;
    writing++;
    lock->Release();
}
void RWLock::doneWrite() {
    lock->Acquire();
    writing--;
    if(write_wait > 0){
	write->Signal(lock);
    }
    
    else if(read_wait > 0){
	read->Broadcast(lock);
    }

    lock->Release();
}
#endif
