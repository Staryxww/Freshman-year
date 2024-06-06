package main

import (
	"fmt"
)

func judgemonth(month, year int) int {
	daymax := 0
	if ((year%4 == 0 && year%100 != 0) || (year%400 == 0)) && month == 2 {
		daymax = 29
	} else if month == 2 {
		daymax = 28
	} else if (month%2 == 0 && month <= 7) || (month%2 != 0 && month >= 8) {
		daymax = 30
	} else {
		daymax = 31
	}
	return daymax
}

func output(week, month, day, century, yearOfCent int, year int) {
	if month == 1 || month == 2 {
		month += 12
		year--
		century = year / 100
		yearOfCent = year % 100
		fmt.Printf("MONTH %d\nSUN MON WED TUE THU FRI SAT \n", month-12)
		week = (yearOfCent + yearOfCent/4 + century/4 - 2*century + 26*(month+1)/10) % 7
		if week < 0 {
			week += 7
		} else if week > 7 {
			week = 7
		}
		for i := 0; i < week; i++ {
			fmt.Printf("    ")
		}
		year++
		month -= 12
	} else {
		fmt.Printf("MONTH %d\nSUN MON WED TUE THU FRI SAT \n", month)
		century = year / 100
		yearOfCent = year % 100
		week = (yearOfCent + yearOfCent/4 + century/4 - 2*century + 26*(month+1)/10) % 7
		if week < 0 {
			week += 7
		} else if week > 7 {
			week = 7
		}
		for i := 0; i < week; i++ {
			fmt.Printf("    ")
		}
	}

	for day = 1; day <= judgemonth(month, year); day++ {
		fmt.Printf("%3d ", day)
		if week++; week > 6 {
			fmt.Println()
			week = 0
		}
	}
}

func main() {
	var year int
	fmt.Print("Please enter the year: ")
	fmt.Scan(&year)

	for month := 1; month <= 12; month++ {
		output(0, month, 0, 0, 0, year)
		fmt.Println()
	}
}
