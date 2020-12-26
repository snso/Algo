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
*   获取当前秒
*/
double CVzTimeUtils::GetElapsedSecond()
{
	return GetElapsedTimeInMicroSec() * 0.000001;
}

/**
*   获取毫秒
*/
double CVzTimeUtils::GetElapsedTimeInMilliSec()
{
	return GetElapsedTimeInMicroSec() * 0.001;
}

/**
*   获取微妙
*/
long long CVzTimeUtils::GetElapsedTimeInMicroSec()
{
	return std::chrono::duration_cast<std::chrono::microseconds>(std::chrono::high_resolution_clock::now() - m_begin).count();
}