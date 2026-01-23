"""
Programa: Sobrecarga Simulada
Demuestra uso de *args para simular sobrecarga de métodos
"""
#Archivo con la Clase
from core.calculadora import Calculadora

#Funcion Principal
def main ():
    calc = Calculadora()

    print(f"Suma de 2 números: {calc.sumar(10, 20)}")
    print(f"Suma de 3 números: {calc.sumar(10, 20, 30)}")
    print(f"Suma de 5 números: {calc.sumar(1, 2, 3, 4, 5)}")

    print(f"\nMultiplicación de 3: {calc.multiplicar(2, 3, 4)}")

#Funcion que inicia todo el codigo
if __name__ == "__main__":
    main()