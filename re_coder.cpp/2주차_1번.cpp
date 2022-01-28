#include <iostream>
#include <random>
using namespace std;

void Sender();
void Transmission_Process(const char* data);
void Receiver(const char* data);

void Sender()
{
	char send[5];
	int sum = 0;
	char checksum;

	cin >> send;

	cout << "Data: ";
	for (int i = 0; i < 6; i++)
		cout << send[i];

	// �迭 send�� char���̹Ƿ� �ƽ�Ű �ڵ��̱� ������ ���� '0'�� ���� int�� ���� sum�� ����
	for (int i = 0; i < 4; i++)
		sum+=send[i] - '0';

	if (sum > 9)
		sum%=10;

	// sum�� in�� �����̱� ������ ���� '0'�� �������ν� �ƽ�Ű �ڵ�� ����� char�� ���� checksum�� ����
	checksum = sum + '0';

	send[4] = checksum;

	cout << endl << "Send Data: ";
	for (int i = 0; i < 5; i++)
		cout << send[i];

	// �迭 send�� ���ڷ�
	Transmission_Process(send);
}

void Transmission_Process(const char* data)
{
	char transmission[5];
	random_device rd;
	mt19937 mersenne(rd());

	// �Ű������� ���� data�� const�̹Ƿ� ������ �� ���⿡ transmission�̶�� �迭�� ����� ����
	for (int i = 0; i < 5; i++)
		transmission[i] = data[i];

	uniform_int_distribution<> position_range(0, 4);

	// �迭�� ��ġ�� 0���� 4���� ���� ���� ����
	int position = position_range(mersenne);
	
	uniform_int_distribution<> random_range(0, 9);

	// 0���� 9���� ���� ���� ����
	int random = random_range(mersenne);

	// 40%�� Ȯ���� �����ϱ� ���� 0~9���� 10�� �� 0~3 4������ ���
	if (random < 4)
	{
		while (transmission[position] == random + '0')
		{
			transmission[position] = random_range(mersenne) + '0';
		}
	}
	else
		transmission[position] = random + '0';
	cout << endl;

	Receiver(transmission);
}

void Receiver(const char* data)
{
	char receive[5];

	cout << "Received Data: ";

	for (int i = 0; i < 5; i++)
		receive[i] = data[i];

	for(int i=0; i<5; i++)
		cout<<receive[i];
	cout << endl;

	int hap = 0;

	for (int i = 0; i < 4; i++)
		hap += receive[i]-'0';

	if (hap > 9)
		hap %= 10;

	if (receive[4] != hap + '0')
		cout << receive[4] << "!=" << hap << "	" << "Error!";
	else
		cout << receive[4] << "==" << hap << "	" << "Error is not Occured!";

	cout << endl;

}

int main(void)
{
	Sender();

	return 0;
}