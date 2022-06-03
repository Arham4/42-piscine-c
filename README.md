# 42 Silicon Valley - Piscine C
### Projects Breakdown
- **Harassment Policy** - Agreeing to never force somebody to 
have tea when they don't want it ([credits](https://www.youtube.com/watch?v=oQbei5JGiT8)). - 
![#98fb98](https://via.placeholder.com/15/98fb98/98fb98.png) Succeeded with 100%
- **Day 00** - Basics of Unix - ![#f03c15](https://via.placeholder.com/15/f03c15/f03c15.png) Failed with 0%
- **Day 01** - Basic bash scripts - ![#f03c15](https://via.placeholder.com/15/f03c15/f03c15.png) Failed with 10%
- **Day 02** - Introduction to C - ![#98fb98](https://via.placeholder.com/15/98fb98/98fb98.png) Succeeded with 65%
- **Day 03** - More Introduction to C - ![#98fb98](https://via.placeholder.com/15/98fb98/98fb98.png)
Succeeded with 65%
- **Day 04** - Recursion - ![#98fb98](https://via.placeholder.com/15/98fb98/98fb98.png) Succeeded with 50%
- **Individual Project: Sastantua** - Make an ASCII-art pyramid 
given the  amount of bases in the pyramid, with a door and a 
door handle. Only about 3% of Pisciners have ever had success
in this project. - ![#98fb98](https://via.placeholder.com/15/98fb98/98fb98.png) Succeeded with 100%
- **Group Project: Rush 00** - Make an ASCII-art rectangle with
a different pattern per group. - ![#f03c15](https://via.placeholder.com/15/f03c15/f03c15.png) Failed with 0%
- **Day 05** - Review of C material - ![#f03c15](https://via.placeholder.com/15/f03c15/f03c15.png) Failed with 10%
- **Day 06** - Program arguments - ![#98fb98](https://via.placeholder.com/15/98fb98/98fb98.png) Succeeded with 100%
- **Day 07** - Pointers and arrays - ![#98fb98](https://via.placeholder.com/15/98fb98/98fb98.png) Succeeded with 30%
- **Individual Project: Match-N-Match** - Traverse two strings and
see if they match, while also respecting the REGEX wildcard symbol
in the second string. - ![#98fb98](https://via.placeholder.com/15/98fb98/98fb98.png) Succeeded with 100%
- **Group Project: Rush 01** - Make a 9x9 Sudoku-board solver
given an initial grid. - ![#f03c15](https://via.placeholder.com/15/f03c15/f03c15.png) Failed with 29%
- **Day 08** - Header files and macros - ![#98fb98](https://via.placeholder.com/15/98fb98/98fb98.png) Succeeded with 70%
- **Day 09** - A fun review day in which exercises unlocked
every hour in a 24-hour time frame. Every assignment followed
a story-line. - ![#98fb98](https://via.placeholder.com/15/98fb98/98fb98.png) Succeeded with 48%
- **Day 10** - Makefiles and functional programming - ![#f03c15](https://via.placeholder.com/15/f03c15/f03c15.png) Failed with 0%
- **Day 11** - Linked lists - ![#f03c15](https://via.placeholder.com/15/f03c15/f03c15.png) Failed with 21%
- **Day 12** - Recreating bash scripts in C - ![#98fb98](https://via.placeholder.com/15/98fb98/98fb98.png) Succeeded with 50%
- **Day 13** - Binary trees, Binary search trees, and 
Red-Black trees - ![#98fb98](https://via.placeholder.com/15/98fb98/98fb98.png) Succeeded with 30%
- **Individual Project: EvalExpression** - Make a calculator
that respects the rules of PEMDAS (or BODMAS) for a given expression
that may or may not have white-spaces. - ![#f03c15](https://via.placeholder.com/15/f03c15/f03c15.png) Failed with 0%
- **Group Project: Rush 02** - Make a program that is a 
Rush-00-identifier. The program should take in input from
the standard input and identify which sub-Rush-00 project
was executed. - ![#98fb98](https://via.placeholder.com/15/98fb98/98fb98.png) Succeeded with 100%
- **BSQ** - Find the largest square in a 2-dimensional character
matrix and mark it with a given "fill" character. The program
should read from both standard input and from files. Grading
was done not only by functionality, but by the efficiency of
the program in both speed and memory. Only about 1% of Pisciners
have ever had success in this project. - ![#f03c15](https://via.placeholder.com/15/f03c15/f03c15.png) Failed with 0%

Final Piscine level: **7.4**

### Grading at 42
Grading is done by an auto-grader called Moulinette. "She" 
requires assignments to be pushed to the respective Git 
repository by 11:42 PM. Once pushed, one is required to get
evaluated by their peers (with the exception of Rush projects).
For the daily projects, one must get evaluated two times, while
for the individual projects one must get evaluated three times.
After one is evaluated by their peers, Moulinette grades the user.
**She is strict.** The moment an exercise is marked wrong, she
stops incrementing one's grade. That is, for example, **if one 
did 10 exercises in a day and got 9 of the exercises correct, 
but the first exercise wrong, they would get a 0 for the day.**


She could experience a time-out (a program never ending), a KO
(an incorrect output), or a Norme-error. All projects are
required to respect The Norm, which is a set of rules. For 
example, one may not have more than 25 lines in a function, a 
line may not have more than 80 characters, a file may not have 
more  than 5 functions, the declaration of all variables must 
be at  the top of the function, declaration and initialization
of variables in the same line is forbidden, and many more, 
with the aforementioned ones being the most common.

One is regarded as "successful" in a given project (besides Rush)
if one gets a 25 or above. In a Rush, one requires a 50 to have
success.

### Grading Breakdown
- **Harassment Policy** - Agreeing to never force somebody to 
have tea when they don't want it ([credits](https://www.youtube.com/watch?v=oQbei5JGiT8)). 
```diff
+ Succeeded with 100%
+ policy: OK
```
- **Day 00** - Basics of Unix
```diff
- Failed with 0%
+ ex00: OK
+ ex01: OK
- ex02: KO
- ex03: KO
- ex04: KO
+ ex05: OK
+ ex06: OK
- ex07: KO
+ ex08: OK
- ex09: KO
+ ex10: OK
```
- **Day 01** - Basic bash scripts
```diff
- Failed with 10%
+ ex00: OK
- ex01: KO
+ ex02: OK
+ ex03: OK
- ex04: KO
+ ex05: OK
- ex06: KO
- ex07: KO
+ ex08: OK
```
- **Day 02** - Introduction to C 
```diff
+ Succeeded with 65%
+ ex00: OK
+ ex01: OK
+ ex02: OK
+ ex03: OK
+ ex04: OK
+ ex05: OK
- ex06: Does not compile
- ex07: KO
```
- **Day 03** - More Introduction to C 
```diff
+ Succeeded with 65%
+ ex00: OK
+ ex01: OK
+ ex02: OK
+ ex03: OK
+ ex04: OK
+ ex05: OK
+ ex06: OK
+ ex07: OK
- ex08: KO
- ex09: KO
```
- **Day 04** - Recursion 
```diff
+ Succeeded with 50%
+ ex00: OK
+ ex01: OK
+ ex02: OK
+ ex03: OK
+ ex04: OK
+ ex05: OK
- ex06: KO
+ ex07: OK
+ ex08: OK
- ex09: Nothing turned in
```
- **Individual Project: Sastantua** - Make an ASCII-art pyramid 
given the  amount of bases in the pyramid, with a door and a 
door handle. Only about 3% of Pisciners have ever had success
in this project. - ![#98fb98](https://via.placeholder.com/15/98fb98/98fb98.png) Succeeded with 100%
- **Group Project: Rush 00** - Make an ASCII-art rectangle with
a different pattern per group. - ![#f03c15](https://via.placeholder.com/15/f03c15/f03c15.png) Norme error - Failed with 0%
- **Day 05** - Review of C material
```diff
- Failed with 10%
+ ex00: OK 
+ ex01: OK 
+ ex02: OK 
+ ex03: OK 
+ ex04: OK 
- ex05: KO 
+ ex06: OK 
+ ex07: OK 
+ ex08: OK 
+ ex09: OK 
+ ex10: OK 
+ ex11: OK 
+ ex12: OK 
+ ex13: OK 
+ ex14: OK 
+ ex15: OK 
+ ex16: OK 
+ ex17: OK 
+ ex18: OK 
+ ex19: OK
- ex20: Nothing turned in 
- ex21: Nothing turned in 
- ex22: Nothing turned in 
- ex23: Nothing turned in
```
- **Day 06** - Program arguments 
```diff
+ Succeeded with 100%
+ ex00: OK 
+ ex01: OK 
+ ex02: OK 
+ ex03: OK 
+ ex04: OK 
```
- **Day 07** - Pointers and arrays 
```diff
+ Succeeded with 30%
+ ex00: OK 
+ ex01: OK 
+ ex02: OK 
- ex03: KO 
+ ex04: OK 
+ ex05: OK 
- ex06: KO 
+ ex07: OK
```
- **Individual Project: Match-N-Match** - Traverse two strings and
see if they match, while also respecting the REGEX wildcard symbol
in the second string. - ![#98fb98](https://via.placeholder.com/15/98fb98/98fb98.png) Succeeded with 100%
- **Group Project: Rush 01** - Make a 9x9 Sudoku-board solver
given an initial grid. - ![#f03c15](https://via.placeholder.com/15/f03c15/f03c15.png) Failed with 29%
- **Day 08** - Header files and macros 
```diff
+ Succeeded with 70%
+ ex00: OK 
+ ex01: OK 
+ ex02: OK 
+ ex03: OK 
+ ex04: OK 
+ ex05: OK 
- ex06: KO 
```
- **Day 09** - A fun review day in which exercises unlocked
every hour in a 24-hour time frame. Every assignment followed
a story-line. 
```diff
+ Succeeded with 48%
+ ex00: OK 
- ex01: KO 
- ex02: KO 
+ ex03: OK 
- ex04: Does not compile 
+ ex05: OK 
+ ex06: OK 
+ ex07: OK 
+ ex08: OK 
+ ex09: OK 
+ ex10: OK 
+ ex11: OK 
+ ex12: OK 
- ex13: KO 
- ex14: Does not compile 
- ex15: Does not compile 
+ ex16: OK 
- ex17: KO 
- ex18: Does not compile 
+ ex19: OK 
- ex20: KO 
- ex21: Nothing turned in 
- ex22: KO 
+ ex23: OK
```
- **Day 10** - Makefiles and functional programming 
```diff
- Failed with 0%
- ex00: KO 
+ ex01: OK 
+ ex02: OK 
+ ex03: OK 
+ ex04: OK 
+ ex05: OK 
- ex06: KO 
+ ex07: OK 
- ex08: KO 
- ex09: KO
```
- **Day 11** - Linked lists
```diff
- Failed with 21%
+ ex00: OK 
+ ex01: OK 
+ ex02: OK 
+ ex03: OK 
+ ex04: OK 
- ex05: KO 
+ ex06: OK 
+ ex07: OK 
+ ex08: OK 
+ ex09: OK 
+ ex10: OK 
+ ex11: OK 
+ ex12: OK 
+ ex13: OK 
+ ex14: OK 
- ex15: Nothing turned in 
- ex16: Nothing turned in 
- ex17: Nothing turned in
```
- **Day 12** - Recreating bash commands in C 
```diff
+ Succeeded with 50%
+ ex00: OK 
+ ex01: OK 
+ ex02: OK 
- ex03: Nothing turned in 
- ex04: Nothing turned in
```
- **Day 13** - Binary trees, Binary search trees, and 
Red-Black trees 
```diff
+ Succeeded with 30%
+ ex00: OK 
+ ex01: OK 
+ ex02: OK 
+ ex03: OK 
- ex04: Segmentation fault 
+ ex05: OK 
+ ex06: OK 
- ex07: Norme error 
- ex08: Does not compile 
- ex09: Nothing turned in
```
- **Individual Project: EvalExpression** - Make a calculator
that respects the rules of PEMDAS (or BODMAS) for a given expression
that may or may not have white-spaces. - ![#f03c15](https://via.placeholder.com/15/f03c15/f03c15.png) Norme error - Failed with 0%
- **Group Project: Rush 02** - Make a program that is a 
Rush-00-identifier. The program should take in input from
the standard input and identify which sub-Rush-00 project
was executed. - ![#98fb98](https://via.placeholder.com/15/98fb98/98fb98.png) Succeeded with 100%
- **BSQ** - Find the largest square in a 2-dimensional character
matrix and mark it with a given "fill" character. The program
should read from both standard input and from files. Grading
was done not only by functionality, but by the efficiency of
the program in both speed and memory. Only about 1% of Pisciners
have ever had success in this project. - ![#f03c15](https://via.placeholder.com/15/f03c15/f03c15.png) Failed with 0%
```
Only one problem with the project: Cannot read STDIN correctly 
(when it is inserted using the < notation). I.E.:

./bsq < test1.txt test2.txt
```
