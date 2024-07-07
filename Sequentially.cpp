#include <iostream>
#include <vector>
#include <chrono> // Do mierzenia czasu

// Funkcja pomocnicza do zamiany dwóch elementów
void swap(int &a, int &b) {
    int temp = a;
    a = b;
    b = temp;
}

// Funkcja partycjonująca
int partition(std::vector<int> &arr, int low, int high) {
    int pivot = arr[high]; // Wybieramy ostatni element jako pivot
    int i = low - 1; // Indeks mniejszego elementu

    for (int j = low; j < high; j++) {
        // Jeśli bieżący element jest mniejszy lub równy pivot
        if (arr[j] <= pivot) {
            i++; // Zwiększamy indeks mniejszego elementu
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    return (i + 1);
}

// Funkcja implementująca Quick Sort
void quickSort(std::vector<int> &arr, int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high); // pi to indeks partycji

        // Sortowanie elementów przed i po partycji
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

// Funkcja do drukowania tablicy
void printArray(const std::vector<int> &arr) {
    for (int i : arr) {
        std::cout << i << " ";
    }
    std::cout << std::endl;
}

int main() {
    int n =100;

std::vector<int> arr(n);
std::srand(std::time(0)); // Ustawienie ziarna losowości

// Inicjalizacja tablicy elementami losowymi
for (int i = 0; i < n; i++) {
    arr[i] = std::rand() % 100; // Losowe liczby od 0 do 99
}
    std::cout << "Original array: ";
    printArray(arr);

    // Mierzenie czasu wykonania quickSort
    auto start = std::chrono::high_resolution_clock::now(); // Start
    quickSort(arr, 0, n - 1);
    auto end = std::chrono::high_resolution_clock::now(); // Koniec

    std::chrono::duration<double> duration = end - start; // Obliczanie czasu trwania
    std::cout << "Sorted array: ";
    printArray(arr);

    std::cout << "Time taken by quickSort: " << duration.count() << " seconds" << std::endl;
    return 0;
}
