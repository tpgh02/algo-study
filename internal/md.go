package main

import (
	"fmt"
	"os"
	"path"
	"strings"
)

type MD struct {
	Body string
}

func NewMD(week string) MD {
	return MD{
		Body: "# " + strings.ToUpper(week),
	}
}

func (m *MD) AddProblem(Problem *Problem) {
	m.Body = m.Body + "\n\n### " + Problem.platform + "_" + Problem.number + ": " + Problem.name + "\n\n"
}

func (m *MD) StartSolved() {
	m.Body = m.Body + `|이름|풀이 링크|
|--|--|
`
}

func (m *MD) AddSolvedBy(problemDir os.DirEntry, solvedBy os.DirEntry) {
	name := solvedBy.Name()
	strs := strings.Split(name, ".")

	m.Body = m.Body +
		fmt.Sprintf("|%s| [link](%s)\n", strs[0], path.Join(problemDir.Name(), solvedBy.Name()))
}

func (m *MD) AddLine() {
	m.Body = m.Body + "---\n"
}
