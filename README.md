# Operating-Systems
 Write a multi-threaded C program that gives readers priority over writers concerning a shared (global) variable. Essentially, if any readers are waiting, then they have priority over writer threads -- writers can only write when there are no readers. This program should adhere to the following constraints: 
    Multiple readers/writers must be supported (5 of each is fine) 
    Readers must read the shared variable X number of times 
    Writers must write the shared variable X number of times 
    Readers must print: 
        The value read 
        The number of readers present when value is read 
    Writers must print: 
        The written value 
        The number of readers present were when value is written (should be 0) 
    Before a reader/writer attempts to access the shared variable it should wait some random amount of time 
        Note: This will help ensure that reads and writes do not occur all at once 
    Use pthreads, mutexes, and condition variables to synchronize access to the shared variable.

#Test Case 1:  Taking Equal number of readers and writers.
    
syam@syam-virtual-machine:~/Desktop$ nano Reader-Writer.c
syam@syam-virtual-machine:~/Desktop$ 
syam@syam-virtual-machine:~/Desktop$ gcc Reader-Writer.c -lpthread
syam@syam-virtual-machine:~/Desktop$ ./a.out
Enter the Initial  value of Shared Variable(INTEGER Format):10
========================================================================
Enter the number of readers
5
R0
R1
R2
R3
R4
=========================================================================
Enter the number of  writers:5
W0
W1
W2
W3
W4
=========================================================================
Thread Creating...!
=========================================================================
=======================================================================
W0 is waiting for Random Time = 3
Enter the number of times W0 wants to write:
1
W0 is Writing...
Enter the value 1 to write
2
UPDATED SHARED VARIABLE  = 12
========================================================================
R0 is waiting for random time = 6
R0 is waiting for random time = 7
R0 is waiting for random time = 5
R0 is waiting for random time = 3
R0 is waiting for random time = 5
Enter the number of times R0 wants to read:
Enter the number of times R0 wants to read:
Enter the number of times R0 wants to read:
Enter the number of times R0 wants to read:
Enter the number of times R0 wants to read:
1
R0 is reading
R0 is reading shared value = 12
Number of readers = 4
5
R0 is reading
R0 is reading shared value = 12
R0 is reading shared value = 12
R0 is reading shared value = 12
R0 is reading shared value = 12
R0 is reading shared value = 12
Number of readers = 3
6
R0 is reading
R0 is reading shared value = 12
R0 is reading shared value = 12
R0 is reading shared value = 12
R0 is reading shared value = 12
R0 is reading shared value = 12
R0 is reading shared value = 12
Number of readers = 2
3
R0 is reading
R0 is reading shared value = 12
R0 is reading shared value = 12
R0 is reading shared value = 12
Number of readers = 1
2
R1 is reading
R1 is reading shared value = 12
R1 is reading shared value = 12
Number of readers = 0
=======================================================================
W1 is waiting for Random Time = 6
Enter the number of times W1 wants to write:
1
W1 is Writing...
Enter the value 1 to write
3
UPDATED SHARED VARIABLE  = 15
========================================================================
=======================================================================
W1 is waiting for Random Time = 2
Enter the number of times W1 wants to write:
2
W1 is Writing...
Enter the value 1 to write
2
Enter the value 2 to write
3
UPDATED SHARED VARIABLE  = 20
========================================================================
=======================================================================
W1 is waiting for Random Time = 9
Enter the number of times W3 wants to write:
1
W3 is Writing...
Enter the value 1 to write
2
UPDATED SHARED VARIABLE  = 22
========================================================================
=======================================================================
W3 is waiting for Random Time = 1
Enter the number of times W3 wants to write:
2
W3 is Writing...
Enter the value 1 to write
2
Enter the value 2 to write
3
UPDATED SHARED VARIABLE  = 27
========================================================================
======================After Joining the Thread=========
Final Value Of Shared Variable is:27

