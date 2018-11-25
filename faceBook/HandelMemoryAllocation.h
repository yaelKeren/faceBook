#ifndef __HANDELMEMORYALLOCATION_H
#define __HANDELMEMORYALLOCATION_H

#define SIZE 1

class HandelMemAlloc
{
public:
	static void** expendPointerArray(void** &arr, int& arrSize)
	{
		//int currentSize = sizeof(arr) / sizeof(arr[0]);

		int newSize = arrSize * 2;

		if (newSize == 0)
		{
			newSize = SIZE;
		}
		void** newArr = new void*[newSize];

		if (newSize != SIZE)
		{
			for (int i = 0; i < arrSize; i++)
			{
				newArr[i] = arr[i];
				arr[i] = nullptr;
			}
		}
		for (int i = arrSize; i < newSize; i++)
		{
			newArr[i] = nullptr;
		}

		arrSize = arrSize * 2;
		if (arrSize == 0)
		{
			arrSize = SIZE;
		}
		delete[]arr;
		return newArr;


	}
};

#endif