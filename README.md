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
