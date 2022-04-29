//
//		��������� ����� �������
//
#pragma once

#include "base.h"

//��������� ����� - ������ ��������� ������������� ����
template<typename T>
class cArray : public _cArrayBase
{
protected:
	T *data; //��������������� ��� ������ ���������

public:
	//����������� �� ���������
	cArray();
	//����������� ��������
	cArray(int n);
	//����������� �������� � ��������������
	cArray(int n, T first, ...);
	//����������� �����������
	cArray(const cArray &origin);

	//����������
	~cArray();


	//��������� ����� �������
	cArray<T> Splice(int start, int len);
	/*
	//������� ��������
	void InsertSingle(const T el, int index);

	//�������� ��������
	void EraseSingle(int index);

	//������� ��������� ������� �������
	void InsertArray(const cArray<T> &arr, int index);

	//�������� ����� �������
	void ErasePart(int start, int len);
	*/

	//������� ��������
	static cArray<T> InsertSingle(const cArray<T> &origin, const T el, int index);

	//�������� ��������
	static cArray<T> EraseSingle(const cArray<T> &origin, int index);

	//������� ��������� ������� �������
	static cArray<T> InsertArray(const cArray<T> &origin, const cArray<T> &arr, int index);

	//�������� ����� �������
	static cArray<T> ErasePart(const cArray<T> &origin, int start, int len);


	//������������� ���������
	T&			operator [] (int i);
	const T&	operator [] (int i) const;
	cArray<T>	operator = (const cArray<T>& right);
	bool		operator == (const cArray<T>& with) const;
	friend cArray<T>	operator + (const cArray<T>& left, const cArray<T>& right)
	{
		int ls = left.GetSize();
		int rs = right.GetSize();
		cArray<T> res(ls+rs);

		for (int i=0; i<ls; i++)
		{
			res[i] = left[i];
		}
		for (int i=0; i<right.GetSize(); i++)
		{
			res[ls+i] = right[i];
		}

		return res;
	} //������������;
};

#include "array.hpp" //���������� �������