package solution

func Solution(A []int) int {
	m := map[int]int{}

	for _, value := range A {
		if _, exists := m[value]; exists {
			if m[value] == 1 {
				m[value] = 0
			} else {
				m[value] = 1
			}
		} else {
			m[value] = 1
		}
	}

	var result int
	for key, value := range m {
		if value == 1 {
			result = key
			break
		}
	}

	return result
}
