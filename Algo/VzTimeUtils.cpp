#include "VzTimeUtils.h"

CVzTimeUtils::CVzTimeUtils()
{
}


CVzTimeUtils::~CVzTimeUtils()
{
}

void CVzTimeUtils::Update()
{
	m_begin = std::chrono::high_resolution_clock::now();
}

/**
*   ��ȡ��ǰ��
*/
double CVzTimeUtils::GetElapsedSecond()
{
	return GetElapsedTimeInMicroSec() * 0.000001;
}

/**
*   ��ȡ����
*/
double CVzTimeUtils::GetElapsedTimeInMilliSec()
{
	return GetElapsedTimeInMicroSec() * 0.001;
}

/**
*   ��ȡ΢��
*/
long long CVzTimeUtils::GetElapsedTimeInMicroSec()
{
	return std::chrono::duration_cast<std::chrono::microseconds>(std::chrono::high_resolution_clock::now() - m_begin).count();
}