//
//		���������� ������� �������� ������
//
#include "stdafx.h"

#include "base.h"

//����������� �� ���������
_cArrayBase::_cArrayBase() : size(0)
{}

//����������� ��������
_cArrayBase::_cArrayBase(int s) : size(s)
{}

//����������� �����������
_cArrayBase::_cArrayBase(_cArrayBase &origin) : size(origin.size)
{}


//�������� ������� �� �������
/*bool _cArrayBase::Empty() const
{	return (size>0);	}*/

//��������� ������� �������
int _cArrayBase::GetSize() const
{	return size;	}