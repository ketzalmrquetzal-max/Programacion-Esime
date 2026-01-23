# Generador de fractales recursivos

#Clase FractalesRecursivos
class FractalesRecursivos:
    #Funcion para generar el triangulo de Sierpinski
    def sierpinski(self, nivel, tamano=16):
        #Caso base de la recursividad
        if nivel == 0:
            self._dibujar_triangulo(tamano)
            return
        #Muestra el nivel actual del fractral 
        print(f"Sierpinski nivel {nivel}:")
        self.sierpinski(nivel - 1, tamano // 2)
        print()
    # Función que genera el conjunto de Cantor
    def cantor(self, nivel, longitud=81):
        #Caso base de la recursividad
        if nivel == 0:
            print("#" * longitud)
            return
        self.cantor(nivel - 1, longitud // 3)
        print(" " * (longitud // 3), end="")
        self.cantor(nivel - 1, longitud // 3)
    # Función auxiliar para dibujar un triángulo
    def _dibujar_triangulo(self, tamano):
        for i in range(tamano):
            print(" " * (tamano - i - 1) + "*" * (2 * i + 1))
