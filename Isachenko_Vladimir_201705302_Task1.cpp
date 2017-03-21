#include "Isachenko_Vladimir_201705302_Task1.h"
#include <stdexcept>
#include <utility>

namespace mvms_2017
{

	void Isachenko_Vladimir_201705302_Task1::drawpixel(cv::Mat & img, int x, int y, int color = WHITE)
	{
		if (x < img.rows && y < img.cols)
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

	cv::Mat Isachenko_Vladimir_201705302_Task1::drawCircle(std::string filename, float x, float y, float r)
	{
		cv::Mat img = cv::imread(filename);

		cv::circle(img, cv::Point(50, 50), 15, cv::Scalar(0), -1);

		int r1 = (int)(r + 0.5), x1 = (int)(x + 0.5), y1 = (int)(y + 0.5);
		int cx = 0, cy = r1;
		int delta = 1 - 2 * r1, error = 0;
		while (cy >= 0)
		{
			drawpixel(img, x1 + cx, y1 + cy);
			drawpixel(img, x1 + cx, y1 - cy);
			drawpixel(img, x1 - cx, y1 + cy);
			drawpixel(img, x1 - cx, y1 - cy);
			error = 2 * (delta + cy) - 1;
			if ((delta < 0) && (error <= 0))
			{
				delta += 2 * ++cx + 1;
				continue;
			}
			error = 2 * (delta - cx) - 1;
			if ((delta > 0) && (error > 0))
			{
				delta += 1 - 2 * --cy;
				continue;
			}
			cx++;
			delta += 2 * (cx - cy);
			cy--;
		}

		return img;
	}
}
