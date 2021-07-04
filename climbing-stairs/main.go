package main

import (
	"fmt"
)

func main() {
	ways := climbStairs(5)
	fmt.Println("ways", ways)
}

func climbStairs(n int) int {
    memo := make(Memo)
    
    return memo.Climb(n)
}

type Memo map[int]int

func (m Memo) Climb(n int) int {
    if n == 1 {
        return 1
    }
    if n == 2 {
        return 2
    }
    if n == 3 {
        return 3
    }
    if _, ok := m[n-1]; !ok {
        m[n-1] = m.Climb(n-1)
    }
    if _, ok := m[n-2]; !ok {
        m[n-2] = m.Climb(n-2)
    }
    return m[n-1] + m[n-2]
}

// Lets denote f(n) as the number of ways that we can climb for a staircase with n steps
// for f(n = 1) = 1
// for f(n = 2) = 2  ({1, 1} & {2})
// for f(n = 3) = 3 ({1, 1, 1}, {1, 2}, {2, 1})
// for f(n = 4) = 5  ({1, 1, 1, 1}, {1, 1, 2}, {2, 1, 1}, {1, 2, 1}, {2, 2})

// notice that for f(n)
// if we take one step, then the remaining ways are f(n-1) -> n way one
// if we take two step, then the remaining ways are f(n-2) -> n way two



