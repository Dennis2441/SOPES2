#ifndef PRIORITYQUEUE_H  
#define PRIORITYQUEUE_H  

#include <queue>  
#include <vector>  
#include <functional>  

// Comparador personalizado para la cola de prioridades  
struct CompareByKey {  
    template <typename T, typename K>  
    bool operator()(const std::pair<K, T>& a, const std::pair<K, T>& b) const {  
        return a.first > b.first; // Comparación basada únicamente en las claves  
    }  
};  

// Clase para una cola de prioridades genérica  
template <class T, class K>  
class PriorityQueue {  
    using Element = std::pair<K, T>;  // (clave, valor)  
    std::priority_queue<Element, std::vector<Element>, CompareByKey> pq;  

public:  
    // Añade un elemento a la cola  
    void add(T info, K key) {  
        pq.emplace(key, info);  // Solo se utiliza la clave para la comparación  
    }  

    // Devuelve el elemento con mayor prioridad (menor clave) sin eliminarlo  
    T head() {  
        if (!pq.empty()) return pq.top().second;  
        return T();  
    }  

    // Devuelve la clave del elemento con mayor prioridad  
    K headKey() {  
        if (!pq.empty()) return pq.top().first;  
        return K();  
    }  

    // Elimina y devuelve el elemento con mayor prioridad  
    T pop() {  
        if (!pq.empty()) {  
            T value = pq.top().second;  
            pq.pop();  
            return value;  
        }  
        return T(); // Retorna un objeto vacío si la cola está vacía  
    }  
};  

#endif