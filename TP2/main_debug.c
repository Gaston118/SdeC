/* main_debug.c
   Programa C PURO para depurar con GDB.
   Muestra el estado del stack ANTES, DURANTE y DESPUÉS de llamar a gini_convert().

   Compilar con:
     gcc -g3 -O0 -no-pie -o debug_gini main_debug.c gini_stub.c

   Depurar con:
     gdb ./debug_gini
*/

#include <stdio.h>
#include "gini_calc.h"

/* Declaramos directamente gini_convert para poder llamarla desde main
   sin pasar por calcular_gini, así GDB muestra el stack más limpio */
extern long gini_convert(double valor);

int main() {
    /* Valor GINI real de Argentina 2020 (obtenido de la API) */
    double gini_arg   = 42.9;
    double gini_bra   = 48.9;
    double gini_uru   = 39.7;
    long   resultado  = 0;

    printf("=== TP2 - Depuración GINI con GDB ===\n\n");

    /* ── ANTES de llamar al ASM ────────────────────────────────────────────
       Punto de breakpoint recomendado: aquí se ve el stack de main limpio.
       En GDB:  break main_debug.c:44
                x/8xg $rsp        <- ver 8 "giant words" del stack
                info registers    <- ver todos los registros             */

    printf("[C] Valor a enviar al ASM: %.4f\n", gini_arg);
    printf("[C] RSP antes de la llamada: se ve en GDB con 'x/8xg $rsp'\n\n");

    /* ── LLAMADA al ASM ────────────────────────────────────────────────────
       El double gini_arg se pasa en XMM0 (convención System V AMD64 ABI).
       Segundo breakpoint recomendado: dentro de gini_convert
       En GDB:  break gini_convert
                stepi              <- paso a paso en ASM
                info registers xmm0  <- ver el double recibido
                x/8xg $rsp        <- ver el stack dentro del ASM         */

    resultado = gini_convert(gini_arg);

    /* ── DESPUÉS de la llamada ─────────────────────────────────────────────
       El resultado vuelve en RAX.
       Tercer breakpoint recomendado: línea siguiente al return
       En GDB:  break main_debug.c:63
                print $rax        <- ver el resultado en RAX
                info registers    <- confirmar que RBP/RSP se restauraron */

    printf("[C] Resultado ASM Argentina (%.1f -> int+1): %ld\n\n", gini_arg, resultado);

    /* Procesamos más países para ver múltiples llamadas al stack en GDB */
    printf("--- Procesando múltiples países ---\n");
    printf("Argentina  (%.1f) -> %ld\n", gini_arg, resultado);

    resultado = gini_convert(gini_bra);
    printf("Brasil     (%.1f) -> %ld\n", gini_bra, resultado);

    resultado = gini_convert(gini_uru);
    printf("Uruguay    (%.1f) -> %ld\n", gini_uru, resultado);

    printf("\n=== Fin del programa ===\n");
    return 0;
}
