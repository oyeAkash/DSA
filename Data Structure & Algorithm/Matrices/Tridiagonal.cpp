#include <iostream>
using namespace std;

class LTMatrix
{
private:
	int n;
	int *A;

public:
	LTMatrix(int n)
	{
		this->n = n;
		A = new int[n * (n + 1) / 2];
	}
	~LTMatrix() { delete[] A; }
	void Display();
	void setRowMajor(int i, int j, int x);
	int getRowMajor(int i, int j);
	int getN() { return n; }
};

void LTMatrix::setRowMajor(int i, int j, int x)
{
	if (i<=j)
	{
		int index = ((i * (i - 1)) / 2) + j - 1;
		A[index] = x;
	}
}

int LTMatrix::getRowMajor(int i, int j)
{
	if (i - j == -1)
	{
		int index = ((i * (i - 1)) / 2) + j - 1;
		A[index] = x;
	}
    if(i - j == 0)
    {
        int index = ((i * (i - 1)) / 2) + j - 1;
		A[index] = x;
    }
    if(i - j == 1)
    {
        int index = ((i * (i - 1)) / 2) + j - 1;
		A[index] = x;
    }
    return 0;
}

void LTMatrix::Display()
{
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			if (i - j == 1)
                cout << getRowMajor(i,j) << " ";
            else if(i - j == 0)
                cout << getRowMajor(i,j) << " ";
            else if(i - j == -1)
                cout << getRowMajor(i,j) << " ";
			else
			{
				cout << 0 << " ";
			}
		}
		cout << endl;
	}
}

int main()
{

	LTMatrix rm(4);
	rm.setRowMajor(1, 1, 1);
	rm.setRowMajor(2, 1, 2);
	rm.setRowMajor(2, 2, 3);
	rm.setRowMajor(3, 1, 4);
	rm.setRowMajor(3, 2, 5);
	rm.setRowMajor(3, 3, 6);
	rm.setRowMajor(4, 1, 7);
	rm.setRowMajor(4, 2, 8);
	rm.setRowMajor(4, 3, 9);
	rm.setRowMajor(4, 4, 10);

	rm.Display();
	cout << endl;
	return 0;
}