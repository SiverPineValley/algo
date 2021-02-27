package solution

func Solution(X int, Y int, D int) int {
	distance := Y - X
	if distance == 0 {
		return 0
	}

	jumps := distance / D
	if distance%D > 0 {
		jumps++
	}

	return jumps
}
