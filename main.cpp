#include "task1.h"
#include "task2.h"
#include "task3.h"
#include "task4.h"
#include "task5.h"

#include "Strekalova_Svetlana_201700221_Task1.h"

int main(int argc, char *argv[])
{
    mvms_2017::Task1 x(true);
    mvms_2017::Task2 x1(true);
    mvms_2017::Task3 x2(true);
    mvms_2017::Task4 x3(true);
    mvms_2017::Task5 x4(true);

	mvms_2017::Strekalova_Svetlana_201700221_Task1 my_class;

	try
	{
        cv::imshow("Task1", my_class.drawCircle("Lenna.png", 220, 220, 205));
		cv::waitKey(0);
    }
	catch(std::exception ex)
	{
        std::cout << ex.what() << std::endl;
    }

    return 0;
}
