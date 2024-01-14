package main

import "sort"

func closeStrings(word1 string, word2 string) bool {
	if len(word1) != len(word2) {
		return false
	}

	wordCnt1 := make([]int, 26)
	wordCnt2 := make([]int, 26)

	for i := 0; i < len(word1); i++ {
		wordCnt1[int(word1[i]-'a')]++
		wordCnt2[int(word2[i]-'a')]++
	}

	for i := 0; i < 26; i++ {
		if wordCnt1[i] == 0 && wordCnt2[i] != 0 {
			return false
		}

		if wordCnt2[i] == 0 && wordCnt1[i] != 0 {
			return false
		}
	}

	sort.Ints(wordCnt1)
	sort.Ints(wordCnt2)

	for i := 0; i < len(wordCnt1); i++ {
		if wordCnt1[i] != wordCnt2[i] {
			return false
		}
	}

	return true
}

