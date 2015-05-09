#pragma once
#include <opencv2\core.hpp>
#include <opencv2\highgui.hpp>
#include <opencv2\imgproc.hpp>
#include <iostream>
#include "Client.h"


public ref class DataParser
{
public:
	DataParser(array<String ^> ^args):
		client(gcnew Client(args[0], Int32::Parse(args[1]))),
		img(nullptr)
	{ }

	cv::Mat next()
	{
		client->send("NEW REQUEST");
		client->recieveString();
		client->send("OK");
		buffersize = Int32::Parse(client->recieveString());		client->send("OK");
		rows = Int32::Parse(client->recieveString());			client->send("OK");
		cols = Int32::Parse(client->recieveString());			client->send("OK");
		client->recieveString();
		client->send("BEGIN");

		if (img != nullptr)
		{
			delete img;
			img = nullptr;
		}
		if (imgvec != nullptr)
		{
			delete[] imgvec;
			imgvec = nullptr;
		}

		int size = rows * cols;
		int mod = size % buffersize;

		imgvec = new uchar[size];
		memset(imgvec, 255, size);

		int buffercounter = 0;
		while (true)
		{
			array<unsigned char>^ line = client->recieveArray();
			client->send("OK");

			int currentbuffersize = (size - mod > buffersize * buffercounter ? buffersize : mod);

			for (int i = 0; i < currentbuffersize; i++)
				imgvec[i + (buffercounter * buffersize)] = line[i];

			if (currentbuffersize < buffersize)
			{
				client->recieveArray();
				client->send("END");

				img = bytesToMat(imgvec, cols, rows);
				return *img;
			}

			buffercounter++;
		}
	}

	cv::Mat * bytesToMat(uchar * bytes, int width, int height)
	{
		return new cv::Mat(height, width, CV_8U, bytes);
	}

private:

	Client^ client;
	int buffersize;
	int rows, cols;
	cv::Mat* img;
	uchar * imgvec;
};