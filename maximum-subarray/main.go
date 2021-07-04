package main

import (
	"fmt"
)

func main() {
    // https://leetcode.com/problems/maximum-subarray/
	max := maxSubArray([]int{-2, 1})
	fmt.Println(max)
}

// https://stackoverflow.com/questions/6878590/the-maximum-value-for-an-int-type-in-go
const MaxUint = ^uint(0) 
const MinUint = 0 
const MaxInt = int(MaxUint >> 1) 
const MinInt = -MaxInt - 1

// learning dynamic programming memoization
// O(n^2) solution
func maxSubArray(nums []int) int {
    memo := make(Memo)
    
    max := MinInt 
    for i := 0; i < len(nums); i++ {
        for j := i; j < len(nums); j++ {
            sum := memo.Sum(nums, j) - memo.Sum(nums, i - 1)
            if max < sum {
                max = sum
            }
        }
    }
    
    return max
}

type Memo map[int]int

// Sum => sum(nums[0:i+1])
// i inclusive!
func (l Memo) Sum(nums []int, i int) int {
    if i < 0 {
        return 0
    }
    if i == 0 {
        return nums[0]
    }
    if i == 1 {
        return nums[1] + nums[0]
    }

    if _, ok := l[i-1]; !ok {
        l[i-1] = l.Sum(nums, i-1) 
    }

    return nums[i] + l[i-1]
} 
