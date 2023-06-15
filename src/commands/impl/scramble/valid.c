#include "./valid.h"

bool valid(char* scramble_array, uint8_t i)
{
	if (!scramble_array)
		return true;

	if (i && scramble_array[i - 1] == scramble_array[i]) 
        return false;

	if (i > 1 && scramble_array[i] == scramble_array[i - 2])
	{
		if ((scramble_array[i] == 'U' && scramble_array[i - 1] == 'D') || (scramble_array[i] == 'D' && scramble_array[i - 1] == 'U') ||
			(scramble_array[i] == 'R' && scramble_array[i - 1] == 'L') || (scramble_array[i] == 'L' && scramble_array[i - 1] == 'R') ||
			(scramble_array[i] == 'F' && scramble_array[i - 1] == 'B') || (scramble_array[i] == 'B' && scramble_array[i - 1] == 'F')) 
                return false;
	}

	return true;
}