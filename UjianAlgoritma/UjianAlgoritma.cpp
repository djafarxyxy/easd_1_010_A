//1. The efficiency of an algorithm can be improved by using an appropriate data structure. 
//2. static and dynamic
//3. -Speed of the machine
//   -Compiler				
//   -Operating system
//   -Programming language
//   -Input data
//4. algoritma insert sort
//5. struct

#include <iostream>
using namespace std;

int Han[30];
int cmp_count = 0;
int mov_count = 0;
int n;

void input() {
	while (true)
	{
		cout << "masukan panjang element array: ";
		cin >> n;

		if (n <= 30)
			break;
		else
			cout << "\nMaksimum panjang array adalah 20" << endl;
	}

	cout << "\n____________________" << endl;
	cout << "\nEnter Array Element" << endl;
	cout << "\n____________________" << endl;

	for (int i = 0; i < n; i++)
	{
		cout << "<" << (i + 1) << ">";
		cin >> Han[i];
	}
}

void swap(int x, int y)
{
	int temp;

	temp = Han[x];
	Han[x] = Han[y];
	Han[y] = temp;
}

void m_sort(int low, int high)
{
	int pivot, i, j;
	if (low > high) {		
		return;
	}
	

	pivot = Han[low];		

	i = low + 1;		
	j = high;	


	while (i <= j)		
	{
		
		while ((Han[i] <= pivot) && (i <= high))		
		{
			i++;
			cmp_count++;
		}
		cmp_count++;
		
		while ((Han[j] > pivot) && (j >= low))
		{
			j--;
			cmp_count++;
		}
		cmp_count++;

		
		if (i < j)					
		{
			
			swap(i, j);
			mov_count++;
		}
	}
	
	if (low < j)		
	{
		
		swap(low, j);
		mov_count++;
	}
	
	m_sort(low, j - 1);		 

	
	m_sort(j + 1, high);	
}

void display() {
	cout << "\n___________________" << endl;
	cout << "Sorted Array" << endl;
	cout << "___________________" << endl;

	for (int i = 0; i < n; i++)
	{
		cout << Han[i] << " ";
	}

	cout << "\n\nNumber of comparasion : " << cmp_count << endl;
	cout << "Number of data movements: " << mov_count << endl;
}

int main()
{

	input();
	
	m_sort(0, n - 1);
	display();
	system("pause");

	return 0;
}
