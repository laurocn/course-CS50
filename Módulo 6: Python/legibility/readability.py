import math


def main():
    while True:
        # loop para garantir que o usuário coloque um texto
        try:
            text = input("Enter text: ")
            break
        # se não colocar um texto
        except ValueError:
            print('Invalid input.')
            continue
    # índice Coleman-Liau = 0,0588 * L (número médio de letras por 100 palavras) - 0,296 * S (número médio de sentenças por 100 palavras) - 15,8
    palavras = len(text.split())
    sentencas = text.count(".") + text.count("!") + text.count("?")
    letras = 0
    for a in text:
        if a.isalpha():
            letras += 1
    letrasm = (letras * 100 / palavras)
    sentencasm = (sentencas * 100 / palavras)
    grade = round((0.0588 * letrasm) - (0.296 * sentencasm) - 15.8)
    if grade < 1:
        print("Before Grade 1")
    elif grade >= 16:
        print("Grade 16+")
    else:
        print(f"Grade {grade}")
    return 0


main()