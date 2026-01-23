"""
Programa: Herencia con Sobreescritura
Demuestra polimorfismo: mismo método, diferentes implementaciones
"""
#Clases a usar
from core.calculadoras import CalculadoraDirecta, CalculadoraSucesiva
#Funcion Princpal
def main ():
    print("=== CALCULADORA DIRECTA ===")
    cd = CalculadoraDirecta() #Creamos el objeto con los atributos por defecto
    print(f"5 * 3 = {cd.multiplicar(5, 3)}")
    print(f"2^8 = {cd.potencia(2, 8)}")
    print(f"20 / 4 = {cd.dividir(20, 4)}\n")

    print("=== CALCULADORA SUCESIVA ===")
    cs = CalculadoraSucesiva()#Creamos el objeto con los atributos por defecto
    print(f"5 * 3 = {cs.multiplicar(5, 3)}")
    print(f"2^8 = {cs.potencia(2, 8)}")
    print(f"20 / 4 = {cs.dividir(20, 4)}")

#Funcion que inicia todo el codigo
if __name__ == "__main__":
    main ()
