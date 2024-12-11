#include "TimerSystem.h"  
#include "PriorityQueue.h"  
#include "TimerRequest.h"  
#include "Utilities.h"  

// Cola de prioridades global que organiza los temporizadores  
PriorityQueue<TimerRequest, long> timerQueue;  

void timer_create(long timems, long signal) {  
    long pid = get_pid();                      
    long expirationTime = get_time() + timems;  

    TimerRequest request = {pid, signal};  
    timerQueue.add(request, expirationTime);  

    // Reiniciar el temporizador físico si el nuevo temporizador tiene la prioridad más alta  
    if (timerQueue.headKey() == expirationTime) {  
        timer_stop();    
        timer_start(timems);   
    }  
}  

void timer_interrupt_handler() {  
    TimerRequest expiredTimer = timerQueue.pop();  
    send_signal(expiredTimer.pid, expiredTimer.signal);  

    // Configurar el siguiente temporizador en la cola si existe  
    if (timerQueue.headKey()) {  
        long currentTime = get_time();  
        long nextExpirationTime = timerQueue.headKey() - currentTime;  
        timer_start(nextExpirationTime);  
    }  
}