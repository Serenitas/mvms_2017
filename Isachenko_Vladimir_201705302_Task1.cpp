#include "Isachenko_Vladimir_201705302_Task1.h"
#include <stdexcept>
#include <utility>

namespace mvms_2017
{
	Isachenko_Vladimir_201705302_Task1::Isachenko_Vladimir_201705302_Task1()
		: Isachenko_Vladimir_201705302_Task1(true)
	{

	}

	Isachenko_Vladimir_201705302_Task1::Isachenko_Vladimir_201705302_Task1(bool verbose)
		: Task1(verbose)
	{

	}

	int Isachenko_Vladimir_201705302_Task1::variant()
	{
		return VARIANT_NUMBER;
	}

	std::string Isachenko_Vladimir_201705302_Task1::getFirstName()
	{
		return FIRST_NAME;
	}

	std::string Isachenko_Vladimir_201705302_Task1::getSecondName()
	{
		return LAST_NAME;
	}

	cv::Mat Isachenko_Vladimir_201705302_Task1::drawCircle(std::string filename, float x, float y, float r)
	{
		return cv::Mat();
	}
}
