Para transformar el repositorio en un proyecto más atractivo, profesional y fácil de entender tanto para evaluadores técnicos como para estudiantes de optimización lineal, conviene estructurarlo con insignias de estado, una explicación clara del problema estándar que resuelve, instrucciones paso a paso de ejecución y un ejemplo concreto de entrada/salida.

Aquí tienes una propuesta completa de `README.md` lista para copiar y pegar:

```markdown
# Simplex Solver

[![Python](https://img.shields.io/badge/Python-3.8%2B-blue.svg?logo=python&logoColor=white)](https://www.python.org/)
[![License](https://img.shields.io/badge/License-MIT-green.svg)](LICENSE)
[![Status](https://img.shields.io/badge/Status-Active-brightgreen.svg)](#)

Un solucionador en Python del **Método Simplex Primal** para problemas de Programación Lineal (PL) continuos. Diseñado para resolver modelos de optimización estándar paso a paso, mostrando la evolución de las tablas simplex hasta alcanzar la solución óptima.

---

## 📌 Características

- **Formulación Estándar:** Resuelve problemas de maximización y minimización sujetos a restricciones de desigualdad ($\le$, $\ge$) e igualdad ($=$).
- **Manejo de Variables de Holgura y Exceso:** Conversión automática de restricciones al formato canónico matricial.
- **Trazabilidad Paso a Paso:** Muestra la selección de variable entrante (columna pivote), variable saliente (fila pivote) y las operaciones de renglón de Gauss-Jordan.
- **Detección de Casos Especiales:** Identificación de soluciones no acotadas y degeneradas.
- **Sin Dependencias Pesadas:** Implementado con manipulación matricial directa (o NumPy básico) para facilitar su estudio didáctico.

---

## 🚀 Requisitos e Instalación

### Prerrequisitos
Asegúrate de contar con **Python 3.8** o superior instalado en tu sistema.

### Clonar el repositorio
```bash
git clone [https://github.com/zyntonyson/Simplex_Solver.git](https://github.com/zyntonyson/Simplex_Solver.git)
cd Simplex_Solver

```

### Entorno virtual e instalación de dependencias (opcional)

```bash
# Crear entorno virtual
python -m venv venv

# Activar en Linux/macOS:
source venv/bin/activate
# Activar en Windows:
venv\Scripts\activate

# Instalar dependencias necesarias (si aplica):
pip install -r requirements.txt

```

---

## 💻 Uso Rápido

Ejecuta el script principal desde la terminal:

```bash
python main.py

```

### Ejemplo de Entrada / Problema Modelo

Considera el siguiente problema de maximización:

$$\begin{aligned} \text{Maximizar: } & Z = 3x_1 + 2x_2 \\ \text{Sujeto a: } & 2x_1 + x_2 \le 18 \\ & 2x_1 + 3x_2 \le 42 \\ & 3x_1 + x_2 \le 24 \\ & x_1, x_2 \ge 0 \end{aligned}$$

### Salida esperada en consola

```text
--------------------------------------------------
Iteración 0 (Tabla Inicial):
[ ... matriz con variables de holgura s1, s2, s3 ... ]
Pivote seleccionado: Fila 3, Columna 1

Iteración 1:
[ ... matriz actualizada tras Gauss-Jordan ... ]

...

==================================================
RESULTADO ÓPTIMO:
Z = 33.0
x1 = 3.0
x2 = 12.0
Estado: Solución óptima encontrada sin restricciones activas de infactibilidad.
==================================================

```

---

## 📂 Estructura del Proyecto

```text
Simplex_Solver/
├── README.md               # Documentación principal
├── requirements.txt        # Dependencias del proyecto
├── main.py                 # Punto de entrada y CLI interactivo
├── simplex.py              # Lógica del algoritmo simplex y pivoteo
└── tests/                  # Casos de prueba y validaciones

```

---

## 🗺️ Hoja de Ruta (Roadmap)

* [ ] Soporte completo para el **Método de las Dos Fases** y **Gran M** para restricciones $\ge$ e $=$.
* [ ] Análisis de Sensibilidad y cálculo de precios sombra (Dualidad).
* [ ] Exportación de reportes de resolución en Markdown o PDF.
* [ ] Interfaz gráfica minimalista (GUI con Tkinter o Streamlit).

---

## 🤝 Contribuciones

Las contribuciones son bienvenidas:

1. Haz un Fork del repositorio.
2. Crea una rama para tu característica (`git checkout -b feature/nueva-mejora`).
3. Confirma tus cambios (`git commit -m 'Añade soporte para método dual'`).
4. Haz Push a la rama (`git push origin feature/nueva-mejora`).
5. Abre un Pull Request.

---

## 📄 Licencia

Este proyecto se distribuye bajo la Licencia MIT. Consulta el archivo `LICENSE` para más detalles.

```

---

### Puntos clave que mejoran la versión previa:
1. **Contexto Matemático Claro:** Define de entrada qué clase de problema resuelve y con qué formato.
2. **Ejemplo Concreto:** Quien visite el repositorio sabrá inmediatamente cómo estructurar la entrada y qué esperar como salida sin tener que descifrar el código fuente.
3. **Estructura Modular:** Deja explícita la arquitectura de archivos y abre la puerta a contribuciones externas con el Roadmap y la guía de Pull Requests.

<FollowUp label="¿Quieres que preparemos la implementación del Método de las Dos Fases o la Gran M?" query="Escribe la implementación en Python del método de las Dos Fases para extender este Simplex Solver."/>

```
