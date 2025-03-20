# 📊 push_swap

push_swap is an algorithm project that sorts a given list of random numbers with a limited set of instructions, using the lowest possible number of actions.

![](https://github.com/char-projects/push_swap/blob/master/sorting.gif)

## Usage

Git clone the repository and cd into it. Then use ```make``` to compile.

Then run it with :

```shell
./build/push_swap <numbers>
```
or
```shell
./build/push_swap "<numbers>"
```


The numbers provided can be positive or negative integers. There must not be any duplicates. For example :

```shell
./push_swap 9 0 -217 23647 -21474836
```

If the arguments are valid, the program will output the most efficient list of actions to sort the list.


## Push_Swap Rules

The program is only allowed two stacks to work with, stack A and stack B. All the numbers are initially added to stack A, and B is empty.

The possible actions are:

* ```pa``` (push A): Take the first element at the top of B and put it at the top of A. Do nothing if B is empty.
* ```pb``` (push B): Take the first element at the top of A and put it at the top of B. Do nothing if A is empty.
* ```sa``` (swap A): Swap the first 2 elements at the top of stack A. Do nothing if there is only one or no elements.
* ```sb``` (swap B): Swap the first 2 elements at the top of stack B. Do nothing if there is only one or no elements.
* ```ss```: ```sa``` and ```sb``` at the same time.
* ```ra``` (rotate A): Shift all elements of stack A up by 1. The first element becomes the last one.
* ```rb``` (rotate B): Shift all elements of stack B up by 1. The first element becomes the last one.
* ```rr```: ```ra``` and ```rb``` at the same time.
* ```rra``` (reverse rotate A): Shift all elements of stack A down by 1. The last element becomes the first one.
* ```rrb``` (reverse rotate B): Shift all elements of stack b down by 1. The last element becomes the first one.
* ```rrr``` : ```rra``` and ```rrb``` at the same time.


## Efficiency
 
* Sorting 3 values: no more than 3 actions
* Sorting 5 values: no more than 12 actions
* Sorting 100 values: less than 700 actions
* Sorting 500 values: less than 5500 actions
