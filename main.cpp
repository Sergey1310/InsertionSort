#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>





template <typename T, typename F> //Делаем функцию шаблонной, где Т - шаблон для принимаемого массива, а F - шаблон для временной переменной так как её тип предположительно тоже неизвестно.
void InsertionSort(T* arr, int size) // Функция сортировки вставками. Не возвращает никакого значения так как работает с указателем на массив "arr". Целочисленная переменная "size" принимает размер массива.
{
    F temp; // Временная переменная для хранения переставляемого значения.
    for (int i = 0; i < size-1 ; ++i) { // Цикл прохода по массиву. Так как каждый элемент массива сравнивается со следующим за ним, количество итераций на единицу меньше размера массива (size-1).
        if (arr[i] > arr[i+1]) // Первая проверка, определяет - является ли следующий элемент массива меньше текущего, если да - то выполняется нижестоящая функция, в противном случае игнорируется.
        {
            for (int j = i+1; j >= 0 ; --j) // Этот цикл идёт в обратном порядке и перемещает элемент на его место в списке. Так как из описания вышестоящего цикла известно,
                // что сравнивается элемент следующий за текущим, то для определения необходимого числа итераций, в цикле используется число - на единицу больше текущего положения элемента,
                // отсчёт ведётся до значения меньше или равного 0, чтобы охватить все ранее отсартированные элементы.
            {
                if (arr[j] < arr[j-1]) // Вторая проверка, сравнивает перемещаемый элемент с предыдущим элементом.
                {
                    temp = arr[j]; // Сохраняем значение текущего элемента во временную переменную.
                    arr[j] = arr[j-1]; // Перемещаем значение предыдущего элемента в текущий.
                    arr[j-1] = temp; // Кладём в предыдущий элемент - значение текущего. Таким образом меняем местами элементы массива.
                }
            }
        }
    }
}

// Функции для тестирования и вспомогательные по отношению к ним функции:

//Функции заполнения массива с использованием rand. Принимают указатель на массив и его размер.
template<typename T>
void FillArrayMixed(T* arr, int size) // Смешанное заполнение массива положительными и отрицательными числами.
{
    for (int i = 0; i < size; ++i) {
        if (i%2 != 0) { // Делаем нечётные числа положительными.
            arr[i] = rand();
        }else arr[i] = -(rand()); // А чётные - отрицательными.
    }
}
template<typename T>
void FillArrayPositive(T* arr, int size) // Заполнение массива только положительными числами.
{
    for (int i = 0; i < size; ++i) {
            arr[i] = rand();
    }
}
template<typename T>
void FillArrayNegative(T* arr, int size) // Заполнение только отрицательными числами.
{
    for (int i = 0; i < size; ++i) {
            arr[i] = -(rand());
           }
}
template<typename T>
void FillArray(T* arr, int size,int type) // Обобщённая функция заполнения массива. Принимает ссылку на массив и его размер, а так же тип вызываемого заполнения.
//Так как инструмент тестирования не предполагает взаимодействия с пользователем, а используется исключительно в функциях, их определение в дальнейшем не приводится.
{
    switch (type) {
        case 0:
            FillArrayMixed(arr,size);
            break;
        case 1:
            FillArrayPositive(arr,size);
            break;
        case 2:
            FillArrayNegative(arr,size);
            break;
        default: std::cout << "Incorrect value";
    }
}

template<typename T>
void ShowArray(T* arr, int size) // Функция вывода значений массива на экран. Принимает ссылку на массив и его размер.
{
    for (int i = 0; i < size; ++i) {
        std::cout << arr[i] << "\t";
    }
    std::cout << std::endl;
}

//Функции нахождения наибольшего и наименьшего элементов массива - для их сравнения с первым и последним элементами  отсортированного массива.
int IntGreatestNumber(int* arr, int size) // Функция нахождения наибольшего значения массива.
{
    int greatest = arr[0]; // Временная переменная для хранения наибольшего значения
    for (int i = 0; i < size-1 ; ++i) { // Пробегаемся по массиву, так же количество раз на единицу меньшее чем размер массива.
        if (arr[i] < arr[i+1]) // Сравниваем текущее значение с последующим.
            greatest = arr[i+1]; // Если следующее значение больше - сохраняем его в переменной.
    }
    return greatest;
}

int IntLeastNumber(int* arr, int size) // Функция нахождения наименьшего элемента массива.
{
    // Аналогична предыдущей меняем только знак равенства
    int least = arr[0];
    for (int i = 0; i < size-1 ; ++i) {
        if (arr[i] > arr[i+1])
            least = arr[i+1];
    }
    return least;
}

void IntCheckTest(int* arr, int size) // Функция попарно выводит на экран значения наименьшего элемента и первого элемента массива.
// Наибольшего элемента и последнего элемента массива.
// Так же выводит сообщение об ошибке если они не совпадают.
{
    std::cout << std::endl;
    std::cout << "Min number: " << IntLeastNumber(arr,size) << std::endl;
    std::cout << "First element: " << arr[0] << std::endl;
    if (IntLeastNumber(arr,size) != arr[0]) std::cout << "Test FALSE" << std::endl;
    std::cout << std::endl;

    std::cout << "Max number: " << IntGreatestNumber(arr,size) << std::endl;
    std::cout << "Last element: " << arr[size-1] << std::endl;
    if (IntGreatestNumber(arr,size) != arr[size-1]) std::cout << "Test FALSE" << std::endl;
    std::cout << std::endl;
}

// Функции тестирования. Заполняют массив в трёх вариантах заполнения "Смешанный", "Положительные числа", "Отрицательные числа" .
void IntRundomCountOfElementsTest(int size) // Функция создаёт и заполняет массив заданного размера.
{
    for (int i = 0; i < 3 ; ++i) { // Цикл реализует разные варианты заполнения массива в зависимости.
        std::string sign[3]{"Mixed", "Positive", "Negative"}; // Массив названий вариантов заполнения для отображения соответствующего варианта на экран.
        std::cout << "Start test with " << size << " random element/s in array with :: " << sign[i] << " sign: " << std::endl; // Информация о запуске теста с указанием метода заполнения и количество элементов.
        int *arr = new int[size]; // Выделяем память под новый массив.
        FillArray(arr, size, i); // Заполняем массив в зависимости от переменной "i" - заданным вариантом.
        std::cout << "Before sorting: "; // Выводим не отсортированный массив на экран.
        ShowArray(arr, size);
        InsertionSort<int, int>(arr, size); // Производим сортировку.
        std::cout << "After sorting: "; // Выводим отсортированный список на экран.
        ShowArray(arr, size);
        IntCheckTest(arr, size); // Вызываем функцию проверки - выводит на экран первый и последний элемент массива, сравнивает с наибольшим и наименьшими элементами.
        std::cout << "Finish test" << std::endl; // Вывод на экран информации о завершении теста и разделительной строки
        std::cout << "--------------------------------------------------------------------------------------------------" << std::endl << std::endl;
        delete[] arr; // Освобождаем память.
    }
}

void IntEmptyTest() // Тестируем пустой массив.
{
    std::cout << "START EMPTY TEST" << std::endl;
    for (int i = 0; i < 3 ; ++i) {
        std::string sign[3]{"Mixed","Positive","Negative"} ;
        std::cout << "Start test with empty array with :: " << sign[i] << " sign: " << std::endl;
        int size = 0;
        int *arr = new int[size];
        FillArray(arr, size, i);
        std::cout << "Before sorting: ";
        ShowArray(arr, size);
        InsertionSort<int, int>(arr, size);
        std::cout << "After sorting: ";
        ShowArray(arr, size);
        std::cout << "Finish test" << std::endl;
        std::cout << "--------------------------------------------------------------------------------------------------" << std::endl << std::endl;
        delete[] arr;
    }
    std::cout << "FINISH EMPTY TEST" << std::endl << "@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@" << std::endl << std::endl; // Отделяем блок из трёх тестов.

}
void IntOneElementTest() // Тестируем массив с одним элементом.
{
    std::cout << "START ONE ELEMENT TEST" << std::endl;
    for (int i = 0; i < 3 ; ++i) {
        std::string sign[3]{"Mixed", "Positive", "Negative"};
        std::cout << "Start test with one random element in array with :: " << sign[i] << " sign: " << std::endl;
        int size = 1;
        int *arr = new int[size];
        FillArray(arr, size, i);
        std::cout << "Before sorting: ";
        ShowArray(arr, size);
        InsertionSort<int, int>(arr, size);
        std::cout << "After sorting: ";
        ShowArray(arr, size);
        std::cout << "Finish test" << std::endl;
        std::cout << "--------------------------------------------------------------------------------------------------" << std::endl << std::endl;
        delete[] arr;
    }
    std::cout << "FINISH ONE ELEMENT TEST" << std::endl << "@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@" << std::endl << std::endl;
}
void IntTwoElementsTest() // Тестируем массив из двух элементов.
{
    std::cout << "START TWO ELEMENT TEST" << std::endl;
    for (int i = 0; i < 3 ; ++i) {
        std::string sign[3]{"Mixed", "Positive", "Negative"};
        std::cout << "Start test with two random elements in array with :: " << sign[i] << " sign: " << std::endl;
        int size = 2;
        int *arr = new int[size];
        FillArray(arr, size,i);
        std::cout << "Before sorting: ";
        ShowArray(arr, size);
        InsertionSort<int, int>(arr, size);
        std::cout << "After sorting: ";
        ShowArray(arr, size);
        IntCheckTest(arr, size);
        std::cout << "Finish test" << std::endl;
        std::cout << "--------------------------------------------------------------------------------------------------" << std::endl << std::endl;
        delete[] arr;
    }
    std::cout << "FINISH TWO ELEMENT TEST" << std::endl << "@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@" << std::endl << std::endl;
}
void ItnMultipleInputTest(int count) // Тестируем массив заданное количество раз, заполняя его рандомным числом элементов в диапазоне от 0 до 20.
{
    std::cout << "START MULTIPLE INPUT TEST" << std::endl;
    for (int i = 0; i < count; ++i)
    {
        int size = rand()%20;
        IntRundomCountOfElementsTest(size);
    }
    std::cout << "FINISH MULTIPLE INPUT TEST" << std::endl << "@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@" << std::endl << std::endl;
}




int main()
{
    srand(time(NULL)); // Привязываем функцию генерации случайных чисел ко времени.

    //Запускаем тесты.
    IntEmptyTest();
    IntOneElementTest();
    IntTwoElementsTest();
    ItnMultipleInputTest(3);
}
