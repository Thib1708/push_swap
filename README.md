# push_swap
Push_swap is a 42 project whose ask you to sort a stack flowing some rules :
  - You had to use 2 stack : 
    - a : the stack which contain the integer to sort.
    - b : an empty stack.
  - You can only use the instructions bellow :
    - sa (swap a): Swap the first 2 elements at the top of stack a.
          Do nothing if there is only one or no elements.
    - sb (swap b): Swap the first 2 elements at the top of stack b.
          Do nothing if there is only one or no elements.
    - ss : sa and sb at the same time.
    - pa (push a): Take the first element at the top of b and put it at the top of a.
          Do nothing if b is empty.
    - pa (push a): Take the first element at the top of b and put it at the top of a.
          Do nothing if b is empty.
    ra (rotate a): Shift up all elements of stack a by 1.
        The first element becomes the last one.
    - rb (rotate b): Shift up all elements of stack b by 1. 
          The first element becomes the last one.
    - rr : ra and rb at the same time.
    - rra (reverse rotate a): Shift down all elements of stack a by 1.
           The last element becomes the first one.
    - rrb (reverse rotate b): Shift down all elements of stack b by 1. 
           The last element becomes the first one.
    - rrr : rra and rrb at the same time.
    
## Instal

Copy the command line and execute it in your consol.

```git clone git@github.com:Thib1708/push_swap.git```

## Runing 

Use the "make" command to compile the project then execute the new file created called "push_swap" with a list of integer.

```make; ./push_swap 20 8 2 15 -42```

## How does it work

### Fill stacks
The program takes as argument several non-duplicate integer either as one argument or each integer as an argument:

```./push_swap 20 8 2 15 -42```

```./push_swap "20 8 2 15 -42```

Using split and atoi I fill an first array of integer.

To sort the stack I use an algorithm that doesn't works whith negative integer so I had to replace each integer by an index depending on the value of the integer.

### Sort the stack
To sort the stack I use the radix algorithm here is an article about it :
[radix sort](https://leofu890806.medium.com/push-swap-tutorial-fa746e6aba1e)

To sort small stack I use an other methode : 
  -I first created a function to sort 3 integer.
  -To sort a 5 integer's stack I split it in half on the "a" stack I let the 3 biggest integer and on the "b" stack the smallest ones.
   I then sort "a" with the previous function and on the "b" stack I put the smallest number on the botom and the put back the numbers on top of "a".

This methode make you pass the project without the full score.

## Advice

I invite you not to clone my project but to try doing it by your self using the explanation I give to you.
My project is not the best a all their are plenty of better project but I think that mine is pretty simple to understand.
