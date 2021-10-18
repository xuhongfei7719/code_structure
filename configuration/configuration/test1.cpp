#include<opencv2\opencv.hpp>
#include<iostream>

using namespace std;
using namespace cv;

int main()
{
	Mat img;
	img = imread("D:/configuration/opencv/sources/samples/data/baboon.jpg");
	if (img.empty())
	{
		cout << "请确认文件名称" << endl;
		return -1;
		Mat img1;

	}
	
	imshow("test", img);
	waitKey(0);
	return 0;
}