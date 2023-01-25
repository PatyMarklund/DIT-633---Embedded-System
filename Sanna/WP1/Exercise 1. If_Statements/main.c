# include <stdio.h>
//Write  a  program  that  reads  in  an  integer  number  between  1  and  5  from  the  keyboard  and  prints  out  one  of 
//existing five sentences on the console depending on what number was entered.You can invent the sentences
// as you want, but each sentence should be unique.
//The program continues to ask for a new number and exits if number isn ́t in the interval 1 to 5


int main(void) {

	//declare variables
	int number = 0;

	//repeat the statement until the expression becomes false
	do {

		printf("Enter a number between 1-5.");

		// saves the input from the console
		scanf_s("%d", &number);

		// checks if the input number matches any of the cases 1-5 and prints out accordingly to that number choosen
		switch (number)
		{
		case 1:                     // if the number chosen is 1, execute case 1 etc.
			printf("Hello\n");
			break;					// breaks the flow and goes back to the do statement at the top
		case 2:
			printf("Hej\n");
			break;
		case 3:
			printf("Ciao\n");
			break;
		case 4:
			printf("Hola\n");
			break;
		case 5:
			printf("Oi\n");
			break;
		}

	//if the number entered is not 1-5, the loop will exit 
	} while (number >= 1 && number <= 5);

	//if the number does not match number 1-5 this will be printed.
	printf("The number you have typed is not 1-5. You will now exit the program.");

	// exit the method
	return 0;

}