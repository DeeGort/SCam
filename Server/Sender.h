#pragma once
#include <opencv2\core.hpp>
#include <opencv2\highgui.hpp>
#include <opencv2\imgproc.hpp>
#include <iostream>
#include <vector>
#define BUFFERSIZE 512
using namespace System;


public ref class Sender
{
public:
	Sender(array<String ^> ^args) :
		server(gcnew Server(Int32::Parse(args[0])))
	{}

	void send(cv::Mat _img)
	{
		cv::Mat img;
		cv::cvtColor(_img, img, CV_RGB2GRAY);

		// Send title
		Console::WriteLine(server->recieve());
		server->send("SIZE");																	server->recieve();
		server->send(Int32(BUFFERSIZE).ToString());												server->recieve();
		server->send(Int32(img.rows).ToString());												server->recieve();
		server->send(Int32(img.cols).ToString());												server->recieve();
		server->send("BEGIN");																	server->recieve();

		// Send image
		// This is the cool part		
		uchar * bytes = matToBytes(img);				// Create bytes based array
		int size = img.cols * img.rows;
		int maxit =	size / BUFFERSIZE;
		int mod =	size % BUFFERSIZE;
		uchar buffer[BUFFERSIZE];
		int i = 0;
		while (i < maxit * BUFFERSIZE) {
			std::memcpy(buffer, &bytes[i], BUFFERSIZE * sizeof(uchar));
			server->send(makeManagedArray(buffer, BUFFERSIZE));									server->recieve();
			i += BUFFERSIZE;
		}
		memset(buffer, 0, BUFFERSIZE);
		std::memcpy(buffer, &bytes[i], mod * sizeof(uchar));
		server->send(makeManagedArray(buffer, mod));										server->recieve();
		delete [] bytes;
		bytes = nullptr;
		
		server->send("END");																	server->recieve();
	}

	uchar * matToBytes(cv::Mat image)
	{
		int size = image.total() * image.elemSize();
		uchar * bytes = new uchar[size]; 
		std::memcpy(bytes, image.data, size * sizeof(uchar));
		return bytes;
	}

	array<uchar>^ makeManagedArray(unsigned char* input, int len)
	{
		array<uchar>^ result = gcnew array<uchar>(len);
		for (int i = 0; i < len; i++)
		{
			result[i] = input[i];
		}
		return result;
	}

private:
	Server ^ server;
};