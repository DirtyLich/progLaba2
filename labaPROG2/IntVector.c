#include <intVector.h> // Подключение заголовочного файла intVector.h

void print_error(int code_error) // Объявление функции print_error с аргументом code_error
{
    switch (code_error) // Начало оператора switch, оцениваемого по аргументу code_error
    {
        case STRUCT_MEMORY_ALLOCATION_ERROR: // Если code_error равен константе STRUCT_ALLOCATION_ERROR 
        printf("%s\n", "error: failed to alllocate memory for the vector"); // Выводим сообщение об ошибке
        break; // Завершаем выполнение оператора switch
        
        case ARRAY_MEMORY_ALLOCATION_ERROR: // Если code_error равен константе ARRAY_MEMORY_ALLOCATION_ERROR
        printf("%s\n", "error: failed to allocate memory for the array"); // Выводим сообщение об ошибке
        break; // Завершаем выполнение оператора switch
        
        case GETTING_INDEX_OUT_OF_ARRAY_ERROR: // Если code_error равен константе GETTING_INDEX_OUT_OF_ARRAY_ERROR
        printf("%s\n", "error: getting ellement out of array"); //выводим сообщение об ошибке
        break; // Завершаем выполнение оператора switch
       
        case SETTING_VALUE_TO_ELEMENT_OUT_OF_ARRAY: // Если code_error равен константе SETTING_VALUE_TO_ELEMENT_OUT_OF_ARRAY
        printf("%s\n", "error: setting value to element out of array"); // Выводим сообщеение об ошибке 
        break; // Завершаем выполнение оператора switch

        default: // Если code_error не равен ни одной из перечисленных констант
        printf("unknown error"); // Выводим сооббщение об ошибке
        break; // Завершаеем работу оператора switch
    }
}
IntVector* int_vector_new(size_t initial_capacity)
{   
    IntVector *vector = malloc(sizeof(IntVector));
    // Выделяем память для структуры IntVector или начальная емкость не положительна, тогда выводим ошибку
    if (vector == NULL || initial_capacity <= 0)
        print_error(STRUCT_MEMORY_ALLOCATION_ERROR);

    // Иначе, инициализируем структуру, выделяем память для массива данных и проверяем успешность выделения
    else
    {
        vector->capacity = initial_capacity;
        vector->data = malloc(INT_SIZE * initial_capacity);

        // Если не удалось выделить память для массива дданных, освобожждаем ранее выделенную память и выводим ошибку
        if (vector->data == NULL)
        {
            free(vector);
            print_error(ARRAY_MEMORY_ALLOCATION_ERROR);
            vector = NULL;
        }
    }
    // Возвращаем указатель на структуру IntVector
    return vector;
}
// Созданиее нового вектора и копирование данных из исходного вектора в него
IntVector *int_vector_copy(const IntVector *v)
{
    // Выделяем память под новый вектор
    IntVector *vector = int_vector_new(v->capacity);
    
    // Проверяем, была ли выделена память под новый вектор
    if (vector != NULL)
    {
        // Копируем данные из исходного вектора в новый
        vector->size = v->size;
        vector->capacity = v->capacity;
        for (int i = 0; i < vector->size; i++)
        {
            // Копируем элементы из исходного вектора в новый
            (vector->data)[i] = (v->data)[i];
        }
    }
    // Возвращаем указатель на новый вектор
    return vector;
}

// Функция, которая освобождает память, выделенную под структуру IntVector и массив data
void int_vector_free(IntVector *v)
{
    if (v != NULL && v->data != NULL) // Проверяем, что указатель на структуру IntVector и на массив data не являются NULL
    free(v->data); // Освобождаем память, выдделенную под массив data
    if (v != NULL) // Проверяем, что указатель на структуру IntVector не является NULL
    free(v); // Освобождаем память, выделенную подд структуру IntVector
}

int int_vector_get_item(const IntVector *v, size_t index)
{
    int item; // Объявляем переменную item для хранения значения элемента массива
    if (index >= 0 && index < v->size) // Проверяем, что индекс находится в пределах размера массива
    item = *(v->data + index); // Присваиваем значение элемента массива по указанному индексу переменной item
    else // Если индекс за пределами массива, то вызываем функцию вывода сообщения об ошибке
    print_error(GETTING_INDEX_OUT_OF_ARRAY_ERROR);
    return item; // возвращаем значение элемента массива
}

//Функция для установки значения элемента вектора по индексу
void int_vector_set_item(IntVector *v, size_t index, int item)
{
    if(index >= 0 && index < v -> size) //если индекс находится в допустимом диапазоне
        *(v->data + index) = item; //устанавливаем значение элемента вектора
    
    else //если индекс находится вне допустимого диапазона
        print_error(SETTING_VALUE_TO_ELEMENT_OUT_OF_ARRAY); //выводим сообщение об ошибкее
}

size_t int_vector_get_size(const IntVector *v)
{
    return v->size; //возвращает размер вектора, который хранитсяв поле size структуры Intvector
}

//функция возвращает теекущую емкость вектора
size_t int_vector_get_capacity(const IntVector *v)
{
    return v ->  capacity; // возвращает текущую емкость вектора
}

//функция уменьшает размер вектора на 1, удаляя последний элемент. Если веектор пустой, то функция ничего не делает
void int_vector_pop_back(IntVector *v)
{
    if (v -> size != 0) //если вектор не пустой
    {
        --(v -> size); //уменьшаем размер вектора на 1
        v -> data[v -> size] = 0; //удаляем последний элемент
    }
}
//функция добавляет новый элемент в конец вектора. Если вектор заполнен, его вместимость увеличивается в два раза
int int_vector_push_back(IntVector *v, int item)
{
    if(v -> size >= v -> capacity) //если размер вектора ббольше или равен его емкости, значит нужно увеличить его емкость
    {
        int_vector_reserve(v, v -> capacity * 2); //вызываем функцию, которая увеличит емкость вектора в два раза
    }
    v -> data[v -> size] = item; //записываем значение item в ячейку массива, соответсвующую размеру вектора
    v -> size += 1; //увеличиваем рамзер вектора на 1
    return 0;
}
//функция изменяет размер выделенной памяти для вектора до его фактического размера(то есть уменьшает выделенную память до минимально необходимого размера для хранеения дданных)
 int int_vector_shrint_to_fit(IntVector *v)
 {
    bool shrink_to_fit_unsuccess = false; //флаг для отслежживания неуддачи уменьшения размера вектора

    if(v -> size == 0 || v -> capacity == 0) //если размеер или емкость равны нулю, то ничего уменьшать не нужно
    shrink_to_fit_unsuccess = true; //помечаем неудачу
 
    else 
    {
        v -> capacity = v-> size; //изменяем емкость вектора на его текущий размер
        v -> data = realloc(v -> data, INT_SIZE* v -> capacity);//изменяем размер выделенной памяти для массива вектора на размер, равный размеру элементов вектора умножеенному на его емкость

        if (v -> data == NULL) //если выделить память не удалось, то помечаем неудачу
        shrink_to_fit_unsuccess = true;
    }
    return -(int)shrink_to_fit_unsuccess; //возвращаем код ошибки, 0-успех, -1 - неудача
 }
//функция изменяет размер веткора "v" на размер "new_size"
int_vector_resize(IntVector *v, size_t new_size)
{
    if(new_size > v -> size) //если новый размер текущего размера вектора 
    {
        if(new_size > v-> capacity) //если новый размер больше вместимости вектора
        {
            int_vector_reserve(v, new_size * 2); //увеличиваем вместимость вектора ддо двух раз больше нового размера
            for(int i = v -> size; i < v -> capacity; i++) //заполняем недостающие элементы вектора нулями
            {
                v -> data[i] = 0;
            }
        }
        v -> size = new_size; //обновляем размер вектора
    }
    if (new_size < v -> size) //если новый размер меньше текущего размера вектора
    {
        v -> size = new_size; //обновляем размер вектора
    }
    return 0;
}

//функция для изменения размера вектора "Intvector" на заданное значение "new_size"
int int_vector_reserve(IntVector *v, size_t new_capacity)
{
    bool reserve_unsuccess = false; //флаг неудачного выделения памяти
    if (new_capacity < v -> capacity || new_capacity < 0) //если новая емкость меньше текущей или отрицательная
        reserve_unsuccess = true; //установить флаг неудачи
    else //в противном случае
    {
        v ->capacity = new_capacity; //установить новую емкость
        v -> data = realloc(v -> data, INT_SIZE * new_capacity); //перевыделить память
        if(v -> data == NULL) //если не удалось выделить память 
        {
            print_error(ARRAY_MEMORY_ALLOCATION_ERROR); //вывести ошибку
            reserve_unsuccess = true; //установить флаг неудачи
        }
    }
    return -(int)reserve_unsuccess;
}
