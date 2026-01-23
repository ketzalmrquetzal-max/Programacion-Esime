"""
Programa: Calculadora Básica
Demuestra operaciones matemáticas con manejo de errores
"""

from core.calculadora import Calculadora

if __name__ == "__main__":
    calc = Calculadora()

    print(f"10 + 5 = {calc.sumar(10, 5)}")
    print(f"10 - 5 = {calc.restar(10, 5)}")
    print(f"10 * 5 = {calc.multiplicar(10, 5)}")
    print(f"10 / 5 = {calc.dividir(10, 5)}")

    try:
        calc.dividir(10, 0)
    except ValueError as e:
        print(f"Error: {e}")
