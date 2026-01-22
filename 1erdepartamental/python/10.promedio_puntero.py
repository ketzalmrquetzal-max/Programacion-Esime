# ============================================
# PROGRAMA: Estadísticas con Simulación de Punteros
# DESCRIPCIÓN: Demuestra el concepto de punteros usando clases en Python
# ============================================


class Puntero:
    """
    Clase que simula un puntero a un arreglo.

    En lenguajes como C/C++, los punteros apuntan a direcciones de memoria.
    Python no tiene punteros reales, pero esta clase simula el comportamiento
    de un puntero que puede moverse a través de un arreglo.
    """

    def __init__(self, arreglo):
        """
        Constructor del Puntero.

        Parámetros:
            arreglo (list): El arreglo al que "apunta" este puntero
        """
        self._arr = arreglo  # Arreglo subyacente
        self._pos = 0  # Posición actual del puntero (índice)

    def get(self):
        """
        Obtiene el valor en la posición actual del puntero.
        Equivalente a *p en C/C++

        Returns:
            El elemento en la posición actual
        """
        return self._arr[self._pos]

    def get_at(self, i):
        """
        Obtiene el valor en una posición relativa al puntero.
        Equivalente a *(p+i) en C/C++

        Parámetros:
            i (int): Desplazamiento desde la posición actual

        Returns:
            El elemento en la posición _pos + i
        """
        return self._arr[self._pos + i]

    def set_at(self, i, valor):
        """
        Establece un valor en una posición relativa al puntero.
        Equivalente a *(p+i) = valor en C/C++

        Parámetros:
            i (int): Desplazamiento desde la posición actual
            valor: Valor a establecer
        """
        self._arr[self._pos + i] = valor

    def avanzar(self):
        """
        Mueve el puntero una posición adelante.
        Equivalente a p++ en C/C++
        """
        self._pos += 1

    def reset(self):
        """
        Reinicia el puntero al inicio del arreglo.
        Equivalente a p = arr en C/C++
        """
        self._pos = 0


class EstadisticasPuntero:
    """
    Clase que realiza cálculos estadísticos usando la clase Puntero.
    Demuestra cómo usar punteros (simulados) para acceder a los datos.
    """

    def __init__(self, arreglo):
        """
        Constructor que crea un puntero al arreglo.

        Parámetros:
            arreglo (list): Arreglo de números a analizar
        """
        self.puntero = Puntero(arreglo)  # Crea un puntero al arreglo
        self.tamanio = len(arreglo)  # Guarda el tamaño

    def suma(self):
        """
        Calcula la suma usando acceso por puntero.
        Demuestra el uso de get_at() para acceder a elementos.

        Returns:
            int/float: La suma total
        """
        total = 0
        for i in range(self.tamanio):
            total += self.puntero.get_at(i)  # Acceso via *(p+i)
        return total

    def promedio(self):
        """
        Calcula el promedio usando la suma.

        Returns:
            float: El promedio
        """
        return self.suma() / self.tamanio

    def maximo(self):
        """
        Encuentra el máximo usando acceso por puntero.

        Returns:
            int/float: El valor máximo
        """
        m = self.puntero.get_at(0)  # Primer elemento via puntero
        for i in range(1, self.tamanio):
            if self.puntero.get_at(i) > m:
                m = self.puntero.get_at(i)
        return m

    def minimo(self):
        """
        Encuentra el mínimo usando acceso por puntero.

        Returns:
            int/float: El valor mínimo
        """
        m = self.puntero.get_at(0)  # Primer elemento via puntero
        for i in range(1, self.tamanio):
            if self.puntero.get_at(i) < m:
                m = self.puntero.get_at(i)
        return m


# ============================================
# BLOQUE DE EJECUCIÓN PRINCIPAL
# ============================================
if __name__ == "__main__":
    # Crea un objeto que usa punteros para acceder a los datos
    e = EstadisticasPuntero([10, 25, 5, 30, 15])

    # Todos los cálculos se realizan usando acceso por puntero
    print(f"Suma: {e.suma()}")
    print(f"Promedio: {e.promedio()}")
    print(f"Maximo: {e.maximo()}")
    print(f"Minimo: {e.minimo()}")
