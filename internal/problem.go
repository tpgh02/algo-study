package main

const (
	BAEKJOON   = "BOJ"
	CODEFORCES = "CF"
	ATCODER    = "AT"
	LEETCODE   = "LEET"
)

type Problem struct {
	platform string
	number   string
}

func NewProblem(name string) Problem {
	strs := make([]string, 2)
	if name[0] == 'B' {
		strs[0] = BAEKJOON
		strs[1] = name[3:]
	}

	return Problem{
		platform: strs[0],
		number:   strs[1],
	}
}
