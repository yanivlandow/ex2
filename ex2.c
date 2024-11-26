/******************
Name:yaniv landow
ID:213096035
Assignment: ex2
*******************/
#include <stdio.h>

int main() {
    // Main menu
    int key;  // Variable to store user's choice
    while (1) {
        // Displaying the menu
        printf("Choose an option:\n");
        printf("\t1. Happy Face\n");
        printf("\t2. Balanced Number\n");
        printf("\t3. Generous Number\n");
        printf("\t4. Circle Of Joy\n");
        printf("\t5. Happy Numbers\n");
        printf("\t6. Festival Of Laughter\n");
        printf("\t7. Exit\n");

        // Taking input for the menu option
        scanf("%d", &key);

        // Validate input choice
        if (key < 1 || key > 7) {
            printf("This option is not available, please try again.\n");
        }

        // If the user chooses to exit, break the loop
        if (key == 7) {
            printf("Thank you for your journey through Numeria!\n");
            break;
        }

        // Switch case to handle different menu options
        switch (key) {
            case 1: {
                // Case for "Happy Face"
                int faceSize, rememberSize;
                char eyes, nose, mouth;

                // Input symbols for face features
                printf("Enter symbols for the eyes, nose, and mouth:\n");
                scanf(" %c %c %c", &eyes, &nose, &mouth);
                scanf("%*[^\n]");  // Clear the input buffer
                scanf("%*c");

                // Input face size
                printf("Enter face size:\n");
                scanf("%d", &faceSize);

                // Validate if face size is positive and odd
                while (faceSize <= 0 || faceSize % 2 == 0) {
                    printf("The face's size must be an odd and positive number, please try again:\n");
                    scanf("%d", &faceSize);
                }

                rememberSize = faceSize;  // Store original face size

                // Print eyes and face outline
                printf("%c", eyes);
                while (faceSize > 0) {
                    printf(" ");
                    faceSize--;
                }
                printf("%c\n", eyes);

                faceSize = rememberSize;

                // Print nose
                for (int i = 0; i < (faceSize + 1) / 2; i++) {
                    printf(" ");
                }
                printf("%c", nose);
                faceSize = rememberSize;

                // Print mouth
                printf("\n\\");
                while (faceSize > 0) {
                    printf("%c", mouth);
                    faceSize--;
                }
                printf("/\n");
                break;
            }

            case 2: {
                // Case for "Balanced Number"
                int number, realNum;
                int sumRight = 0, count = 1, sumLeft = 0, totalSum = 0;
                const int TEN = 10;

                // Input number
                printf("Enter a number:\n");
                scanf("%*[^\n]");  // Clear the input buffer
                scanf("%*c");
                scanf(" %d", &number);

                // Ensure the number is positive
                while (number <= 0) {
                    printf("Only positive number is allowed, please try again:\n");
                    scanf(" %d", &number);
                }
                scanf("%*[^\n]");  // Clear the input buffer
                scanf("%*c");
                realNum = number;
                // Determine the number of digits
                while (number / TEN != 0) {
                    number = number / TEN;
                    count++;
                }
                number = realNum;

                // Check for even or odd number of digits
                if (count % 2 == 0) {
                    // For even digit numbers, split and check balance
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

                sumRight = 0; // Reset right sum for odd case

                // Handle odd digit numbers
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
                // Case for "Generous Number"
                int number ;
                int sum =0;
                const int TEN = 10;

                // Input number
                printf("Enter a number:\n");
                scanf(" %d", &number);

                // Ensure the number is positive
                while (number <= 0) {
                    printf("Only positive number is allowed, please try again:\n");
                    scanf(" %d", &number);
                }
                //i check if the number divided all the number until thr number and then sum all of it
                for (int i = 1; i < number; i++) {
                    if (number % i == 0) {
                        sum+=i;
                    }
                }
                //if thr sum is bigger it generous if not it not share
                if (sum > number) {
                    printf("This number is generous!\n");
                }else {
                    printf("This number does not share.\n");
                }
                break;
            }

            case 4: {
                // Case for "Circle Of Joy"
                int number, newNumber, rememberNumber;
                int reversedNumber = 0;
                const int TEN = 10;

                // Input number
                printf("Enter a number:\n");
                scanf("%d", &number);

                // Ensure the number is positive
                while (number <= 0) {
                    printf("Only positive number is allowed, please try again:\n");
                    scanf("%d", &number);
                }

                newNumber = number;

                // Check if number is prime
                int i = 2;
                for (; i < number; i++) {
                    if (number % i == 0) {
                        printf("The circle remains incomplete.\n");
                        break;
                    }
                }
                rememberNumber = number;
                if (i == number) {
                    // Reverse the number and check if it is prime
                    while (number != 0) {
                        newNumber = number % TEN;
                        number = number / TEN;
                        reversedNumber = reversedNumber * TEN + newNumber;
                    }
                    number = rememberNumber;
                    int z = 2;
                    for (; z < reversedNumber; z++) {
                        if (reversedNumber % z == 0) {
                            printf("The circle remains incomplete.\n");
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
                // Case for "Happy Numbers"
                int number, newNumber, temp;
                int loop = 1, power = 0;
                const int TEN = 10;

                // Input number
                printf("Enter a number:\n");
                scanf("%d", &number);

                // Ensure the number is positive
                while (number <= 0) {
                    printf("Only positive number is allowed, please try again:\n");
                    scanf(" %d", &number);
                }

                temp = loop;
                printf("Between 1 and %d only these numbers bring happiness:", number);

                // Loop through numbers and check happiness condition
                while (loop <= number) {
                    while (temp != 0) {
                        newNumber = temp % TEN;
                        power = power + (newNumber * newNumber);
                        temp = temp / TEN;
                    }

                    // If power reaches 1, it's a happy number
                    if (power == 1) {
                        printf(" %d", loop);
                        loop += 1;
                        temp = loop;
                        power = 0;
                    } else {
                        // If power reaches 4, it's not a happy number
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
                // Case for "Festival Of Laughter"
                int smile, cheer, maxNumber;
                int x;

                // Input smile and cheer numbers
                printf("Enter a smile and cheer number:\n");
                scanf("%*[^\n]");  // Clear the input buffer
                scanf("%*c");
                while (1) {
                    x = scanf("smile: %d, cheer: %d", &smile, &cheer);
                    if (x == 2 && cheer > 0 && smile > 0 && smile != cheer) {
                        break;
                    }
                    printf("Only 2 different positive numbers in the given format are allowed for the festival, please try again:\n");
                    scanf("%*[^\n]");  // Clear the input buffer
                    scanf("%*c");
                }

                // Input maximum number for the festival
                printf("Enter maximum number for the festival:\n");
                scanf(" %d", &maxNumber);
                if (maxNumber <= 0) {
                    printf("Only positive maximum number is allowed, please try again:\n");
                    scanf(" %d", &maxNumber);
                }

                // Print the festival messages
                for (int i = 1; i <= maxNumber; i++) {
                    if (i % smile != 0 && i % cheer != 0) {
                        printf("%d \n", i);
                    }
                    if (i % smile == 0 && i % cheer != 0) {
                        printf("Smile!\n");
                    }
                    if (i % smile != 0 && i % cheer == 0) {
                        printf("Cheer!\n");
                    }
                    if (i % smile == 0 && i % cheer == 0) {
                        printf("Festival!\n");
                    }
                }
                break;
            }

            case 7: {
                // Exit message
                printf("Thank you for your journey through Numeria!\n");
                break;
            }
        }
    }
    return 0;
}

