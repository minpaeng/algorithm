#include <iostream>
using namespace std;

int n;

void f(int cnt) {
	if (cnt == n) {
		for (int i = 0; i < cnt * 4; i++) cout << '_';
		cout << "\"����Լ��� ������?\"\n";
		for (int i = 0; i < cnt * 4; i++) cout << '_';
		cout << "\"����Լ��� �ڱ� �ڽ��� ȣ���ϴ� �Լ����\"\n";
		for (int i = 0; i < cnt * 4; i++) cout << '_';
		cout << "��� �亯�Ͽ���.\n";
		return;
	}
	for (int i = 0; i < cnt * 4; i++) cout << '_';
	cout << "\"����Լ��� ������?\"\n";
	for (int i = 0; i < cnt * 4; i++) cout << '_';
	cout << "\"�� ����. �������� �� �� ����⿡ �̼��� ��� ������ ����� ������ �־���.\n";
	for (int i = 0; i < cnt * 4; i++) cout << '_';
	cout << "���� ������� ��� �� ���ο��� ������ ������ �߰�, ��� �����Ӱ� ����� �־���.\n";
	for (int i = 0; i < cnt * 4; i++) cout << '_';
	cout << "���� ���� ��κ� �ǾҴٰ� �ϳ�. �׷��� ��� ��, �� ���ο��� �� ���� ã�ƿͼ� ������.\"\n";
	f(cnt + 1);
	for (int i = 0; i < cnt * 4; i++) cout << '_';
	cout << "��� �亯�Ͽ���.\n";
}
int main() {
	cin >> n;
	cout << "��� �� ��ǻ�Ͱ��а� �л��� ������ �������� ã�ư� ������.\n";
	f(0);
	return 0;
}