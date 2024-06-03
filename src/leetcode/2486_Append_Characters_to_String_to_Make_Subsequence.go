package main

func appendingCharacters(s, t string) int {
	i, j := 0, 0

	for i < len(s) && j < len(t) {
		if s[i] == t[j] {
			j++
		}

		i++
	}

	return len(t) - j
}
