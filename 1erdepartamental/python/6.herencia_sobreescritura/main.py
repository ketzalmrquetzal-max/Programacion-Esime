"""
Programa: Herencia con Sobreescritura
Demuestra polimorfismo: mismo método, diferentes implementaciones
"""

from core.calculadoras import CalculadoraDirecta, CalculadoraSucesiva

if __name__ == "__main__":
    print("=== CALCULADORA DIRECTA ===")
    cd = CalculadoraDirecta()
    print(f"5 * 3 = {cd.multiplicar(5, 3)}")
    print(f"2^8 = {cd.potencia(2, 8)}")
    print(f"20 / 4 = {cd.dividir(20, 4)}\n")

    print("=== CALCULADORA SUCESIVA ===")
    cs = CalculadoraSucesiva()
    print(f"5 * 3 = {cs.multiplicar(5, 3)}")
    print(f"2^8 = {cs.potencia(2, 8)}")
    print(f"20 / 4 = {cs.dividir(20, 4)}")
