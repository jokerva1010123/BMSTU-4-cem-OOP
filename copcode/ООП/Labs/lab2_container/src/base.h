//
//		������� ����� �������
//
#pragma once


//����������� ����� �������
class _cArrayBase
{
public:
	//����������� �� ���������
	_cArrayBase();

	//����������� ��������
	_cArrayBase(int s);

	//����������� �����������
	_cArrayBase(_cArrayBase &origin);

	//��������� ������� �������
	int GetSize() const;

	//�������� ������� �� �������
	//bool Empty() const;

protected:
	int size; //������ �������

};