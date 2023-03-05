#include <iostream>
#include <cstdlib>
#include <ctime>
#include <algorithm>

//���������� ���:
int gcd(int num1, int num2) {
	if (num2 == 0)
		return num1;
	return gcd(num2, num1 % num2);
}

//�������� �����:
int rev(int num) {
	int res = 0;
	while (num) {
		res *= 10;
		res += num % 10;
		num /= 10;
	}
	return res;
}

//�������� �������:
template <typename T>
void print_arr(T arr[], const int length) {
	std::cout << "[";
	for (int i = 0; i < length; i++)
		std::cout << arr[i] << ", ";
	std::cout << "\b\b]\n";
}

//���������� ������� ���������� �������:
template <typename T>
void fill_arr(T arr[], const int length, int left, int right) {
	srand(time(NULL));
	for (int i = 0; i < length; i++)
		arr[i] = rand() % (right - left) + left;
}

//���������� ����� �������:
template <typename T>
void rightside_sort(T arr[], const int length) {
	int index = 0;
	for (int i = 0; i < length; i++)
		if (arr[i] < 0) {
			index = i;
			break;
		}
	for (int i = length - 1; i > index + 1; i--)
		for (int j = index + 1; j < i; j++)
			if (arr[j] > arr[j + 1])
				std::swap(arr[j], arr[j + 1]);
}

int main() {
	setlocale(LC_ALL, "Russian");
	
	std::cout << "������� 1\n������� ������ ����� -> ";
	int n11;
	std::cin >> n11;
	std::cout << "������� ������ ����� -> ";
	int n12;
	std::cin >> n12;
	std::cout << gcd(n11, n12) << std::endl;

	std::cout << "\n������� 2\n������� ����� -> ";
	int num2;
	std::cin >> num2;
	std::cout << num2 << " -> " << rev(num2) << std::endl;

	std::cout << "\n������� 3\n����������� ������:\n";
	const int size3 = 10;
	int arr3[size3];
	int m31;
	int m32;
	std::cout << "������ ��������� -> ";
	std::cin >> m31;
	std::cout << "����� ��������� -> ";
	std::cin >> m32;
	fill_arr(arr3, size3, m31, m32);
	print_arr(arr3, size3);
	std::cout << "\n������� ����� �� ������� -> ";
	int n3;
	std::cin >> n3;
	std::cout << "�������� ������ -> ";
	rightside_sort(arr3, size3);
	print_arr(arr3, size3);

	std::cout << "\n������� 4\n ������:";
	const int size4 = 12;
	int arr4[size4];
	int m41;
	int m42;
	std::cout << "������ ��������� -> ";
	std::cin >> m41;
	std::cout << "����� ��������� -> ";
	std::cin >> m42;
	fill_arr(arr4, size4, m41, m42);
	print_arr(arr4, size4);

	return 0;
}