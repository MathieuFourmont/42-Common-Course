# 42-push_swap

Because swap_push isn't as natural

Given a set of integers, sort it using a predefined set of instructions using
two stacks. The instruction set is defined below. This program outputs a program
in push_swap instructions that sorts the input integers.

## Instruction set

For the following instructions, if the instruction is not possible, the part of
it that can't be executed won't.

| Code  | Instruction                         | Action                                                 |
| ----- | ----------------------------------- | ------------------------------------------------------ |
| `sa`  | swap a                              | swaps the 2 top elements of stack a                    |
| `sb`  | swap b                              | swaps the 2 top elements of stack b                    |
| `ss`  | swap a + swap b                     | both `sa` and `sb`                                     |
| `pa`  | push a                              | moves the top element of stack b at the top of stack a |
| `pb`  | push b                              | moves the top element of stack a at the top of stack b |
| `ra`  | rotate a                            | shifts all elements of stack a from bottom to top      |
| `rb`  | rotate b                            | shifts all elements of stack b from bottom to top      |
| `rr`  | rotate a + rotate b                 | both `ra` and `rb`                                     |
| `rra` | reverse rotate a                    | shifts all elements of stack a from top to bottom      |
| `rrb` | reverse rotate b                    | shifts all elements of stack b from top to bottom      |
| `rrr` | reverse rotate a + reverse rotate b | both `rra` and `rrb`                                   |

## Algorithm

For the stacks with size less than 6 -> small_sort.

In this project I used `Radix` sort as the main algorithm. `Radix` sort is an efficient algorithm to sort non-negative integers
with time complexity O(n). For example, we can sort following list of integers with this algorithm

```
87 487 781 100 101 0 1
```

Imagine there are 10 boxes labeled 0, 1, 2, …, 9

Start from the least significant digit (which is the digit in 1’s place), we put each number into the box which its digit corresponds to.

In the example, 87 has 7 in 1’s place, hence we put it in box 7. 487 also has 7 in 1’s place, so it should be placed in box 7 too (right behind 87) … And we repeat this process until every number is in one of the boxes.

```
box 0    100    0
box 1    781    101    1
box 2
box 3
box 4
box 5
box 6
box 7     87    487
box 8
box 9
```

After that, we connect every number according to the order of boxes.

```
100 0 781 101 1 87 487
```

As we can see, the numbers are sorted according to the digit in 1’s place. For those with the same digit in 1’s place, they’re sorted according to their order in the original list.

We repeat this procedure n times, where n is the number of digits of the largest number in the array
(In this case 783 => n = 3).

After doing it n times and connecting numbers after each cycle we will have array sorted.

### Simplify numbers

As we mentioned before, this algorithm is for non-negative integers. However, we’ll have negative numbers in this project, so we should simplify the numbers before we start.

To do so I gave indexes to each number in a stack. The smallest number gets index 0, the next smallest gets 1 and so on...
With this idea, we can simplify any list of integers to make them in the range [0,N) ( ≥ 0 and < N, N is the size of the list).

After simplification we need to do something with the boxes. We have only two stacks instead of 10 boxes. Hence, I sorted the number in base 2 (to use 2 stacks instead of 10).

As in radix sort, we need two boxes for 0 and 1 respectively. Here we treat A as box 1 and B as box 0. Then, we start from the rightmost bit to the leftmost bit.

At the i-th digit from the right, if the i-th digit of the top number of A is 0, we perform `pb` to put this number in stack B. Else, we perform `ra` to leave it in stack A. After we perform one operation on each number, each of them is in the box that corresponds to its digit, as how we put numbers in the boxes in radix sort.

After that, we perform `pa` until there are no numbers in stack B, as we connect the numbers in radix sort.

Repeated the same procedure for every bit and after that got the sorted numbers in the stack a.

### Performance of the Algorithm

My push_swap sorts

    3 numbers with maximum 2 instructions,
    4 numbers with maximum 6 instructions,
    5 numbers with maximum 10 instructions,
    100 numbers with maximum 1084 instructions => 3 points,
    500 numbers with maximum 6785 instructions => 4 points.

The algorithm is good enough to pass the project with 84%.

## Tester

There is also a tester attached to this project (credits to @Hevhove). The tester checks the validity of arguments and the algorithm itself on different numbers and different stack sizes (line 6). It will work with the checker_Mac program and will display "ok" or "ko" if the stack is well sorted or not and the number of actions.

To run the tester you need to make the code and then run the following command

```
bash test.sh
```

I'm also using this [python_visualizer](https://github.com/o-reo/push_swap_visualizer) to show the operations performed.

## Compiling and running

Run `make`. after which the project will be compiled. Then run the command

```
./push_swap $ARG
```
where ARG is just a sample of numbers. To run the checker you need to write these commands
```
ARG="1 5 2 4 3"
./push_swap $ARG | ./checker_Mac $ARG
