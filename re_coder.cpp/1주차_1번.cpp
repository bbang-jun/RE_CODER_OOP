#include <iostream>
using namespace std; 

int main(void)
{
	int i = 0;
	char input[1000];
	int sum = 0;

	// cin.getline�� ���� �Է�(cin���� ������ ���ۿ� ���� �����̽� ������ �Է� ������ ���������� �ݿ� x)
	cin.getline(input, sizeof(input));

	cout << input[0];

	// null�� ���� ������(������)
	while (input[i]!='\0')
	{
		if (input[i] == input[i + 1]) // ���� ���ڰ� �������� �� �ÿ� 1�� +
		{
			sum++;
		}
		else // �ٸ� ���ڰ� ���� ���
		{
			cout << sum+1 << input[i+1];  
			sum = 0;
		}
		i++;
	}

	return 0;
}