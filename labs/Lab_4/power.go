package main

import "fmt"

func main() {
	testPower()
}

func testPower() {
	var tests = []struct {
		base     int
		exponent int
		expected int
	}{
		{2, 0, 1}, // Test 2 ** 0 == 1
		{2, 1, 2}, // Test 2 ** 1 == 2
		{2, 2, 4},
		{-3, 0, 1},
		{-3, 1, -3},
		{-3, 2, 9},
	}

	fmt.Println("Testing power")
	passed := 0
	failed := 0
	for _, test := range tests {
		if result := power(test.base, test.exponent); result != test.expected {
			fmt.Printf("power(%v, %v) => %v, not %v\n", test.base, test.exponent, result, test.expected)
			failed += 1
		} else {
			passed += 1
		}
	}
	fmt.Printf("%d tests passed, %d tests failed\n", passed, failed)
}

/* Return base raised to the power n, n >= 0 */
func power(base, n int) int {
	pow := 1
	for ; n > 0; n -= 1 {
		pow *= base
	}
	return pow
}
