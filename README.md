# Philosophers

The goal of this project is to do algorithms and understand threading in C.

The program takes as parameters :
* the number of philosophers
* the time they take to eat
* the time they take to die without eating.

To eat a philosopher must have two forks. There is one fork per philosophers, so they must take a fork from their right or left neighbors.

Each philosopher is a new thread and here we have one mutex per fork.

The goal is to stop the program from the moment a philosopher dies.

![image](https://github.com/HugoKovac/Philosophers/blob/main/Table.png)
