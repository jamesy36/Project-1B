usage: ./nachos_($LOCK_TO_TEST) -q $TESTNUMBER

TEST#		DESCRIPTION
 -1  ALL_TESTS //runs all tests
  1  T_READ_K, //single get to center key for each thread
  2  TEST_PUT_K, //single put to center key for each thread
  3  TEST_LOCK, //test whether we can acquire/release lock
  4  TEST_SIGNAL, //test whether we can signal a thread waiting on a condition variable
  5  TEST_BCAST, //test whether we can broadcast to all waiting threads
  6  TEST_WAIT, //test whether we actually wait when we call Condition::Wait()
  7  TEST_RW_WEXLCUDE, //test whether RWLock prevents multiple writers at once
  8  TEST_RW_RWEXLCUDE, //test whether RWLock prevents readers and writers at the same time
  9  TEST_RW_MULTIPLE_R, //test whether RWLock allows multiple readers at the same time
  10 TEST_SEQUENCE, //basic sequence of gets, puts, and deletes
  11 TEST_READ, //simple read-only sequence
  12 TEST_PUT, //sequence of put statements (first put writes 0, second put writes correct value i)
  13 TEST_DELPUT, //sequence of deletes and puts
  14 TEST_PUTGET, //sequence of puts and gets. set up so there are write conflicts, not not on k, so we should always be the last person to write to key k
  15 TEST_KEYHIT, //sequences of puts/deletes for the same key
  16 TEST_RWHIT, //sequence of modifications that should all land in the same bucket (to hit the rwlock harder).
  17 TEST_INC, //sequence of increments. If we didn't miss anything, the final value of key n should be the number of threads * the number of iterations * 100
