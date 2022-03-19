typedef struct {
    int capacity;       //capacidade maxima de elementos no vetor
    int size;           //quantidade de elementos armazenados
    float *data;        //Dados do vetor
}   FloatVector;

FloatVector* create(int capacity);
void destroy(FloatVector** vec_ref);
int size(FloatVector* vec);
int capacity(FloatVector* vec);
float get(FloatVector* vec, int index);
void append(FloatVector* vec, float val);
void set(FloatVector* vec, int index, float val);
void print(FloatVector* vec);
void erase(FloatVector* vec);
void clone(FloatVector* vec);
void rrmov(FloatVector* vec, int index);