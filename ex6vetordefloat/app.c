#include "float_vector.h"
#include <stdio.h>

int main() {
    FloatVector *vec = create(10);
    print(vec);
    append(vec, 4.6);
    append(vec, 22.4);
    append(vec, 13.7);
    print(vec);
    //printf("Valor do indice: %f", get(vec, 2));
    set(vec, 1, 77.3);
    rrmov(vec,2);
    clone(vec);
    print(vec);
    erase(vec);
    print(vec);
   
}