import time

class Operadores:

    def __init__(self):
        self.__resultado = 0

    def sumar(self, a, b):
        self.__resultado = a + b
        return self.__resultado

    def restar(self, a, b):
        self.__resultado = a - b
        return self.__resultado

    def multiplicar(self, a, b):
        self.__resultado = a * b
        return self.__resultado

    def dividir(self, a, b):
        if b != 0:
            self.__resultado = a / b
            return self.__resultado
        else:
            return "Error: división entre cero"


class Menu(Operadores):

    def __init__(self):
        super().__init__()

    def menuprincipal(self):
        while True:
            time.sleep (2)
            print("\n--- MENÚ CALCULADORA ---")
            print("1. Sumar")
            print("2. Restar")
            print("3. Multiplicar")
            print("4. Dividir")
            print("5. Salir")

            opcion = input("Seleccione una opción: ")

            if opcion == "5":
                print("Saliendo...")
                break

            a = float(input("Ingrese el primer número: "))
            b = float(input("Ingrese el segundo número: "))

            if opcion == "1":
                print("Resultado:", self.sumar(a, b))
            elif opcion == "2":
                print("Resultado:", self.restar(a, b))
            elif opcion == "3":
                print("Resultado:", self.multiplicar(a, b))
            elif opcion == "4":
                print("Resultado:", self.dividir(a, b))
            else:
                print("Opción inválida")


class Calculadora(Menu):
    def __init__(self):
        super().__init__()


def main():
    calculadora_esime = Calculadora()
    calculadora_esime.menuprincipal()

if __name__ == "__main__":
    main()