package main

import "fmt"
import "math"

func main() {
	testDiameter()
	testCopperWireResistance()
}

func testDiameter() {
	var tests = []struct {
		gauge    int
		expected float64
	}{
		{1, 7.3481},  // AWG 1 wire is 7.3481 mm in diameter
		{12, 2.0525}, // AWG 12 wire is 2.0525 mm in diameter
		{40, 0.0799}, //AWG 40 wire is 0.0799 mm in diameter
	}

	fmt.Println("Testing diameter")
	passed := 0
	failed := 0
	for _, test := range tests {
		if result := diameter(test.gauge); math.Abs(result-test.expected) > 0.001 {
			fmt.Printf("diameter(%v) returns %v, not %v\n", test.gauge, result, test.expected)
			failed += 1
		} else {
			passed += 1
		}
	}
	fmt.Printf("%d tests passed, %d tests failed\n", passed, failed)
}

func testCopperWireResistance() {
	var tests = []struct {
		length   float64
		gauge    int
		expected float64
	}{
		{10.0, 17, 0.16}, // 10 m of AWG 17 wire has resistance of 0.16 ohms
		{10.0, 24, 0.83}, // 10 m of AWG 24 wire has resistance of 0.16 ohms
	}

	fmt.Println("Testing copperWireResistance")
	passed := 0
	failed := 0
	for _, test := range tests {
		if result := copperWireResistance(test.length, test.gauge); math.Abs(result-test.expected) > 0.01 {
			fmt.Printf("copperWireResistance(%v, %v) returns %v, not %v\n", test.length, test.gauge, result, test.expected)
			failed += 1
		} else {
			passed += 1
		}
	}
	fmt.Printf("%d tests passed, %d tests failed\n", passed, failed)
}

/* Return the diameter, in mm, of an AWG (American Wire Gauge) n wire, 1 <= n <= 40. */
func diameter(wireGauge int) float64 {
	return 0.127 * math.Pow(92, (36 - float64(wireGauge)) / 39)
}

/* Return the resistance of a copper wire with the specified length (in m)
 * and gauge.
 */
func copperWireResistance(length float64, wireGauge int) float64 {
	return 4 * 1.7 * math.Pow10(-8) * length / (math.Pi * math.Pow(diameter(wireGauge) / 1000, 2))
}
