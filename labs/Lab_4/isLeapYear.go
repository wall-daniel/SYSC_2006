package main

import "fmt"

func main() {
	testIsLeapYear()
}

func testIsLeapYear() {
	var tests = []struct {
		year     uint
		expected bool
	}{
		{1900, false}, // 1900 is not a leap year
		{2000, true},  // 2000 is a leap year
		{2018, false}, // 2018 is not a leap year
		{2019, false}, // 2019 is not a leap year
		{2020, true},  // 2020 is a leap year
	}

	fmt.Println("Testing isLeapYear")
	passed := 0
	failed := 0
	for _, test := range tests {
		if result := isLeapYear(test.year); result != test.expected {
			fmt.Printf("isLeapYear(%v) returns %v, not %v\n", test.year, result, test.expected)
			failed += 1
		} else {
			passed += 1
		}
	}
	fmt.Printf("%d tests passed, %d tests failed\n", passed, failed)
}

/* Return true if year is a leap year; otherwise return false.
 * Parameter n > 1582.
 */
func isLeapYear(year uint) bool {
	if year % 400 == 0 {
		return true
	} else if year % 100 == 0 {
		return false
	} else if year % 4 == 0 {
		return true
	}
	return false
}
