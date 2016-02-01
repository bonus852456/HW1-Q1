

#include "stdafx.h"
#include <iostream>
#include <opencv2\opencv.hpp>

using namespace cv;
using namespace std;

int main(){
	enum{ ORIGIN, BLUE, GREEN, RED };
	cv::Mat image;
	image = cv::imread("../image/aleng.jpg");   // Read the file
	uchar *pixptr;
	int a;
	float b;
	if (image.empty()){
		std::cout << "圖片不見了QQ";
		system("pause");
		return 0;
	}
	cout << "Whitch colar you would like to change?  (ORIGIN=0,BLUE=1,GREEN=2,RED=3)\n";
	cin >> a;
	switch (a)
	{
	case ORIGIN:

		for (int i = 0; i<image.rows; i++){
			pixptr = image.ptr<uchar>(i);
			for (int j = 0; j<image.cols; j++){
				pixptr[0] = pixptr[0] * 1;
				pixptr[1] = pixptr[1] * 1;
				pixptr[2] = pixptr[2] * 1;
				pixptr += 3;
			}
		}
		break;
	case BLUE:
		cout << "how much percentage would like blue to be ? (ex : 50 )\n";
		cin >> b;
		b = b / 100;
		for (int i = 0; i<image.rows; i++){
			pixptr = image.ptr<uchar>(i);
			for (int j = 0; j<image.cols; j++){
				pixptr[0] = pixptr[0] * b * 2;
				pixptr[1] = pixptr[1] * (1 - b);
				pixptr[2] = pixptr[2] * (1 - b);
				pixptr += 3;
			}
		}
		break;
	case GREEN:
		cout << "how much percentage would like green to be ? (ex : 50 )\n";
		cin >> b;
		b = b / 100;
		for (int i = 0; i<image.rows; i++){
			pixptr = image.ptr<uchar>(i);
			for (int j = 0; j<image.cols; j++){
				pixptr[0] = pixptr[0] * (1 - b);
				pixptr[1] = pixptr[1] * b * 2;
				pixptr[2] = pixptr[2] * (1 - b);
				pixptr += 3;
			}
		}
		break;
	case RED:
		cout << "how much percentage would like red to be ? (ex : 50 )\n";
		cin >> b;
		b = b / 100;
		for (int i = 0; i<image.rows; i++){
			pixptr = image.ptr<uchar>(i);
			for (int j = 0; j<image.cols; j++){
				pixptr[0] = pixptr[0] * (1 - b);
				pixptr[1] = pixptr[1] * (1 - b);
				pixptr[2] = pixptr[2] * b * 2;
				pixptr += 3;
			}
		}
		break;
	default:
		cout << "sorry,please enter number between 0 to 3 !!";
		break;
	}

	if (a <= 3)
	{
		cv::imwrite("../image/Result1.png", image);
		cv::imshow("Traverse result", image);
		cv::waitKey(0);
	}
	return(0);
}