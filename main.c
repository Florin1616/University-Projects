#include <stdio.h>
#include <stdbool.h>
void print_menu()
{	
	printf("1.Decompose a number in its prime factors\n");
	printf("2.Longest contiguous subsequence such that any consecutive elements contain the same digits.\n");
	printf("0.Exit\n");
}
void prime_factors_of_given_number(int number, int occurences_of_digits[])
{
	if (number % 2 == 0) 
	{
		while (number % 2 == 0)
		{
			occurences_of_digits[2]++;
			number = number / 2;
		}
		
	}
	for (int prime_divisor = 3; prime_divisor * prime_divisor <= number; prime_divisor += 2)
		if (number % prime_divisor == 0)
		{
			while (number % prime_divisor == 0)
			{
				occurences_of_digits[prime_divisor]++;
				number = number / prime_divisor;
			}
			
		}
	if (number != 1)
	{
		occurences_of_digits[number]++;
	}
}
void print_prime_factors(int number_of_occurences[], int number_to_be_decomposed)
{

	printf("%d = ", number_to_be_decomposed);
	bool check_if_two_appears_in_the_decomposing_of_number_in_prime_factors = false;
	if (number_of_occurences[2] != 0)
	{	
		check_if_two_appears_in_the_decomposing_of_number_in_prime_factors = true;
		printf("2^%d", number_of_occurences[2]);
	}
	int contor = 0;
	if (check_if_two_appears_in_the_decomposing_of_number_in_prime_factors == false)
		for (int prime_divisor = 3; prime_divisor < 100; prime_divisor += 2)
		{
			if (number_of_occurences[prime_divisor] != 0)
			{
				if (contor == 0)
				{
					contor++;
					printf("%d^%d", prime_divisor, number_of_occurences[prime_divisor]);
				}
				else
					printf(" * %d^%d", prime_divisor, number_of_occurences[prime_divisor]);
			}
		}
	else
		for (int prime_divisor = 3; prime_divisor < 100; prime_divisor += 2)
		{
			if (number_of_occurences[prime_divisor] != 0)
			{
				printf(" * %d^%d", prime_divisor, number_of_occurences[prime_divisor]);
			}
		}

	printf("\n");
}

int compare_if_two_numbers_have_the_exact_same_digits(int number1, int number2)
{
	int digits_that_appear_in_number1[10] = { 0 };
	int digits_that_appear_in_number2[10] = { 0 };
	while (number1 != 0)
	{
		digits_that_appear_in_number1[number1 % 10] = 1;
		number1 /= 10;
	}
	while (number2 != 0)
	{
		digits_that_appear_in_number2[number2 % 10] = 1;
		number2 /= 10;
	}
	for (int i = 0; i < 10; i++)
	{
		if (digits_that_appear_in_number1[i] != digits_that_appear_in_number2[i])
			return 0;
	}
	return 1;

}

void longest_subsequence_such_that_any_consecutive_elements_have_the_same_digits(int given_vector[], int length_of_vector, int *starting_position, int *ending_position)
{
	int max_length = 1;
	int current_length = 1;
	*starting_position = 0;
	*ending_position = 0;
	for (int index = 1; index < length_of_vector; index++)
	{
		if (compare_if_two_numbers_have_the_exact_same_digits(given_vector[index],given_vector[index-1]) == true)
		{
			current_length += 1;
		}
		else
		{
			current_length = 1;
		}
		if (current_length > max_length)
		{
			max_length = current_length;
			*starting_position = index - current_length + 1;
			*ending_position = index;
		} 
	}
}
void print_subsequence(int vector[], int start, int end)
{
	for (int index = start; index <= end; index++)
	{
		printf("%d ", vector[index]);
	}
	printf("\n");
}
int main() {

	int choice = 0;
	do {
		print_menu();
		printf("Enter your choice: ");
		scanf("%d", &choice);
		switch (choice)
		{
		case 0:
		{
			break;
		}
		case 1:
		{
			int occurences_of_digits[100] = { 0 };
			int number;
			printf("Enter your number: ");
			scanf("%d", &number);
			prime_factors_of_given_number(number, occurences_of_digits);
			print_prime_factors(occurences_of_digits, number);

			break;
		}
		case 2:
		{
			int length_of_vector, new_element, new_vector[100];
			printf("Enter the length of the vector: ");
			scanf("%d", &length_of_vector);
			for (int index = 0; index < length_of_vector; index++)
			{
				scanf("%d", &new_vector[index]);
			}
			int start, end;
			longest_subsequence_such_that_any_consecutive_elements_have_the_same_digits(new_vector, length_of_vector, &start, &end);
			print_subsequence(new_vector, start, end);
			break;
		}
		default:
		{
			printf("Invalid input!\n");
			break;
		}
		}
	} while (choice != 0);
	return 0;
}