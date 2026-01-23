"""
Programa: Recursividad
Demuestra algoritmos recursivos clásicos
"""
#Clase Principa
from core.algoritmos import AlgoritmosRecursivos

def main ():
    algo = AlgoritmosRecursivos()
    print(f"Factorial de 5: {algo.factorial(5)}")
    print(f"Fibonacci de 7: {algo.fibonacci(7)}")
    print(f"Suma hasta 10: {algo.suma_hasta(10)}")
    print(f"2^8: {algo.potencia(2, 8)}")
    
if __name__ == "__main__":
   main()