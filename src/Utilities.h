#ifndef UTILITIES_H  
#define UTILITIES_H  

#include <iostream>  
#include <chrono>  
#include <thread>  

// Devuelve el tiempo actual en milisegundos  
long get_time() {  
    auto now = std::chrono::steady_clock::now();  
    return std::chrono::duration_cast<std::chrono::milliseconds>(now.time_since_epoch()).count();  
}  

// Simula obtener el PID del proceso actual  
long get_pid() {  
    return 12345; // Valor fijo de ejemplo (puedes reemplazarlo por un sistema de múltiples procesos)  
}  

// Simula enviar una señal  
void send_signal(long pid, long signal) {  
    std::cout << "Señal " << signal << " enviada al proceso con PID " << pid << "\n";  
}  

// Simula iniciar un temporizador físico  
void timer_start(long time) {  
    std::cout << "Temporizador físico configurado por " << time << " ms\n";  
}  

// Simula detener el temporizador físico  
void timer_stop() {  
    std::cout << "Temporizador físico detenido.\n";  
}  

#endif