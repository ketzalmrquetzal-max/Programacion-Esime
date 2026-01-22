# ============================================
# PROGRAMA: Punteros a Tipos de Datos Personalizados
# DESCRIPCIÓN: Combina el concepto de punteros con objetos personalizados
# ============================================


class Persona:
    """
    Clase que representa a una persona.
    """

    def __init__(self, nombre, ap, am, genero, edad):
        """
        Constructor de Persona.

        Parámetros:
            nombre (str): Nombre de pila
            ap (str): Apellido paterno
            am (str): Apellido materno
            genero (str): Género
            edad (int): Edad
        """
        self.nombre = nombre
        self.ap = ap
        self.am = am
        self.genero = genero
        self.edad = edad

    def __str__(self):
        """Representación en string de la persona."""
        return f"{self.nombre} {self.ap}, {self.edad} años"


class Puntero:
    """
    Clase que simula un puntero a un arreglo.
    Permite acceso tipo C/C++ a elementos del arreglo.
    """

    def __init__(self, arreglo):
        """
        Constructor del puntero.

        Parámetros:
            arreglo (list): Arreglo al que apunta
        """
        self._arr = arreglo  # Arreglo subyacente
        self._pos = 0  # Posición actual del puntero

    def get(self):
        """
        Obtiene el elemento en la posición actual.
        Equivale a *p en C/C++

        Returns:
            El elemento en _pos
        """
        return self._arr[self._pos]

    def get_at(self, i):
        """
        Obtiene el elemento en una posición relativa.
        Equivale a *(p+i) en C/C++

        Parámetros:
            i (int): Desplazamiento desde la posición actual

        Returns:
            El elemento en _pos + i
        """
        return self._arr[self._pos + i]

    def avanzar(self):
        """
        Avanza el puntero una posición.
        Equivale a p++ en C/C++
        """
        self._pos += 1

    def reset(self):
        """
        Reinicia el puntero al inicio.
        Equivale a p = arr en C/C++
        """
        self._pos = 0

    def tamanio(self):
        """
        Retorna el tamaño del arreglo.

        Returns:
            int: Número de elementos
        """
        return len(self._arr)


class ListaPersonasPuntero:
    """
    Lista de personas con acceso mediante punteros.

    Combina dos conceptos:
    1. Almacenamiento de objetos personalizados (Persona)
    2. Acceso mediante punteros (simulados)

    Demuestra cómo trabajar con estructuras de datos complejas
    usando el concepto de punteros.
    """

    def __init__(self):
        """
        Constructor que inicializa una lista vacía.
        """
        self._datos = []  # Lista interna de personas
        self.puntero = None  # Puntero a la lista (inicialmente None)

    def agregar(self, persona):
        """
        Agrega una persona y actualiza el puntero.

        Parámetros:
            persona (Persona): Persona a agregar

        Después de agregar, recrea el puntero para incluir el nuevo elemento.
        """
        self._datos.append(persona)
        self.puntero = Puntero(self._datos)  # Actualiza el puntero

    def obtener(self, i):
        """
        Obtiene una persona por índice usando el puntero.

        Parámetros:
            i (int): Índice de la persona

        Returns:
            Persona: La persona en el índice i
        """
        return self.puntero.get_at(i)

    def mostrar(self):
        """
        Muestra todas las personas usando notación de puntero.

        Simula la sintaxis de C: *p+0, *p+1, *p+2, etc.
        Esto es educativo para entender cómo funcionan los punteros
        en lenguajes de bajo nivel.
        """
        for i in range(self.puntero.tamanio()):
            # Muestra en formato "*p+i: valor"
            print(f"*p+{i}: {self.puntero.get_at(i)}")


# ============================================
# BLOQUE DE EJECUCIÓN PRINCIPAL
# ============================================
if __name__ == "__main__":
    # Crea una lista con acceso por puntero
    lp = ListaPersonasPuntero()

    # Agrega personas
    lp.agregar(Persona("Juan", "Perez", "Garcia", "M", 25))
    lp.agregar(Persona("Maria", "Lopez", "Sanchez", "F", 30))
    lp.agregar(Persona("Pedro", "Ramirez", "Torres", "M", 22))

    # Muestra usando notación de puntero
    lp.mostrar()
    # Salida:
    # *p+0: Juan Perez, 25 años
    # *p+1: Maria Lopez, 30 años
    # *p+2: Pedro Ramirez, 22 años
