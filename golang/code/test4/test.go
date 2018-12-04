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
	M, _ := strconv.Atoi(strArray[0])
	N, _ := strconv.Atoi(strArray[1])
	K, _ := strconv.Atoi(strArray[2])

	sijisya := make([]int, M+1)
	sijisya[M] = N // 誰も支持しないに票を入れる

	for i := 0; i < K; i++ {
		scanner.Scan()
		str := scanner.Text()
		index, _ := strconv.Atoi(str)

		acc := sijisya[index-1]
		for j, n := range sijisya {
			if index-1 != j && n > 0 {
				acc++
				sijisya[j] = n - 1
			}
		}
		sijisya[index-1] = acc
	}

	max := 0
	results := make([]int, 0)
	for j, n := range sijisya[0 : len(sijisya)-1] {
		if max <= n {
			max = n
			if len(results) > 0 && sijisya[results[0]] < max {
				results = make([]int, 0)
			}
			results = append(results, j)
		}
	}

	for _, v := range results {
		fmt.Println(v + 1)
	}
}
