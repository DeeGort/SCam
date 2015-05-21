#pragma once
#include <opencv2\core.hpp>
#include <opencv2\highgui.hpp>
#include <opencv2\imgproc.hpp>
#include "DataParser.h"
using namespace System;

int kezdo = 30;

public ref class Observer
{
public:
	Observer(array<String ^> ^args) :
		dataParser(args)
	{
	}

	void kivon(const cv::Mat& alapKep, const cv::Mat& img, cv::Mat& dest, cv::Mat& maszk)
	{
		int vagas = kezdo;
		maszk = cv::Mat(alapKep.size(), CV_8UC1);
		maszk.setTo(0);
		int fekete = 0, feher = 0;
		dest = alapKep - img;

		for (int i = 0; i < alapKep.rows; ++i)
		{
			for (int j = 0; j < alapKep.cols; ++j)
			{
				if (dest.at<uchar>(i, j) <= vagas)
				{
					feher++;
				}
				else
				{
					maszk.at<uchar>(i, j) = img.at<uchar>(i, j);
					fekete++;
				}
			}
		}
		threshold(dest, dest, vagas, 255, cv::THRESH_BINARY);
		//cout << fekete << "\t" << feher << endl;
	}

	void kontur(const cv::Mat& img, cv::Mat& dest)
	{
		dest = cv::Mat(img.size(), CV_8UC3);
		dest.setTo(cv::Scalar(0, 0, 0));

		std::vector<std::vector<cv::Point>> contours;
		std::vector<cv::Vec4i> hierarchy;

		findContours(img, contours, hierarchy, cv::RETR_TREE, cv::CHAIN_APPROX_NONE);

		for (size_t i = 0; i < contours.size(); ++i)
		{
			if (hierarchy[i][3] == -1)
			{
				drawContours(dest, contours, i, cv::Scalar(0, 255, 0), 3, 8, hierarchy);
			}
		}
	}

	void marge(const cv::Mat& img, const cv::Mat& contur, cv::Mat& dest)
	{
		cv::Mat tmp;
		dest = cv::Mat(img.size(), CV_8UC3);
		cvtColor(img, tmp, cv::COLOR_GRAY2BGR);

		for (int i = 0; i < img.rows; ++i)
		{
			for (int j = 0; j < img.cols; ++j)
			{
				if (contur.at<cv::Vec3b>(i, j)[1] == 255)
				{
					dest.at<cv::Vec3b>(i, j)[0] = 0;
					dest.at<cv::Vec3b>(i, j)[1] = 255;
					dest.at<cv::Vec3b>(i, j)[2] = 0;
				}
				else
				{
					dest.at<cv::Vec3b>(i, j) = tmp.at<cv::Vec3b>(i, j);
				}
			}
		}



	}


	void run()
	{
		/*/
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

		*/
		// cv::VideoCapture cap(0);
		cv::Mat frame;
		cv::Mat img, alapKep;
		bool alap = true, exit = false;
		int kesleltet = 0;


		/*készített kép mátrixok*/
		cv::Mat kivont, maszk, konturMat, margeMat;

		cv::namedWindow("marge", 1);

		cv::createTrackbar("Threshold", "marge", &kezdo, 255);

		for (;;)
		{
			if (cv::waitKey(10))
				kesleltet++;
			// cap >> frame;

			frame = dataParser.next();
			if (frame.empty())
			{
				std::cout << "A rendszer nem talál webkamerát!" << std::endl;
				break;
			}
			if (kesleltet <= 10)
			{
				continue;
			}

			frame.copyTo(img);

			// cvtColor(img, img, cv::COLOR_BGR2GRAY);

			cv::Mat gaussImg;
			GaussianBlur(img, gaussImg, cv::Size(5, 5), 2.0, 2.0);

			//imshow("Mozgás", img);

			char key = cv::waitKey(100);

			switch (key)
			{
			case 'z':
				std::cout << "lenyomott z" << std::endl;
				alap = true;
				break;
			case 'e':
				std::cout << "e" << std::endl;
				exit = true;
			default:
				break;
			}

			if (exit)
			{
				break;
			}

			if (alap == true)
			{
				img.copyTo(alapKep);
				alap = false;
			}
			//imshow("Alap Kép", alapKep);

			kivon(alapKep, img, kivont, maszk);
			//imshow("Kivont", kivont);
			//imshow("Maszk", maszk);

			medianBlur(maszk, maszk, 5);
			//imshow("maszk2", maszk);
			kontur(maszk, konturMat);
			//imshow("kontur", konturMat);


			marge(img, konturMat, margeMat);
			imshow("marge", margeMat);
		}
	}

private:
	DataParser dataParser;
};