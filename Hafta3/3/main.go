
package main

import "fmt"

func asalMi(sayi int) bool {
	for i:=2; i<sayi; i++ {
		if sayi % i == 0 {
			return false
		}
	}
	return true
}

func main() {
	sira := 0
	sayi := 2
	for {
		if asalMi(sayi) {
			sira++
			if sira==100 {
				break
			}
		}
		sayi++
	}

	fmt.Println("sayısı 100. asaldır", sayi)
}