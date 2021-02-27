package solution

// you can also use imports, for example:
// import "fmt"
// import "os"

func Solution(A []int) (result int) {
	m := map[int]bool{}
	max := len(A)
	for _, value := range A {
		m[value] = true
	}

	idx := 1
	result = 1
	for idx <= max {
		if _, exists := m[idx]; !exists {
			result = 0
			return
		}
		idx++
	}

	return
}
