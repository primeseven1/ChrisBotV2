#include "./valid.h"

bool valid(char* scramble_array, size_t i)
{
    if (!scramble_array)
        return true;

    // The current and previous move cannot be the same
    if (i && scramble_array[i - 1] == scramble_array[i])
        return false;

    // Removes things like "D U2 D" or "R L R'"
    if (i > 1 && scramble_array[i] == scramble_array[i - 2]) {
        if ((scramble_array[i] == 'U' && scramble_array[i - 1] == 'D') || (scramble_array[i] == 'D' && scramble_array[i - 1] == 'U') ||
            (scramble_array[i] == 'R' && scramble_array[i - 1] == 'L') || (scramble_array[i] == 'L' && scramble_array[i - 1] == 'R') ||
            (scramble_array[i] == 'F' && scramble_array[i - 1] == 'B') || (scramble_array[i] == 'B' && scramble_array[i - 1] == 'F'))
            return false;
    }

    return true;
}