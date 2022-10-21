import math


def main():
    while True:
        # loop para garantir que o usuário coloque um número
        try:
            creditnumber = int(input("Enter credit card number: "))
            # garantir que é maior que tem mais que 13 e menos que 17 dígitos
            a = 999999999999
            b = 10000000000000000
            if creditnumber > a and creditnumber < b:
                break
            else:
                print('INVALID')
                break
        # se não colocar um número
        except ValueError:
            print('You entered a non integer value, try again.')
            continue
    digits = creditnumber
    card = creditnumber
    startingDigits = creditnumber
    # how many digits does the card have?
    digit = 1
    while (digits > 9):
        digits = digits / 10
        digit = digit + 1
    # The Luhn algorithm works?
    luhn = 0
    while (card > 0):
        last_digit = int(repr(card)[-1])
        luhn = luhn + last_digit
        card = math.trunc(card / 10)
        last_digit = int(repr(card)[-1])
        last_digit = last_digit * 2
        if last_digit > 9:
            last_digit = 1 + last_digit % 10
        luhn = luhn + last_digit
        card = math.trunc(card / 10)
    # Define Brand
    # Get 2 first digits
    while (startingDigits > 99):
        startingDigits = startingDigits / 10
    # Truncation to remove decimals
    startingDigits = math.trunc(startingDigits)
    if luhn % 10 != 0:
        print("INVALID")
    elif digit == 15 and (startingDigits == 34 or startingDigits == 37):
        print("AMEX")
    elif digit == 16 and (startingDigits > 50 and startingDigits < 56):
        print("MASTERCARD")
    elif (digit == 13 or digit == 16) and math.trunc(startingDigits / 10) == 4:
        print("VISA")


main()