#ifndef TIMERREQUEST_H  
#define TIMERREQUEST_H  

 
struct TimerRequest {  
    long pid;      // ID del proceso al que está asociado el temporizador  
    long signal;   // Señal que se debe enviar al proceso cuando expire el temporizador  
};  

#endif