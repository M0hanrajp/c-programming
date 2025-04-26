https://stackoverflow.com/questions/5201852/what-is-a-thread-really

From the above discussion:
- In simpler terms (and glossing over some details): once upon a time, a computer program could only do one thing at once. 
  - So it did A, then after that B, then C, then... . In modern systems, this isn't ideal; for example you want to keep browsing 
    the web while downloading a file. 
  - So programs now have one or more 'threads'. Each 'thread' can only do one thing at once, but different threads can do things 
    simultaneously. 
  - Thread 1 can do A, then B, then C; thread 2 can do X, then Y, then Z. B can't start until A has finished, but A and X can happen at once.

Q: what is memory space & how it is different in process and threads ?

https://stackoverflow.com/questions/1096776/what-are-threads-what-is-a-thread/1096986#1096986

From the above discussion:
- An operating system gives a process memory to use. A process when started usually has one "thread" running within it.
- The thread is what the operating system schedules to run on the CPU and it is given an address to start executing instructions from.

https://softwareengineering.stackexchange.com/questions/225371/why-are-threads-called-threads

### Difference in process and threads
https://stackoverflow.com/questions/200469/what-is-the-difference-between-a-process-and-a-thread#:~:text=3,2%2C%202021%20at%2021:03

