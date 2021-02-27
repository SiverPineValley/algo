package solution

func Solution(A []int, K int) []int {
	length := len(A)
	if length == K {
		return A
	}

	var Arr = make([]int, length)
	for idx, value := range A {
		target := (idx + K) % length
		Arr[target] = value
	}

	return Arr
}
