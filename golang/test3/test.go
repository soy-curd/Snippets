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
	scanner.Scan()
	strArray := strings.Fields(scanner.Text())
	scanner.Scan()
	str := scanner.Text()
	myNum, _ := strconv.Atoi(str)

	for i, _str := range strArray {
		input, _ := strconv.Atoi(_str)
		if input > myNum {
			fmt.Println(i + 1)
			break
		}

		if i == len(strArray)-1 {
			fmt.Println(i + 2)
		}
	}
}
