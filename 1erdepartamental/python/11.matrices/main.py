"""
Programa: Matrices
Demuestra operaciones matriciales con operator overloading
"""
#Importe de clases 
from core.matriz import Matriz
#Punto de entrada 
if __name__ == "__main__":
    m1 = Matriz(2, 2)#Se crea una matriz de 2x2
    #Se asignan valores a la matriz
    m1.set(0, 0, 1)
    m1.set(0, 1, 2)
    m1.set(1, 0, 3)
    m1.set(1, 1, 4)
    #Imprime la matriz original
    print("Matriz original:")
    print(m1)
    #Multiplicada por un escalar
    print("\nMultiplicación escalar (x2):")
    print(m1 * 2)
    #Multiplicación entre matrices 
    print("\nMultiplicación matricial:")
    print(m1 * m1)
