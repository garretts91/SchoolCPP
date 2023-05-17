// InsertionSort.cpp
// https://www.youtube.com/watch?v=8oJS1BMKE64

#include <iostream>

void insertionSortAscending(int arr[], int size)
{
    int i, j, key;
    // iterate through the array, starting at position 1
    for (i = 1; i < size; i++)
    {
        // key is the current item, we need to determine if it should move
        key = arr[i];

        // j is the previous index and will allow us to shift items forward
        j = i - 1;

        // Shift everything from arr[0..i-1] that is greater than the key
        // No if's req'd as this guarantees everything ahead is already sorted
        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

void insertionSortDescending(int arr[], int size)
{
    int i, j, key;
    for (i = 1; i < size; i++)
    {
        key = arr[i];
        j = i - 1;
        while (j >= 0 && arr[j] < key)
        {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

void print(int arr[], int n)
{
    for (int i = 0; i < n; i++)
        std::cout << arr[i] << " ";
    std::cout << '\n';
}

enum COLORS {
    NC = -1,
    BLACK,
    RED,
    GREEN,
    YELLOW,
    BLUE,
    MAGENTA,
    CYAN,
    WHITE,
};

const char* colorize(int font, int back = -1, int style = -1) {
    static char code[20];

    if (font >= 0)
        font += 30;
    else
        font = 0;
    if (back >= 0)
        back += 40;
    else
        back = 0;

    if (back > 0 && style > 0) {
        sprintf_s(code, "\033[%d;%d;%dm", font, back, style);
    }
    else if (back > 0) {
        sprintf_s(code, "\033[%d;%dm", font, back);
    }
    else {
        sprintf_s(code, "\033[%dm", font);
    }
    return code;
}

int main()
{
    int numbers[] = { 9, 0, 5, 3, 8, 1, 17, 4, 6, 7, 10, 2, 20, 11, 19, 13, 12, 14, 18, 16, 15 };
    int size = sizeof(numbers) / sizeof(numbers[0]);

    insertionSortDescending(numbers, size);

    std::cout << colorize(GREEN, BLACK);
    print(numbers, size);

    return 0;
}