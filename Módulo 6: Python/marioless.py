# do what you gotta do
def main():
    alt = height()
    pyramid(alt)


def height():
    while True:
        # loop para garantir que o usuário coloque um número
        try:
            height = int(input("Height: "))
            # se colocar um número, verifica se é entre 1 e 8
            if height > 0 and height <= 8:
                break
        # se não colocar um número
        except ValueError:
            print('You entered a non integer value, try again.')
            continue
        # retorna a altura
    return height

# pyramid pega a altura
def pyramid(alt):
    i = 0
    # loop
    while i < alt:
        # printa espaço da pirâmide menos o loop (i)
        print(' ' * (alt - i - 1), end="")
        # printa o loop
        print("#" + "#" * i)
        # soma o loop
        i += 1


main()