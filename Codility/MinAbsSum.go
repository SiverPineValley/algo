package solution

// 미완성
func abs(a int) int {
	if a < 0 {
		return a * -1
	}

	return a
}

func min(a, b int) int {
	if a < b {
		return a
	}

	return b
}

func Solution(A []int) int {
	size := len(A)
	D := make([]int, size)
	D[0] = abs(A[0])
	D[1] = min(abs(D[0]+A[1]), abs(D[0]-A[1]))

	for idx := 2; idx < size; idx++ {
		a := min(abs(D[idx-2]+A[idx-1]+A[idx]), abs(D[idx-2]+A[idx-1]-A[idx]))
		b := min(abs(D[idx-2]-A[idx-1]+A[idx]), abs(D[idx-2]-A[idx-1]-A[idx]))
		D[idx] = min(a, b)
	}

	return D[size-1]
}
