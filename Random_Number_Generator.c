// This file is created for having random number of certain amount in a text file 
// random_number will hold the tatal number of numbers you want মোট কতগুলো সংখ্যা
// max_number select maximum number that can be present in your random numbers সংখ্যার মান কত পর্যন্ত
// This file is created with help of artificial inteligence 
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define random_number 100 // how many random number you want
#define max_range 10 // maximum range of your random number
// 0 to (max_range-1)

int main() {
    FILE *file = fopen("numbers.txt", "w");
    if (file == NULL) {
        perror("Ops!");
        return 1;
    }

    int total_elements = random_number; 
    srand(time(0));

    for (int i = 0; i < total_elements; i++) {
        fprintf(file, "%d ", rand() % max_range); // numbers will between (0 to max_range-1)
    }

    fclose(file);
    printf("%d numbers successfully written to 'numbers.txt'\n", random_number);
    return 0;
}