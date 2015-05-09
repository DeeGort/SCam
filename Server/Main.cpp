// Server.cpp : main project file.

#include "stdafx.h"
#include "Sender.h"
using namespace System;
using namespace System::Net;
using namespace System::Net::Sockets;
using namespace System::Text;

int main(array<String ^> ^args)
{
	if (args->Length != 1)
		return 1;

	cv::VideoCapture cap(0); // open the video camera no. 0

	if (!cap.isOpened())  // if not success, exit program
	{
		std::cout << "Cannot open the video cam" << std::endl;
		return 2;
	}

	Sender^ sender = gcnew Sender(args);

	while (true)
	{
		cv::Mat frame;

		bool bSuccess = cap.read(frame); // read a new frame from video

		if (!bSuccess) //if not success, break loop
		{
			std::cout << "Cannot read a frame from video stream" << std::endl;
			break;
		}

		sender->send(frame);
	}
}