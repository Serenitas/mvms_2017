#pragma once
#include "task1.h"

namespace mvms_2017
{
	class Strekalova_Svetlana_201700221_Task1 : public Task1
	{
	private:
		void drawPoint(int x, int y, cv::Mat& img, int color);

	public:
		Strekalova_Svetlana_201700221_Task1();
		Strekalova_Svetlana_201700221_Task1(bool verbose);

		int variant() override;
		std::string getFirstName() override;
		std::string getSecondName() override;

		cv::Mat drawCircle(std::string filename, float x, float y, float r) override;
	};
}
