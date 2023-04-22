#include <stdio.h> // подключаем библиотеку для ввода и вывода данных
#include <stdlib.h> // подключаем библиотеку для работы с памятью  
#include <stdbool.h> // подключаем библиотеку с логическими значениями

// макросы для определения констант и кодов ошибок
#define INT_SIZE sizeof(int) // размер целого числа в байтах
#define STRUCT_MEMORY_ALLOCATION_ERROR -1 // ошибка при выделении памяти для структуры 
#define ARRAY_MEMORY_ALLOCATION_ERROR -2 // ошибка при выделении памяти для массива в структуре 
#define GETTING_INDEX_OUT_OF_ARRAY_ERROR -3 // ошибка при получении элемента по индексу вне диапазона массива
#define SETTING_VALUE_TO_ELEMENT_OUT_OF_ARRAY -4 // ошибка при установке значения элемента вне диапазона массива

// Определение структуры данных IntVector, представляющей динамический массив целых чисел
typedef struct 
{
    int* data; // указатель на массив целых чисел
    int capacity; // емкость массива (количество выделенных ячеек памяти)
    int size; // количество элементов в массиве
} IntVector;

// объявление функций
void print_error(int code_error);
IntVector* int_vector_new(size_t);
IntVector* int_vector_copy(const IntVector *v);
void int_vector_free(IntVector *v);
int int_vector_get_item(const IntVector *v, size_t index);
void int_vector_set_item(IntVector *v, size_t index, int item);
size_t int_vector_get_size(const IntVector *v);
size_t int_vector_get_capacity(const IntVector *v);
void int_vector_pop_back(IntVector *v);
int int_vector_push_back(IntVector *v, int item);
int int_vector_shrink_to_fit(IntVector *v);
int int_vector_resize(IntVector *v, size_t new_size);
int int_vector_reserve(IntVector *v, size_t new_capacity);

