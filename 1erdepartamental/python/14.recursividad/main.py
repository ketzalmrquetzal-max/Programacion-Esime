"""
Programa: Recursividad
Demuestra algoritmos recursivos clásicos
"""

from core.algoritmos import AlgoritmosRecursivos

if __name__ == "__main__":
    algo = AlgoritmosRecursivos()

    print(f"Factorial de 5: {algo.factorial(5)}")
    print(f"Fibonacci de 7: {algo.fibonacci(7)}")
    print(f"Suma hasta 10: {algo.suma_hasta(10)}")
    print(f"2^8: {algo.potencia(2, 8)}")
