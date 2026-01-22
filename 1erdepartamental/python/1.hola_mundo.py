# ============================================
# PROGRAMA: Hola Mundo con Programación Orientada a Objetos
# DESCRIPCIÓN: Ejemplo básico de una clase en Python
# ============================================


# Clase Principal
class Saludo:
    def __init__(self, nombre):
        # Aquí se guarda lo que le colocamos en el constructor para un saludo personalizado
        self.nombre = nombre

    def saludar(self):
        # Imprime saludo personalizado usando el nombre guardado en el constructor con F strings para encadenarla
        print(f"Hola Mundo, Mi nombre es {self.nombre}")


# ============================================
# FUNCIÓN PRINCIPAL
# ============================================
def main():
    # Solicita al usuario que ingrese su nombre
    nombre = input("Ingrese su nombre: ")
    saludo = Saludo(nombre)
    # Llama al método saludar
    saludo.saludar()


# ============================================
# BLOQUE DE EJECUCIÓN PRINCIPAL
# ============================================
# Este bloque solo se ejecuta si el archivo se ejecuta directamente
# No se ejecuta si el archivo es importado como módulo
if __name__ == "__main__":
    main()  # Llama a la función principal
