#include "Vector.h"
#include <stdio.h>
#include <Windows.h>
#include <iostream>

int main()
{
	WNDCLASSEX wc;
	HWND hwnd;
	


	Vector vector1(10, 5);
	Vector vector2(3, 6);
	Vector vector3 = vector1.AddVector(vector2);

	vector1.Show();
	vector2.Show();
	vector3.Show();

	getchar();
	return 0;
}
