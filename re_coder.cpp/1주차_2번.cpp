#include <iostream>
#include <random>
#include <algorithm>
using namespace std;

void sorting(int N, int length, int** sort_arr)
{
	int* temp_arr = new int[length]; 
	int k = 0;

	
	for (int i = 0; i < N; i++)     
	{
		for (int j = 0; j < N; j++)
		{
			temp_arr[k] = sort_arr[i][j];
			k++;
		}
	}


	int temp;

	for (int i = 0; i < length; i++)       
	{
		for (int j = length; j > i; j--)
		{
			if (temp_arr[j] < temp_arr[j - 1])
			{
				temp = temp_arr[j - 1];
				temp_arr[j - 1] = temp_arr[j];
				temp_arr[j] = temp;
			}
		}
	}


	int k = 0;

	for (int i = 0; i < N; i++)     
	{
		for (int j = 0; j < N; j++)
		{
			sort_arr[i][j] = temp_arr[k];
			cout << sort_arr[i][j] << "	";
			k++;
		}
		cout << endl;
	}

	delete[] temp_arr;            

	return;
}




int main(void)
{
	int N = 0;

	cout << "Array Size(0<N<11): ";
	cin >> N;
	int arr_length = N * N;
	int** arr = new int* [N];
	for (int i = 0; i < N; i++)
		arr[i] = new int[N];

	std::random_device rd; // �õ尪�� ��� ���� random_device ����
	std::mt19937 mersenne(rd()); // random_device�� ���� ���� ���� ���� �ʱ�ȭ
	std::uniform_int_distribution<> range(1, 100); // 1���� 1000���� �յ��ϰ� ��Ÿ���� ������ ������ ���� �յ� ���� ����

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			arr[i][j] = range(mersenne);
			cout << arr[i][j] << "	";
		}
		cout << endl;
	}
	cout << endl;

	sorting(N, arr_length, arr);

	for (int i = 0; i < N; i++)
	{
		delete[] arr[i];
	}
	delete[] arr;

	return 0;
}

//for (int i = 0; i < N; i++)
//{
//	for (int k = 1; k < N; k++)
//	{
//		for (int j = 0; j < N - k; j++)
//		{
//			//if (j == 0 && i != 0)
//			//{
//			//	if (*(*(sort_arr + i) + j) < *(*(sort_arr + i - 1) + N - 1))
//			//	{
//			//		int temp = *(*(sort_arr + i) + j);
//			//		*(*(sort_arr + i) + j) = *(*(sort_arr + i - 1) + N - 1);
//			//		*(*(sort_arr + i - 1) + N - 1) = temp;
//			//	}
//			//}
//
//			if (*(*(sort_arr + i) + j) > *(*(sort_arr + i) + j + 1))
//			{
//				if (j == 0 && i != 0)
//				{
//					if (*(*(sort_arr + i) + j) < *(*(sort_arr + i - 1) + N - 1))
//					{
//						int temp = *(*(sort_arr + i) + j);
//						*(*(sort_arr + i) + j) = *(*(sort_arr + i - 1) + N - 1);
//						*(*(sort_arr + i - 1) + N - 1) = temp;
//					}
//				}
//				int temp = *(*(sort_arr + i) + j);
//				*(*(sort_arr + i) + j) = *(*(sort_arr + i) + j + 1);
//				*(*(sort_arr + i) + j + 1) = temp;
//			}
//		}
//	}
//}
//return;