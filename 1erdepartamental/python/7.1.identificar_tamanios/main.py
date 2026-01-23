"""
Programa: Identificar Tamaños
Demuestra uso de sys.getsizeof() para analizar memoria
"""

from core.analizador import AnalizadorTamanios, Persona

if __name__ == "__main__":
    analizador = AnalizadorTamanios()
    analizador.analizar_tipos_basicos()
    analizador.analizar_strings()

    p = Persona("Hugo", 19)
    analizador.analizar_objeto(p)
