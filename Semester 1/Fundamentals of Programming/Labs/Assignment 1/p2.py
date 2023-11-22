# Solve the problem from the second set here
# The numbers n1 and n2 have the property P if their writing in base 10 uses the
# same digits (e.g. 2113 and 323121). Determine whether two given natural numbers have property P.

def digits_used_in_given_number(given_number):
    list_of_digits = []
    while given_number != 0:
        digit = given_number % 10
        if digit not in list_of_digits:
            list_of_digits.append(digit)
        given_number //= 10
    return list_of_digits


def check_if_the_writing_of_two_numbers_in_base_ten_uses_the_same_digits(list1, list2):
    if sorted(list1) == sorted(list2):
        return True
    else:
        return False


def main():
    first_number = int(input("Enter the first number: "))
    second_number = int(input("Enter the second number: "))
    digits_in_the_first_number = digits_used_in_given_number(first_number)
    digits__in_the_second_number = digits_used_in_given_number(second_number)

    if check_if_the_writing_of_two_numbers_in_base_ten_uses_the_same_digits(digits__in_the_second_number, digits_in_the_first_number) is True:
        print("The numbers that you have entered have the P property!")
    else:
        print("The numbers that you have entered do not have the P property!")

    pass


if __name__ == "__main__":
    main()
