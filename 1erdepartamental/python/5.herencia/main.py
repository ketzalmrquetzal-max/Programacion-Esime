"""
Programa: Herencia
Demuestra herencia con ABC y operaciones especializadas
"""

#Se importan las clases hijas desde el paquete core
from core.calculadoras import CalculadoraCientifica, CalculadoraFinanciera

if __name__ == "__main__":
    #Sección de la calculadora científica 
    print("=== CALCULADORA CIENTÍFICA ===")
    cient = CalculadoraCientifica()
    print(f"Raíz de 16: {cient.raiz_cuadrada(16)}")
    print(f"2^10: {cient.potencia(2, 10)}")
    print(f"Operación especial (raíz de 25): {cient.operacion_especial(25)}\n")
    #Sección de la calculadora financiera 
    print("=== CALCULADORA FINANCIERA ===")

    finan = CalculadoraFinanciera()

    print(f"Interés simple ($1000, 5%, 3 años): ${finan.interes_simple(1000, 0.05, 3)}")

    print(f"Descuento 20% sobre $500: ${finan.descuento(500, 20)}")

    print(f"Operación especial (15% sobre $100): ${finan.operacion_especial(100)}")
