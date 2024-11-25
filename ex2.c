/******************
Name:yaniv landow
ID:213096035
Assignment: ex2
*******************/

#include <stdio.h>
int main() {
    // Main menu
    int key;
    while (1) {
        printf("Choose an option:\n");
        printf("\t1. Happy Face\n");
        printf("\t2. Balanced Number\n");
        printf("\t3. Generous Number\n");
        printf("\t4. Circle Of Joy\n");
        printf("\t5. Happy Numbers\n");
        printf("\t6. Festival Of Laughter\n");
        printf("\t7. Exit\n");
        scanf("%d", &key);
        if (key < 1 || key > 7) {
            printf("This option is not available, please try again.\n");
        }

        switch (key) {
            case 1: {
                int faceSize, rememberSize;
                char eyes, nose, mouth;
                printf("Enter symbols for the eyes, nose, and mouth:\n");
                scanf(" %c %c %c", &eyes, &nose, &mouth);
                printf("Enter face size:\n");
                scanf("%d", &faceSize);
                // Check if the number is positive and odd
                while (faceSize <= 0 || faceSize % 2 == 0) {
                    printf("The face's size must be an odd and positive number, please try again:\n");
                    scanf("%d", &faceSize);
                }
                rememberSize = faceSize;
                printf("%c", eyes);
                while (faceSize > 0) {
                    printf(" ");
                    faceSize--;
                }
                printf("%c\n", eyes);

                faceSize = rememberSize;
                for (int i = 0; i < (faceSize + 1) / 2; i++) {
                    printf(" ");
                }
                printf("%c", nose);
                faceSize = rememberSize;
                printf("\n\\");
                while (faceSize > 0) {
                    printf("%c", mouth);
                    faceSize--;
                }
                printf("/\n");
                break;
            }
            case 2: {
                int number, realNum;
                int sumRight = 0;
                int count = 1;
                int sumLeft = 0;
                int totalSum = 0;
                const int TEN = 10;
                printf("Enter a number:\n");
                scanf(" %d", &number);
                realNum = number;
                while (number / TEN != 0) {
                    number = number / TEN;
                    count++;
                }
                number = realNum;

                if (count % 2 == 0) {
                    for (int i = count; i > count / 2; i--) {
                        sumRight = sumRight + number % TEN;
                        number = number / TEN;
                    }
                    number = realNum;
                    for (int i = 0; i < count; i++) {
                        totalSum = totalSum + number % TEN;
                        number = number / TEN;
                    }
                    sumLeft = totalSum - sumRight;
                    if (sumRight == sumLeft) {
                        printf("This number is balanced and brings harmony!\n");
                    } else {
                        printf("This number isn't balanced and destroys harmony.\n");
                    }
                }
                sumRight = 0;
                if (count % 2 != 0) {
                    for (int i = count; i > (count + 1) / 2; i--) {
                        sumRight = sumRight + number % TEN;
                        number = number / TEN;
                    }
                    number = number / TEN;
                    for (int i = 0; i < count / 2; i++) {
                        sumLeft = sumLeft + number % TEN;
                        number = number / TEN;
                    }
                    if (sumRight == sumLeft) {
                        printf("This number is balanced and brings harmony!\n");
                    } else {
                        printf("This number isn't balanced and destroys harmony.\n");
                    }
                }
                break;
            }
            case 3: {
                int number = 0;
                int count = 1;
                int rightSum, realNumber, leftSum;
                int totalSum = 0;
                const int TEN = 10;
                printf("Enter a number:\n");
                scanf(" %d", &number);
                realNumber = number;
                rightSum = realNumber % TEN;
                while (number < 0) {
                    printf("Only positive number is allowed, please try again:\n");
                    scanf(" %d", &number);
                }
                if (number / TEN == 0) {
                    printf("This number does not share.\n");
                    break;
                }
                while (number / TEN != 0) {
                    number = number / TEN;
                    count++;
                }
                for (int i = 0; i < count; i++) {
                    totalSum = totalSum + realNumber % TEN;
                    realNumber = realNumber / TEN;
                }
                leftSum = totalSum - rightSum;
                if (leftSum > rightSum) {
                    printf("This number does not share.\n");
                } else {
                    printf("This number is generous!\n");
                }
                break;
            }
            case 4: {
                int number, newNumber, rememberNumber;
                int reversedNumber = 0;
                const int TEN = 10;
                printf("Enter a number:\n");
                scanf("%d", &number);
                while (number < 0) {
                    printf("Only positive number is allowed, please try again:\n");
                    scanf("%d", &number);
                }
                newNumber = number;
                int i = 2;
                for (; i < number; i++) {
                    if (number % i == 0) {
                        printf("The circle remains incomplete\n");
                        break;
                    }
                }
                rememberNumber = number;
                if (i == number) {
                    while (number != 0) {
                        newNumber = number % TEN;
                        number = number / TEN;
                        reversedNumber = reversedNumber * TEN + newNumber;
                    }
                    number = rememberNumber;
                    int z = 2;
                    for (; z < reversedNumber; z++) {
                        if (reversedNumber % z == 0) {
                            printf("The circle remains incomplete\n");
                            break;
                        }
                    }
                    if (i == number && z == reversedNumber) {
                        printf("This number completes the circle of joy!\n");
                    }
                }
                break;
            }
            case 5: {
                int number, newNumber, temp;
                int loop = 1;
                int power = 0;
                const int TEN = 10;
                printf("Enter a number:\n");
                scanf(" %d", &number);
                while (number < 0) {
                    printf("Only positive number is allowed, please try again:\n");
                    scanf(" %d", &number);
                }
                temp = loop;
                printf("Between 1 and %d only these numbers bring happiness:", number);
                while (loop <= number) {
                    while (temp != 0) {
                        newNumber = temp % TEN;
                        power = power + (newNumber * newNumber);
                        temp = temp / TEN;
                    }
                    if (power == 1) {
                        printf(" %d", loop);
                        loop += 1;
                        temp = loop;
                        power = 0;
                    } else {
                        if (power == 4) {
                            loop += 1;
                            temp = loop;
                            power = 0;
                        } else {
                            temp = power;
                            power = 0;
                        }
                    }
                }
                printf("\n");
                break;
            }
            case 6: {
                int smile, cheer, maxNumber;
                int x;
                printf("Enter a smile and cheer number:\n");
                scanf("%*[^\n]");
                scanf("%*c");
                while (1) {
                    x = scanf("smile: %d, cheer: %d", &smile, &cheer);
                    if (x == 2 && cheer > 0 && smile > 0 && smile != cheer) {
                        break;
                    }
                    printf("Only 2 different positive numbers in the given format are allowed for the festival, please try again:");
                    scanf("%*[^\n]");
                    scanf("%*c");
                }
                printf("Enter maximum number for the festival:\n");
                scanf(" %d", &maxNumber);
                if (maxNumber < 0) {
                    printf("Only positive maximum number is allowed, please try again:\n");
                    scanf(" %d", &maxNumber);
                }
                for (int i = 1; i <= maxNumber; i++) {
                    if (i % smile != 0 && i % cheer != 0) {
                        printf("%d\n", i);
                    }
                    if (i % smile == 0 && i % cheer != 0) {
                        printf("Smile\n!");
                    }
                    if (i % smile != 0 && i % cheer == 0) {
                        printf("Cheer\n!");
                    }
                    if (i % smile == 0 && i % cheer == 0) {
                        printf("Festival!\n");
                    }
                }
                break;
            }
            case 7: {
                printf("Thank you for your journey through Numeria!\n");
                break;
            }
        }
    }
    return 0;
}

	// Case 1: Draw Happy Face with given symbols for eyes, nose and mouse
	/* Example:
	* n = 3:
	* 0   0
	*   o
	* \___/
	*/


	// Case 2: determine whether the sum of all digits to the left of the middle digit(s)
	// and the sum of all digits to the right of the middle digit(s) are equal
	/* Examples:
	Balanced: 1533, 450810, 99
	Not blanced: 1552, 34
	Please notice: the number has to be bigger than 0.
	*/

	// Case 3: determine whether the sum of the proper divisors (od an integer) is greater than the number itself
	/* Examples:
	Abudant: 12, 20, 24
	Not Abudant: 3, 7, 10
	Please notice: the number has to be bigger than 0.
	*/

	// Case 4: determine wether a number is a prime.
	/* Examples:
	This one brings joy: 3, 5, 11
	This one does not bring joy: 15, 8, 99
	Please notice: the number has to be bigger than 0.
	*/


	// Happy numbers: Print all the happy numbers between 1 to the given number.
	// Happy number is a number which eventually reaches 1 when replaced by the sum of the square of each digit
	/* Examples:
	Happy :) : 7, 10
	Not Happy :( : 5, 9
	Please notice: the number has to be bigger than 0.
	*/

	// Festival of Laughter: Prints all the numbers between 1 the given number:
	// and replace with "Smile!" every number that divided by the given smile number
	// and replace with "Cheer!" every number that divided by the given cheer number
	// and replace with "Festival!" every number that divided by both of them
	/* Example:
	6, smile: 2, cheer: 3 : 1, Smile!, Cheer!, Smile!, 5, Festival!
	*/


