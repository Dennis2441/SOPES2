cmake_minimum_required(VERSION 3.10)  
project(TimerSystemProject)  

set(CMAKE_CXX_STANDARD 17)  

# Ruta de los encabezados  
include_directories(include)  

# Añadir y compilar el ejecutable  
add_executable(TimerSystemProject   
    src/main.cpp   
    src/TimerSystem.cpp   
    src/PriorityQueue.h   
    src/TimerRequest.h   
    src/Utilities.h)