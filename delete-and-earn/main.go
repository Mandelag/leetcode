import "sort"


// nemu strategi baru,
// coba untuk setiap Num, kita calculate total Points nya, kemudian kurangi dengan score kiri kanan nya.
// jika hasilnya >= 0, kita keep number itu
func deleteAndEarn(nums []int) int {
	sort.Slice(nums, func(i, j int) bool {
		return nums[i] > nums[j]
	})

	bins, index := Histogram(nums)

	log.Println("FAZT", bins, index)
	e := &engine{
		exclusion: make(map[int]int),
		index:     index,
	}

	return e.Calculate(bins, 0, len(bins))
}

type Bin struct {
	Num    int
	Points int
}

func (b Bin) Score() int {
	return b.Num * b.Points
}

// Histogram calculate histogram of a sorted array
func Histogram(nums []int) ([]Bin, map[int]int) {
	bins := make([]Bin, len(nums))
	idx := make(map[int]int)
	if len(nums) == 0 {
		return bins, nil
	}

	j := 0
	for i := 0; i < len(nums); i++ {
		if bins[j].Num != nums[i] && i != 0 {
			j++
		}
		bins[j].Num = nums[i]
		bins[j].Points += 1
		idx[nums[i]] += nums[i]
	}

	return bins[:j+1], idx
}

type engine struct {
	exclusion map[int]int
	index     map[int]int
}

func (e *engine) isExcluded(val int) bool {
	return e.exclusion[val] > 0
}

func (e *engine) exclude(nums ...int) {
	for _, num := range nums {
		e.exclusion[num]++
	}
}

func (e *engine) unExclude(nums ...int) {
	for _, num := range nums {
		e.exclusion[num]--
	}
}

func (e *engine) Calculate(nums []Bin, start, end int) int {
	if start >= end || start >= len(nums) || end == 0 {
		return 0
	}
	if end-start == 1 {
		if !e.isExcluded(nums[start].Num) {
			return nums[start].Score()
		}
		return 0
	}

	max := 0
	for i := start; i < end; i++ {
		if e.isExcluded(nums[i].Num) {
			continue
		}

		currentMax := nums[i].Score()

		if currentMax-e.index[i-1]-e.index[i+1] < 0 {
			// don't bother calculate since it will decrease the cost ? greedyass
			continue
		}

		e.exclude(nums[i].Num-1, nums[i].Num+1)

		currentMax += e.Calculate(nums, start, i)
		currentMax += e.Calculate(nums, i+1, end)

		e.unExclude(nums[i].Num-1, nums[i].Num+1)

		if max < currentMax {
			max = currentMax
		}
	}

	return max
}

