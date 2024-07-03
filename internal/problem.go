package main

import (
	"encoding/json"
	"fmt"
	"io"
	"log"
	"net/http"
)

const (
	BAEKJOON   = "BOJ"
	CODEFORCES = "CF"
	ATCODER    = "AT"
	LEETCODE   = "LEET"
)

type Problem struct {
	platform string
	number   string
	name     string
}

func NewProblem(name string) *Problem {
	strs := make([]string, 2)
	if name[0] == 'B' {
		strs[0] = BAEKJOON
		strs[1] = name[3:]
	}

	problem := &Problem{
		platform: strs[0],
		number:   strs[1],
	}
	problem.getProblemName()
	return problem
}

func (p *Problem) getProblemName() {
	resp, err := http.Get(fmt.Sprintf("https://solved.ac/api/v3/problem/show?problemId=%s", p.number))
	if err != nil {
		log.Fatal(err)
	}
	defer resp.Body.Close()

	body, err := io.ReadAll(resp.Body)

	var data map[string]interface{}
	err = json.Unmarshal(body, &data)
	if err != nil {
		log.Fatal(err)
	}

	problemName, ok := data["titleKo"].(string)
	if !ok {
		log.Fatal(err)
	}

	p.name = problemName
}
