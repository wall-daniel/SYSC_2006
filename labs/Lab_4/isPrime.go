package main

import "fmt"
import "math"

func main() {
	testIsPrime()
}

func testIsPrime() {
	var tests = []struct {
		num      int
		expected bool
	}{
		{1, false}, // 1 is not prime
		{2, true},  //2 is prime
		{3, true},
		{4, false},
		{5, true},
		{6, false},
		{7, true},
		{8, false},
		{9, false},
		{10, false},
		{11, true},
		{12, false},
		{13, true},
		{14, false},
		{15, false},
		{16, false},
		{17, true},
		{18, false},
		{19, true},
		{20, false},
	}

	fmt.Println("Testing isPrime")
	passed := 0
	failed := 0
	for _, test := range tests {
		if result := isPrime(test.num); result != test.expected {
			fmt.Printf("isPrime(%v) returns %v, not %v\n", test.num, result, test.expected)
			failed += 1
		} else {
			passed += 1
		}
	}
	fmt.Printf("%d tests passed, %d tests failed\n", passed, failed)
}

/* Return true if n is prime; otherwise return false. Parameter n >= 1. */
func isPrime(n int) bool {
	if n == 1 {
		return false
	} 
	if n == 2 {
		return true
	}
	
	if n % 2 == 0 {
		return false
	}

	var sqrt int = int(math.Sqrt(float64(n)))

	for i := 3; i <= sqrt; i += 2 {
		if n % i == 0 {
			return false
		}
	}

	return true
}
