# Implementación de Cuckoo Hashing

Implementación de la estructura de datos Cuckoo Hash con dos tablas hash y reubicación automática para resolver colisiones mediante el algoritmo de Cuckoo Hashing.

## Compilación y Ejecución
```bash
g++ src/main.cpp src/HashTable.cpp -I include -o main.exe && main.exe
```

## Funcionalidad
El programa implementa un sistema de hash con dos tablas independientes que permite:

- **Inserción eficiente** con manejo automático de colisiones
- **Reubicación Cuckoo**: Desplazamiento de elementos entre tablas cuando hay colisión
- **Redimensionamiento dinámico**: Duplica el tamaño automáticamente tras 20 reubicaciones
- **Visualización en tiempo real**: Muestra el estado de ambas tablas después de cada inserción

## Estructura

**HashTable**: Clase principal que implementa el Cuckoo Hash con dos tablas internas (`HashTable_1` y `HashTable_2`)

**CuckoHash**: Algoritmo de reubicación que desplaza elementos entre tablas hasta encontrar una posición libre

**Funciones Hash**: Dos funciones hash independientes (`firstHash` y `secondHash`) basadas en la suma de cuadrados de caracteres

**Redimensionamiento**: Duplica el tamaño de ambas tablas cuando se alcanza el límite de reubicaciones (20 intentos)

El Cuckoo Hash mantiene dos tablas con funciones hash distintas. Al insertar, si hay colisión en la primera tabla, el elemento existente es desplazado a su posición alternativa en la segunda tabla. Este proceso continúa hasta encontrar una posición vacía o alcanzar el límite de reubicaciones.

## Complejidad Temporal
| Operación | Caso Promedio | Caso Peor |
|-----------|---------------|-----------|
| insertar() | O(1) | O(n)* |
| buscar() | O(1) | O(1) |
| eliminar() | O(1) | O(1) |
| resizeHashTables() | O(n) | O(n) |

**Nota**: La complejidad O(n) en inserción ocurre solo durante el rehashing cuando se alcanza el límite de 20 reubicaciones. En la práctica, la inserción es O(1) amortizado con factor de carga ≤ 0.5.

## Ejemplo de Uso
El programa inserta 17 palabras y muestra paso a paso cómo se distribuyen en las dos tablas:

```
Insertando: computadora
Insertando: programacion
Insertando: algoritmo
...
```

Cada inserción muestra el estado actual de ambas tablas hash, permitiendo observar el comportamiento del algoritmo de Cuckoo Hashing en acción.
