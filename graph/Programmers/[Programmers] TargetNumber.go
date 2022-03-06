type Queue []interface{}

func (q *Queue) IsEmpty() bool {
	return len(*q) == 0
}

func (q *Queue) Push(v interface{}) {
	*q = append(*q, v)
}

func (q *Queue) Pop() (v interface{}) {
	if q.IsEmpty() {
		return nil
	}

	v = (*q)[0]
	*q = (*q)[1:]
	return
}

type Node struct {
	Now   int
	Value int
}

func solution(numbers []int, target int) (result int) {
	op := []int{-1, 1}
	length := len(numbers) - 1
	q := Queue{}

	q.Push(Node{0, numbers[0]})
	q.Push(Node{0, numbers[0] * -1})

	for !q.IsEmpty() {
		v := q.Pop().(Node)

		if v.Now == length-1 {
			r1 := v.Value + op[0]*numbers[v.Now+1]
			r2 := v.Value + op[1]*numbers[v.Now+1]

			if r1 == target {
				result++
			}
			if r2 == target {
				result++
			}
			continue
		}

		q.Push(Node{v.Now + 1, v.Value + op[0]*numbers[v.Now+1]})
		q.Push(Node{v.Now + 1, v.Value + op[1]*numbers[v.Now+1]})
	}

	return
}