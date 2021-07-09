# B4-S4
###### tags: `B4-S4` `github`

B4-S4 is a SAT-based oscillator finder of Conway's game of life under rule B4/S4.

## Rule
Given a $n\times m$ table, each grid can be either *alive* of *dead*, it is called the state at time $0$, and given the state at time $t$, the state at time $t+1$ is followed by the rules
- if there are exactly 4 of a cell's neighbors are *alive* at $t$, then the cell is *alive* at $t+1$.
- otherwise, the cell is *dead* at $t+1$.

where the neighbors of a cell at coordinate $(x,y)$ is defined by
$$
N_{(x,y)}=\{(a,b)\mid |x-a|,|y-b|\leq 1\}\setminus\{(x,y)\}
$$
namely the 8 cells nearly the cell $(x,y)$.

## Oscillator
we call the initial state $S_0$, its next state $S_1$ followed by the rule, and $S_2,S_3,\ldots$ and so on. An *oscillator* is a state $O_0$ if
- $O_0$ is nonempty
- $O_0=O_t$ for some positive integer $t$

if such $t$ is the minimum number satisfying the condition, then $t$ is called the *period*. The following figures shows an example of *oscillator* of period $2$.

| $O_0$ | $O_1$ | $O_2$ |
| -------- | -------- | -------- |
| ![](https://i.imgur.com/9ahOM5k.png)     | ![](https://i.imgur.com/LZhIWIC.png)| ![](https://i.imgur.com/9ahOM5k.png)     |

And the problem we interests is to find out all *oscillator* or find a general way to construct *oscillator*.

## SAT Problem
Given boolean variables $x_1,x_2,\ldots,x_n$, an boolean expression is called *CNF* if it is in the form
$$
F(x_1,\ldots,x_n)=\bigwedge\left(\bigvee x_i\right)
$$

and to find an assignment of $x_1,\ldots x_n$ is called *SAT problem*. It is an *NP-complete* problem, but with some efficient algorithm, we can solve it with quite good large number. Also, the aim of the program is to reduct the oscillator finding to an CNF and solve it by SAT solver called *MiniSat*.

## Remarks
- Unlike original Game of Life, the rule ensure the cells won't exceed the original margin, namely $n\times m$.
- Unlike original Game of Life, there is no *Still lifes*, namely oscillator with period $1$.

## Finding
The smallest oscillator is in size $7\times7$, we called *fire*

| fire0 | fire1 |
| -------- | -------- |
| ![](https://i.imgur.com/FiiMoyh.png)| ![](https://i.imgur.com/aQJYPUe.png)|

For $8\times8$, there are $4$ types of oscillator.


|  | time 0 | time 1 |
| -------- | -------- | -------- |
| Crystal     | ![](https://i.imgur.com/4HXiNmq.png)| ![](https://i.imgur.com/1fprRl9.png)|
|Currency|![](https://i.imgur.com/KEGQNZ0.png)|![](https://i.imgur.com/dnsSoiq.png)|
|Face|![](https://i.imgur.com/EkujDfp.png)|![](https://i.imgur.com/SThqv7D.png)|
|Robot|![](https://i.imgur.com/xQxZXn6.png)|![](https://i.imgur.com/TTPpLwt.png)|

For $8\times9$, there are 2 types.


|  | time 0 | time 1 |
| -------- | -------- | -------- |
| Deer     | ![](https://i.imgur.com/VM5la1a.png)| ![](https://i.imgur.com/wKu4eqQ.png)|
|Shuriken|![](https://i.imgur.com/hVmOvZp.png)|![](https://i.imgur.com/pVInQEB.png)|

And further we have some complicated and not well-symmetrical oscillators. The number of oscillator increases rapidly when the size comes to $12$. Here are some examples.


|  | time 0 | time 1 |
| -------- | -------- | -------- |
| Girrafe     | ![](https://i.imgur.com/5D0q63T.png)| ![](https://i.imgur.com/fR1mJX5.png)     |
|Parallelogram|![](https://i.imgur.com/9V5LNvD.png)|![](https://i.imgur.com/SbMEIZb.png)|
|Tilt|![](https://i.imgur.com/cY7UAYV.png)|![](https://i.imgur.com/NnIYbb7.png)|

## Theorem
There are infinitely many oscillators, since we can repeat this pattern for any finite times

| time 0 | time 1 | 
| -------- | -------- | 
| ![](https://i.imgur.com/dkZVmnT.png)| ![](https://i.imgur.com/PisjCMu.png)| 


## Hypothesis
- all oscillators are with period 2