#include "Isachenko_Vladimir_201705302_Task1.h"
#include <stdexcept>
#include <utility>

namespace mvms_2017
{

	void Isachenko_Vladimir_201705302_Task1::drawpixel(cv::Mat & img, int x, int y, int color = WHITE)
	{
		if (x >= 0 && y >= 0 && x < img.rows && y < img.cols)
		{
			cv::Vec3b pixel = img.at<cv::Vec3b>(cv::Point(x, y));
			pixel[0] = color;
			pixel[1] = color;
			pixel[2] = color;
			img.at<cv::Vec3b>(cv::Point(x, y)) = pixel;
		}
	}

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

	/*Bresenham's circle drawing algorithm*/
	cv::Mat Isachenko_Vladimir_201705302_Task1::drawCircle(std::string filename, float x, float y, float r)
	{
		cv::Mat img = cv::imread(filename);

		int radius = (int)(r + 0.5), center_x = (int)(x + 0.5), center_y = (int)(y + 0.5);
		int dx[] = { 1, 1, -1, -1 };
		int dy[] = { 1, -1, -1, 1 };

		int cur_x = 0, cur_y = radius;
		int delta = 1 - 2 * radius, error = 0;
		while (cur_y >= 0)
		{
			for (int i = 0; i < 4; i++)
			{
				drawpixel(img, center_x + dx[i] * cur_x, center_y + dy[i] * cur_y);
			}
			
			error = 2 * (delta + cur_y) - 1;
			if ((delta < 0) && (error <= 0))
			{
				cur_x++;
				delta += 2 * cur_x + 1;
				continue;
			}
			error = 2 * (delta - cur_x) - 1;
			if ((delta > 0) && (error > 0))
			{
				cur_y--;
				delta += 1 - 2 * cur_y;
				continue;
			}
			cur_x++;
			delta += 2 * (cur_x - cur_y);
			cur_y--;
		}
		return img;
	}
}
