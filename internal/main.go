package main

import (
	"log"
	"os"
	"path"
	"strings"
)

func main() {
	weeks := getWeekDir()

	for _, week := range weeks {
		ReadWeekAndUpdateMD(week)
	}

}

func ReadWeekAndUpdateMD(week os.DirEntry) error {
	problemDirs, err := os.ReadDir(week.Name())

	if err != nil {
		return err
	}

	md := NewMD(week.Name())

	for _, problemDir := range problemDirs {
		if !problemDir.IsDir() {
			continue
		}

		problem := NewProblem(problemDir.Name())
		md.AddProblem(problem)

		problemDirPath := path.Join(week.Name(), problemDir.Name())

		solvedByList, err := os.ReadDir(problemDirPath)
		if err != nil {
			log.Fatal(err)
		}

		md.StartSolved()
		for _, solvedBy := range solvedByList {
			md.AddSolvedBy(problemDir, solvedBy)
		}
		md.AddLine()
	}

	mdpath := path.Join(week.Name(), "README.md")
	os.WriteFile(mdpath, []byte(md.Body), 0644)

	return nil
}

func getWeekDir() []os.DirEntry {
	entrySet, err := os.ReadDir(".")
	if err != nil {
		log.Fatal(err)
	}

	result := make([]os.DirEntry, 0)
	for _, entry := range entrySet {
		if strings.HasPrefix(entry.Name(), "week") {
			result = append(result, entry)
		}
	}
	return result
}
