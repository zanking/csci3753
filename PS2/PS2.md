Problem Set 2     Zanqing Feng

1. 

lock mutex_lock;
semaphore east_sem, west_sem;
int east_cars = 0, west_cars = 0;

go_east() {
    P(east_sem);
    P(mutex_lock);
    east_cars++;
    if (east_cars == 1) {
        P(west_sem); // lock the west side
    }
    V(mutex_lock);
    V(east_sem);
    // code to cross the bridge
    P(mutex_lock);
    east_cars--;
    if (!east_cars) {
        V(west_sem); // release west side
    }
    V(mutex_lock);
}

go_west() {
    P(west_sem);
    P(mutex_lock);
    west_cars++;
    if (west_cars == 1) {
        P(east_cars); // lock the east side
    }
    V(mutex_lock);
    V(west_sem);
    // code to cross the bridge
    P(mutex_lock);
    west_cars--;
    if (!west_cars) {
        V(east_sem); // release east side
    }
    V(mutex_lock);
}






2.
// this is pseudocode
lock mutex_lock;
condition c;
int t1_complete = 0;

// Task T1
Acquire(mutex_lock);
// execute code c1
t1_complete = 1;
Release(mutex_lock);
c.signal();
// End Task T1

// Task T2
Acquire(mutex_lock);
while (!t1_complete) {
    Release(mutex_lock);
    c.wait();
    Acquire(mutex_lock);
}
// execute code c2
Release(mutex_lock);
// End Task T2
3.
The third solution of the R / W problem is no starvation because of the 2 main concepts. When the writing thread wants to enter the critical section to write data, read the thread will have to wait until the next arrival, writing thread written, and read the current thread can continue to read. This prevents write threads from starvation. On the other hand, the read thread is not hungry, as long as there is no thread, it allows multiple readers to access the critical section.




4.
No, the swap () function is not thread safe for the following reasons. Suppose there are two threads (A and B) call swap () function. If A enters the switch () and suspends execution after "* y = * Z" (via interrupt or context switch), the result is now half of the exchange has occurred, and the reference to y is now lost. If a context switch occurs in the middle of the exchange, the temp value will be rewritten, and if the A to resume execution (context switching back), the thread in the A y value will be lost (the previously stored in the temp) it will use the wrong temp.
Yes, swap () is reentrant because there is no use of semaphores, monitors or locks. Therefore, this method does not generate the risk of deadlock, and will be normal.

5. 
Memory sharing IPC is ideal for this situation because you have a fairly large file (10 MB) that you want to pass from a process P1 to another process P2. Process P1 can first read the file to the main memory, wake up the process P2, while the pointer to the memory of the stored file, and asynchronously waiting for P2 to complete. Once the process P2 wakes up, it will synchronize access to the memory and begin to compress the data in the memory location. Once the compression is complete, P2 will release the lock on the memory, send an interrupt to the P1 to warn that the file has been compressed and restored to sleep.

