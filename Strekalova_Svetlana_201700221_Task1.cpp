#include "Strekalova_Svetlana_201700221_Task1.h"
#include <stdexcept>
#include <utility>
#include <cmath>

namespace mvms_2017
{

	void Strekalova_Svetlana_201700221_Task1::drawPoint(int x, int y, cv::Mat & img, int color = 255)
	{
		if (x >= 0 && y >= 0 && x < img.rows && y < img.cols)
		{
			for (int i = 0; i < 3; i++)
				img.at<cv::Vec3b>(x, y)[i] = color;
		}
	}

	Strekalova_Svetlana_201700221_Task1::Strekalova_Svetlana_201700221_Task1()
		: Strekalova_Svetlana_201700221_Task1(true)
	{

	}

	Strekalova_Svetlana_201700221_Task1::Strekalova_Svetlana_201700221_Task1(bool verbose)
		: Task1(verbose)
	{

	}

	int Strekalova_Svetlana_201700221_Task1::variant()
	{
		return 201700221;
	}

	std::string Strekalova_Svetlana_201700221_Task1::getFirstName()
	{
		return "Svetlana";
	}

	std::string Strekalova_Svetlana_201700221_Task1::getSecondName()
	{
		return "Strekalova";
	}

	cv::Mat Strekalova_Svetlana_201700221_Task1::drawCircle(std::string filename, float x, float y, float r)
	{
		x = round(x), y = round(y), r = round(r);
		cv::Mat image = cv::imread(filename);
		int x0 = r, y0 = 0;
		int radiusError = 1 - x0;
		while (x0 >= y0)
		{
			drawPoint(x0 + x, y0 + y, image);
			drawPoint(y0 + x, x0 + y, image);
			drawPoint(-x0 + x, y0 + y, image);
			drawPoint(-y0 + x, x0 + y, image);
			drawPoint(-x0 + x, -y0 + y, image);
			drawPoint(-y0 + x, -x0 + y, image);
			drawPoint(x0 + x, -y0 + y, image);
			drawPoint(y0 + x, -x0 + y, image);
			y0++;
			if (radiusError < 0)
				radiusError += 2 * y0 + 1;
			else
			{
				x0--;
				radiusError += 2 * (y0 - x0 + 1);
			}
		}
		return image;
	}
}
