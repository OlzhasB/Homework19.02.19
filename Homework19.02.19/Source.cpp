#include<iostream>
using namespace std;

void fillArray(int *a, int n)
{
	for (int i = 0; i < n; i++)
	{
		a[i] = 1 + rand() % 20;
	}
}

void printArray(int *a, int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << a[i] << "  ";
	}
	cout << endl;
}

void sortArray(int *a, int n)
{
	for (int i = 0; i < n - 1; i++)
	{
		for (int j = n - 2; j >= i; j--)
		{
			if (a[j] > a[j + 1])
				swap(a[j], a[j + 1]);
		}
	}
}

void FindP(int *a, int n, int num)
{
	int *p = a, indexM = -1, indexL = 0;
	for (; p < a + n; p++)
	{
		if (*p < num)
		{
			indexL = p - a;
		}
		else if (*p > num)
		{
			indexM = p - a;
			break;
		}
	}
	if (indexM == -1) cout << "All the numbers in array are less than number " << num << endl;
	else if (indexM == 0) cout << "All the numbers in array are more than number " << num << endl;
	else if ((n - indexM) < indexL + 1)
		cout << "Amount of numbers less than " << num << " is greater:" << endl << (indexL + 1) << endl;
	else if (n - indexM == indexL + 1)
		cout << "Amount of numbers less than " << num << " is equal to numbers more than it:" << endl << n - indexM << endl;
	else cout << "Amount of numbers more than " << num << " is greater" << endl << n - indexM << endl;
}

void sumPK(int *a, int n, int P, int K)
{
	int *p = a, indexP = -1, indexK = -1;
	int *p1 = a, sum = 0;
	if (P >= K)
	{
		cout << "Invalid boarders" << endl;
	}
	else
	{
		for (; p < a + n; p++)
		{
			if (*p >= P)
			{
				indexP = p - a;
				break;
			}
		}
		for (; p < a + n; p++)
		{
			if (*p <= K)
				indexK = p - a;
			else break;
		}
		if (indexP == -1 || indexK == -1)
		{
			cout << "There is no numbers in this range" << endl;
		}
		else
		{
			for (p1 = a + indexP; p1 <= a + indexK; p1++)
			{
				sum += *p1;
			}
			cout << "Sum of the elements between numbers " << P << " and " << K << " is " << sum << endl;
		}
	}

}

void task1()
{
	/*11. Используя указатели в упорядоченном по возрастанию массиве выяснить, 
	что больше элементов со значением > Р или элементов со значением < Р.*/
	int a[10] = { 0 };
	fillArray(a, 10);
	sortArray(a, 10);
	printArray(a, 10);
	int p;
	cout << "Write any number: ";
	cin >> p;
	FindP(a, 10, p);
}

void task2()
{
	/*12. Используя указатели в упорядоченном по возрастанию массиве подсчитать сумму элементов,
	расположенных за элементом со значением Р и до элемента со значением К ( Р > К ).*/
	int a[10] = { 0 };
	fillArray(a, 10);
	sortArray(a, 10);
	printArray(a, 10);
	int p, k;
	cout << "Write the left boarder: ";
	cin >> p;
	cout << "Write the right boarder: ";
	cin >> k;
	sumPK(a, 10, p, k);
}

int main()
{
	int a, flag;
	do
	{
		cout << "Write the number of task: ";
		cin >> a;
		switch (a)
		{
		case 1:
		{
		task1();
		break;
		}
		case 2:
		{
			task2();
			break;
		}
		}
		cout << "Do you want to continue? 1 / 0: ";
		cin >> flag;
	} while (flag == 1);
	
	system("pause");
}