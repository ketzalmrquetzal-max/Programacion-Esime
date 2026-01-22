# ============================================
# PROGRAMA: Herencia con Sobreescritura de Métodos
# DESCRIPCIÓN: Demuestra polimorfismo mediante sobreescritura de métodos abstractos
# ============================================

from abc import ABC, abstractmethod
import cmath


class CalculadoraBase(ABC):
    """
    Clase abstracta que define métodos que DEBEN ser implementados por las clases hijas.
    Demuestra el concepto de polimorfismo: mismo método, diferentes implementaciones.
    """

    def __init__(self):
        """Inicializa el atributo resultado."""
        self.resultado = 0

    @abstractmethod
    def multiplicar(self, a, b):
        """
        Método abstracto para multiplicación.
        Las clases hijas deben implementar su propia versión.
        """
        pass

    @abstractmethod
    def potencia(self, base, exp):
        """
        Método abstracto para potenciación.
        Las clases hijas deben implementar su propia versión.
        """
        pass

    @abstractmethod
    def dividir(self, a, b):
        """
        Método abstracto para división.
        Las clases hijas deben implementar su propia versión.
        """
        pass


class CalculadoraDirecta(CalculadoraBase):
    """
    Implementación directa usando operadores nativos de Python.
    Métodos más rápidos pero menos educativos.
    """

    def multiplicar(self, a, b):
        """
        Multiplicación directa usando el operador *.

        Returns:
            int/float: Resultado de a * b
        """
        self.resultado = a * b
        return self.resultado

    def potencia(self, base, exp):
        """
        Potenciación usando funciones matemáticas.
        Usa logaritmos y exponenciales para valores positivos.

        Returns:
            complex/float: Resultado de base^exp
        """
        self.resultado = cmath.exp(exp * cmath.log(base)) if base > 0 else base**exp
        return self.resultado

    def dividir(self, a, b):
        """
        División directa con validación.

        Returns:
            float: Resultado de a / b
            None: Si b es 0
        """
        self.resultado = a / b if b != 0 else None
        return self.resultado


class CalculadoraSucesiva(CalculadoraBase):
    """
    Implementación algorítmica usando sumas/restas sucesivas.
    Demuestra cómo funcionan las operaciones a nivel fundamental.
    Menos eficiente pero más educativa.
    """

    def multiplicar(self, a, b):
        """
        Multiplicación mediante sumas sucesivas.

        Concepto: a * b = a + a + a + ... (b veces)
        Ejemplo: 3 * 4 = 3 + 3 + 3 + 3 = 12

        Maneja números negativos correctamente:
        - Si uno es negativo, resultado es negativo
        - Si ambos son negativos, resultado es positivo
        """
        self.resultado = 0
        for _ in range(abs(int(b))):  # Repite |b| veces
            self.resultado += abs(a)  # Suma |a|
        # Ajusta el signo si los operandos tienen signos diferentes
        if (a < 0) != (b < 0):
            self.resultado = -self.resultado
        return self.resultado

    def potencia(self, base, exp):
        """
        Potenciación mediante multiplicaciones sucesivas.

        Concepto: base^exp = base * base * ... (exp veces)
        Ejemplo: 2^4 = 2 * 2 * 2 * 2 = 16

        Implementado con multiplicación por sumas sucesivas anidadas.
        """
        self.resultado = 1
        for _ in range(abs(int(exp))):
            temp = 0
            for _ in range(abs(int(base))):
                temp += abs(self.resultado)
            self.resultado = temp
        return self.resultado

    def dividir(self, a, b):
        """
        División mediante restas sucesivas.

        Concepto: a / b = cuántas veces cabe b en a
        Ejemplo: 17 / 5 = 3 (cabe 3 veces con residuo 2)

        Returns:
            tuple: (cociente, residuo)
            None: Si b es 0
        """
        if b == 0:  # División por cero
            return None

        cociente = 0
        residuo = abs(a)

        # Resta |b| de |a| hasta que no se pueda más
        while residuo >= abs(b):
            residuo -= abs(b)
            cociente += 1

        # Ajusta el signo del cociente
        self.resultado = cociente if (a >= 0) == (b >= 0) else -cociente
        return self.resultado, residuo


# ============================================
# BLOQUE DE EJECUCIÓN PRINCIPAL
# ============================================
if __name__ == "__main__":
    # Prueba de CalculadoraDirecta (implementación rápida)
    cd = CalculadoraDirecta()
    print(f"Directa: 4*5 = {cd.multiplicar(4, 5)}")
    print(f"Directa: 2^4 = {cd.potencia(2, 4)}")

    # Prueba de CalculadoraSucesiva (implementación educativa)
    cs = CalculadoraSucesiva()
    print(f"Sucesiva: 4*5 = {cs.multiplicar(4, 5)}")
    print(f"Sucesiva: 17/5 = {cs.dividir(17, 5)}")  # (cociente=3, residuo=2)
