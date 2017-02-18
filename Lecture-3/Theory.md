# Lecture 3

### Programming Questions to practise:
1. **Modify the previous program (Lecture-2 program)by making the main() function choiced based i.e when the program executes, your code should allow the user to select the operations(Push or Pop) which user wants to do on the Stack.**

2. **Write a program to check whether the string given by user is PALINDROME or not using a Stack.**

3. **Imagine you have two Stacks S1 and S2. The Stack S1 contains some data while S2 is empty. Write a function which takes these two as arguments and sorts the Stack S1 using the Stack S2. Make sure your fuinction does not break rules of Stack.**
***

## USES OF STACK

Stack is an important data structure used by C language compiler in many programming situations. Some common cases where compiler internally uses Stack are:

1. **Local Variable**
   All local data stored inside functions gets copied in a Stack. For example:
    ```c
    #include <stdio.h>
    
    void main(){
        int a = 10, b = 20, c = 30;
        printf("%d");
    }
    ```
    
   The code shown above displays **30 as output** wven though we have not mentioned tyhe name of variable in printf. It is because **30** is the top value in the Stack and the compiler simply prints this value when nothing is passed.
    
2. **To store return address in a function call**
   Whenever the compiler encounters function call, it maintains **Stack frame** i.e before leaving the calling function, the compiler pushes the address of next line inside the Stack. Along with this address if some local data is to be send, it is also pushed. Then the compiler executes the called function and when it returns back, it first pops the current top element from the Stack and the resumes the code in calling function. So, we can say that the compiler alwats visits the Stack two times whenever it handles the function call.
   
3. **Argument Passing**
   Few examples of argument passing are shown below: 
   ```c
   #include <stdio.h>
   
   void main(){
        int a = 10;
        int b = 20;
        int c = 30;
        printf("%d %d %d",a,b,c);
   }
   ```
   In the above example, the output will be: **10 20 30** which can be easily predicted observing the code. Here, the key thing to keep in mind is that, at first value of **c** is poped out, then value of **b**  is popped out and finally value of **a** is popped out of the Stack (**RIGHT TO LEFT PROCESS**)and then the final output is printed.
   
   Lets consider another program to understand this concept better:
   ```c
   #include <stdio.h>
   
   void main(){
        int i = 10;
        printf("%d %d %d",++i,i++,i++);
   }
   ```
   What will be the output of the above program? If you figured out the output to be : **11 11 12** then you are wrong. The output of the above program is: **13 11 10**. Looks weird to you? Let me explain why is the output so. 
   
   As I explained earlier, inside the printf function the arguments will be evaluated from **Left to Right**. So, at first **10** will be pushed into the Stack, and then incremented by 1 since it is postfix and value of **i** now becomes **11**. Again, this **11** will be pushed into the Stack and incremented by 1 so that now value of **i** becomes **12**. Finally, due to prefix, it is first incremented by 1 so that its value becomes **13** now and then it is pushed inside the Stack. So the final output is: **13 11 10** not **11 11 12**.

	Now try to predict the output of this code below:
    ```c
    #include <stdio.h>
   
   void main(){
        int a = 10;
        printf("%d %d %d",a==10, a>5, a=5);
   }
    ```
	The output of above code is : **0 0 5**. Remember, the argument will be evaluated from **Left to Right**. So, at first **a=5** will execute resulting change in value of a to **5** and **5** will be pushed to Stack. Then **a>5** will be evaluated and the condition is false since a=5 is not greater than 5 so **0** will be pushed into the Stack. Finally, the third condition **a==10** will be also evaluated **False** so again **0** will be pushed into the Stack.
    
    Again try to predict the output of this code now:
    ```c
    #include <stdio.h>

    void main(){
        int i;
        printf("%d %d %d",i,i+1,i=5);
    }
    ```
    The output of this code above is: **5 6 5**. Did you get it right?
    
4. **Expressions**
	Compiler use Stack whenever they find an infix expressions and they have to convert it into prefix or postfix form.
    
    In data structures, any statement which contains operators and operands is called as an expression and based upon the placement of operators, expressions are of **three** types:
    * **Infix Expression**: The operator is in between the operands, e.g **a+b**
    * **Prefix Expression**: also known as **Polish Notation** and contain operator before operands, e.g **+a b**
    * **Postfix Expression**: also known as **Reverse Polish Notation** and contain operator after operands, e.g **a b+**

***

### Why compiler converts infix expression to prefix or postfix expression?
We know that to solve an infix operations, the knowledge of operator precedence and associativity is needed. But execution of any instruction in program isn't done by compiler but rather handled by the CPU and CPU doesn't know anything about precedence and associativity  of the operators. So, to make it easier for CPU to solve the expression, the compiler of every programming language converts these infix operations to prefix or postfix form.

The Sepeciality of these form is that, these expressions can be evaluated from one end to the other end without the knowledge of operator precendence or associativity and results can be obtained.