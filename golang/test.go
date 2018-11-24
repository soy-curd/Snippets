package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

func main() {

	// 標準入力
	scanner := bufio.NewScanner(os.Stdin)

	abc := []string{"A", "B", "C", "D", "E", "F", "G", "H", "I", "J"}

	for scanner.Scan() {
		strArray := strings.Fields(scanner.Text())
		num := 0
		i := 0
		for _, str := range strArray {
			input, _ := strconv.Atoi(str)
			num = num + input
			for i < num {
				fmt.Print(abc[i])
				i++
			}
			fmt.Println()
		}
	}
}
