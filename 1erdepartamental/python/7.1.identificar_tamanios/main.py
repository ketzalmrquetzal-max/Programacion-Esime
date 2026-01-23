"""
Programa: Identificar Tamaños
Demuestra uso de sys.getsizeof() para analizar memoria
"""
#Importe de las clases 
from core.analizador import AnalizadorTamanios, Persona
#Punto de Entrada
if __name__ == "__main__":
    analizador = AnalizadorTamanios()
    analizador.analizar_tipos_basicos()
    analizador.analizar_strings()
    
    #Objeto
    p = Persona("Hugo", 19)
    analizador.analizar_objeto(p)
