# UNIVERSIDAD NACIONAL DE CÓRDOBA
# FACULTAD DE CIENCIAS EXACTAS, FÍSICAS Y NATURALES

## SISTEMAS DE COMPUTACIÓN	
## Trabajo Práctico N°1: Rendimiento
### Grupo: BugBusters

- Alfici Facundo
- Capdevila Gastón
- Viberti Tomas

### Docentes
- Jorge, Javier
- Solinas, Miguel

### 2026

---

## GPROF

Debemos asegurarnos de que la generación de perfiles esté habilitada cuando se complete la compilación del código. Esto es posible al agregar la opción '-pg' en el paso de compilación.

<img width="1198" height="220" alt="image" src="https://github.com/user-attachments/assets/1911b2b5-1a7b-48f8-a526-2d20faa640bd" />

**Ejecutar la herramienta gprof**

<img width="1062" height="91" alt="image" src="https://github.com/user-attachments/assets/8c723847-1411-449d-b8f0-d9c99792127c" />

<img width="755" height="919" alt="image" src="https://github.com/user-attachments/assets/ed721d31-ae8a-4713-87da-099e9765bcbe" />

---

### 1. Suprima la impresión de funciones declaradas estáticamente (privadas) usando -a
Aplicando la flag -a se suprimen las funciones declaradas estáticamente (privadas). Por ejemplo, en este caso la func2 no devolverá información por ser estática.

**gprof -a test_gprof gmon.out > analysis.txt**

<img width="878" height="928" alt="image" src="https://github.com/user-attachments/assets/74e020b4-22b1-4cff-bf57-dbb46eda84d5" />

### 2. Elimine los textos detallados usando -b
Aplicando la flag -b se suprimen los textos detallados. Entonces podemos observar que se obtienen solo gráficos y resultados concretos del test.

**gprof -b test_gprof gmon.out > analysis.txt**

<img width="836" height="896" alt="image" src="https://github.com/user-attachments/assets/ddc26439-77a6-4a0f-8dd8-a7e688308c91" />

### 3. Imprima solo perfil plano usando -p
Aplicando la flag -p se obtiene como salida solo el perfil plano.

**gprof -p test_gprof gmon.out > analysis.txt**

<img width="820" height="929" alt="image" src="https://github.com/user-attachments/assets/bc2c0fa4-dbe5-42db-8c72-4b9a49b593a3" />

### 4. Imprimir información relacionada con funciones específicas en perfil plano

**gprof -pfunc1 -b test_gprof gmon.out > analysis.txt**

<img width="721" height="203" alt="image" src="https://github.com/user-attachments/assets/dad0e1ce-a3fb-43c6-8c97-a904e99525ec" />

### Grafico

<img width="1376" height="240" alt="image" src="https://github.com/user-attachments/assets/871abba5-a033-4e70-8e04-f34d7b19d195" />

<img width="233" height="396" alt="image" src="https://github.com/user-attachments/assets/b404db71-2cf2-4a8b-8ca5-f89b5d9fb53d" />

---

## Profiling con linux perf

<img width="1075" height="554" alt="image" src="https://github.com/user-attachments/assets/bb7e52c2-c003-4693-94a5-97d17d0da075" />

**$ sudo perf report**

<img width="937" height="957" alt="image" src="https://github.com/user-attachments/assets/5d1f0dea-d879-4554-b346-7039850d642c" />

- La imagen muestra el reporte de perf con las funciones de test_gprof ordenadas por tiempo de CPU. 
- Las funciones propias del programa son `func1` (49,10%), `func2` (40,51%), `new_func1` (3,95%) y `main` (2,68%). 
- El resto son funciones del kernel Linux (`[k]`) que se pueden ignorar.

---

## Benchmarks

---

## ¿Cual es el rendimiento de estos procesadores para compilar el kernel de linux?
- Intel Core i5-13600K
- AMD Ryzen 9 5900X 12-Core
Cual es la aceleración cuando usamos un AMD Ryzen 9 7950X 16-Core

