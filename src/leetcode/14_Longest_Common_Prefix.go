package main

import "sort"

func longestCommonPrefix(strs []string) string {
	ans := ""

	sort.Strings(strs)

	firstStr := strs[0]
	lastStr := strs[len(strs)-1]

	for i := 0; i < len(firstStr) && i < len(lastStr); i++ {
		if firstStr[i] != lastStr[i] {
			return ans
		}
		ans += string(firstStr[i])
	}

	return ans
}

