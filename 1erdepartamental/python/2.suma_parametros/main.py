"""
Programa: Suma con Parámetros
Demuestra parámetros por defecto y operator overloading
"""
#La clase principal 
from core.sumador import Sumador

#Funcion Principal
def main ():
    s1 = Sumador(10, 20)
    print(f"s1: {s1}")
    print(f"Suma: {s1.sumar()}\n")

    s2 = Sumador(5, 15)
    s3 = s1 + s2
    print(f"s1 + s2 = {s3}")

#Codigo que inicia toda la ejecucion
if __name__ == "__main__":
    main ()