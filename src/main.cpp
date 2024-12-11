#include "TimerSystem.h"  

int main() {  
    // Crear múltiples temporizadores con diferentes tiempos y señales  
    timer_create(5000, 1);  
    timer_create(3000, 2);  
    timer_create(7000, 3);  
    timer_create(2000, 4);  
    timer_create(4000, 5);  

    while (true) {  
        timer_interrupt_handler();  
        break;  
    }  

    return 0;  
}