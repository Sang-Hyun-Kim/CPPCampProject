#pragma once
class Zoo
{
private:
	int idx = 0;
	class Animal* animals[10] = {nullptr,};
	// �迭 �����Ҵ����� �߰��ϴ� ��� ���� �ִ� ũ�� ���� �� �Է��ϰ� �Ǹ� 
	// �߰��� �ź��ϸ鼭 ���ÿ� �ܺ� �ڵ忡�� ������ heap ������ ���� ���� ó���� �ϴ� �ڵ��
	// ������
public:
	Zoo() {};
	~Zoo();
	void addAnimal(Animal* _animal);
	void performActions();

};

