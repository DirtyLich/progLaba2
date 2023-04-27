#include <stdio.h>
#include <stdlib.h>
#include "IntVector.h"

int main()
{
// Создание и инициализация вектора a типа IntVector с начальной емкостью 5
printf("%s\n", "Объявление и инициализация вектора целых чисел с емкостью 5");
IntVector* a = int_vector_new(5);

// Вывод размера и емкости вектора a
printf("%s %ld %s%ld\n\n", "Размер вектора:", int_vector_get_size(a),". Емкость:", int_vector_get_capacity(a));

// Изменение размера вектора a на 10 и вывод его нового размера
printf("%s\n", "Изменение размера вектора a, заполнение его элементами, создание вектора b и копирование вектора a в b");
int_vector_resize(a, 10);
printf("%s %ld\n\n\n", "Теперь вектор имеет размер:", int_vector_get_size(a));

// Создание вектора b как копии вектора a и вывод размера и емкости обоих векторов
IntVector* b = int_vector_copy(a);
printf("%s\n %s %p %ld %ld\n", "Теперь у нас есть два вектора:", "вектор a:", a, int_vector_get_size(a), int_vector_get_capacity(a));
printf("%s %p %ld %ld\n\n\n", "вектор b:", b, int_vector_get_size(b), int_vector_get_capacity(b));

// Освобождение памяти, занятой вектором b, сжатие емкости вектора a и вывод его размера и емкости
int_vector_free(b);
int_vector_shrink_to_fit(a);
printf("%s %ld %s%ld\n\n", "Вывод размера и емкости векторов:", int_vector_get_size(a),". Емкость:", int_vector_get_capacity(a));

// Вызов функции reserve, изменяющей емкость вектора a на 20 и вывод результата
printf("%d\n\n", int_vector_reserve(a, 20));
printf("%s %ld %s%ld\n\n", "Вывод размера и емкости векторов:", int_vector_get_size(a),". Емкость:", int_vector_get_capacity(a));

// Вывод элементов вектора a и добавление в него нового элемента
for (size_t i = 0; i < int_vector_get_size(a); i++)
{
printf("%ld. %d\n", i, int_vector_get_item(a, i));
}
printf("\n\n\n\n");
int_vector_push_back(a, 1);

for (size_t i = 0; i < int_vector_get_size(a); i++)
{
printf("%ld. %d\n", i, int_vector_get_item(a, i));
}
printf("\nsize: %ld\n", int_vector_get_size(a));
printf("-----------------------------------\n");
int_vector_set_item(a, 9, -5); // устанавливаем значение -5 для 10-го элемента вектора a
int_vector_pop_back(a); // удаляем последний элемент из вектора a
for (size_t i = 0; i < int_vector_get_size(a); i++)
{
printf("%ld. %d\n", i, int_vector_get_item(a, i));
}
printf("\nsize: %ld\n", int_vector_get_size(a));
return 0;
}

