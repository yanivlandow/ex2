/******************
Name:yaniv landow
ID:213096035
Assignment: ex2
*******************/

#include <stdio.h>

int main() {
	//maim menu
	char eyes,nose,mouth;
	int faceSize,rememberSize,key;
	while (1) {
		printf("Choose an option:\n");
		printf("\t1. Happy Face\n");
		printf("\t2. Balanced Number\n");
		printf("\t3. Generous Number\n");
		printf("\t4. Circle Of Joy\n");
		printf("\t5. Happy Numbers\n");
		printf("\t6. Festival Of Laughter\n");
		printf("\t7. Exit\n");
		scanf("%d",&key);
		if (key>=1 && key<=7) {
			break;
		}
		else {printf("This option is not available, please try again.\n");
		}
	}
	switch (key) {
		case 1: {
			printf("Enter symbols for the eyes, nose, and mouth:\n");
			scanf(" %c" " %c" " %c" ,&eyes , &nose, &mouth);
			printf("Enter face size:\n");
			scanf("%d",&faceSize);
			//i checked if the number is positive or even if its not i request to bring me a new number until its positive and odd
			while(faceSize>0 && faceSize%2==0) {
				printf("The face's size must be an odd and positive number, please try again:\n");
				scanf("%d", &faceSize);

			}
			rememberSize=faceSize;
			printf("%c",eyes);
			//i want to make space until i arrive to selected index
			while(faceSize>0) {
				printf(" ");
				faceSize--;
			}
			printf("%c\n",eyes);
			//finish eyes starting nose
			faceSize=rememberSize;
			for(int i=0;i<(faceSize+1)/2;i++) {
				printf(" ");
			}
			printf("%c",nose);
			faceSize=rememberSize;
			printf("\n\\");
			while(faceSize>0) {
				printf("%c",mouth);
				faceSize--;
			}
			printf("/");
			break;
		}
		case 2: {
			int number,realNum;
			int sumRight = 0;
			int count = 1;
			int sumLeft = 0 ;
			int totalSum = 0;
			printf("Enter a number:\n");
			scanf(" %d",&number);
			realNum = number;
			// i check how many index the number has
			while(number/10 !=0) {
				number=number/10 ;
				count++;
			}
			number = realNum;
			//there are 2 option one even and one odd here i check what happenes when its even
			if(count%2 ==0) {
				//here i sum all the number in the right side
				for( int i = count; i > count/2; i-- ) {
					sumRight=sumRight+number%10;
					number = number/10;
				}
				number =realNum;
				//here i check the sum of all the number
				for( int i = 0; i <count; i++ ) {
					totalSum=totalSum+number%10;
					number = number/10;

				}
				sumLeft=totalSum-sumRight;
				if (sumRight == sumLeft) {
					printf("This number is balanced and brings harmony!\n");
				}else {
					printf("This number isn't balanced and destroys harmony.\n");
				}
			}
			sumRight = 0;
			if (count%2 !=0) {
				for( int i = count; i > (count+1)/2; i-- ) {
					sumRight=sumRight+number%10;
					number = number/10;
				}
				number = number/10;
				for( int i =0; i<count/2;i++) {
					sumLeft=sumLeft+number%10;
					number = number/10;
				}
				if (sumRight == sumLeft) {
					printf("This number is balanced and brings harmony!\n");
				}else {
					printf("This number isn't balanced and destroys harmony.\n");
				}
				break;
			}
		}
		case 3:{
			int number = 0;
			int count = 1;
			int rightSum,realNumber,leftSum;
			int totalSum = 0;
			printf("Enter a number:\n");
			scanf(" %d",&number);
			realNumber = number;
			rightSum=realNumber%10;
			while(number<0) {
				printf("Only positive number is allowed, please try again:\n");
				scanf(" %d",&number);
			}
				if(number/10 ==0) {
					printf("This number does not share.\n");
					break;
				}
				while(number/10 !=0) {
					number=number/10 ;
					count++;
				}
				for( int i =0; i<count; i++ ) {
					totalSum=totalSum+realNumber%10;
					realNumber = realNumber/10;
				}
				leftSum=totalSum-rightSum;
				if (leftSum > rightSum) {
					printf("This number does not share.\n");
				}else {printf("This number is generous!\n");
				}
			}
			case 4: {
			int number,newNumber,newCount;
			int reversedNumber  = 0;
			int count = 1;
			printf("Enter a number:\n");
			scanf(" %d",&number);
			newNumber = number;
			while(number<0) {
				printf("Only positive number is allowed, please try again:\n");
				scanf(" %d",&number);
			} int i=2;
			for(; i<number; i++) {
			if(number%i == 0) {
			printf("The circle remains incomplete");
			break;
			}
			}
			while(number/10 !=0) {
				number=number/10 ;
				count++;
			}
			number =newNumber;
			newCount=count;
			printf("%d\n",newNumber);
			printf("%d\n",newCount);
			printf("%d\n",number);
			printf("%d\n",reversedNumber);
			for (int k =1; k<count; k++) {
			newNumber=number%10;
			printf("%d\n",newNumber);
			reversedNumber=reversedNumber+newNumber*(10^(2-1));
			newCount=newCount-1;
			number=number/10;
			}
			printf("%d\n",reversedNumber);
			int z=2;

			for(; z<reversedNumber; z++) {
				if(reversedNumber%i == 0) {
					printf("The circle remains incomplete");
					break;
				}
				}
			if(i==number && z==reversedNumber)
				printf("This number completes the circle of joy!\n");



		break;
		}

			case 5:
			case 6:
			case 7:printf("Thank you for your journey through Numeria! ");
			break;
			default: printf("This option is not available, please try again.");

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
	return 0;
}
