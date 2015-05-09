#pragma once
#include <opencv2\core.hpp>
#include <opencv2\highgui.hpp>
#include <opencv2\imgproc.hpp>
#include "DataParser.h"
using namespace System;

public ref class Observer
{
public:
	Observer(array<String ^> ^args):
		dataParser(args)
	{
	}

	void run()
	{
		while (true)
		{
			cv::Mat img = dataParser.next();

			if (!img.empty())
				cv::imshow("Window", img);

			if (cv::waitKey(30) == 27)
			{
				std::cout << "Esc key is pressed by user" << std::endl;
				break;
			}
		}
	}

private:
	DataParser dataParser;
};