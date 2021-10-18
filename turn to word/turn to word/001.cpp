#include<iostream>
#include <vector>
#include <opencv2/core.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/opencv.hpp>
#include <opencv2/features2d.hpp>
#include <opencv2/xfeatures2d.hpp>
#include <opencv2\imgproc\types_c.h>

using namespace std;
using namespace cv;




const string IMAGEPATH = "C:\\Users\\Sober\\source\\repos\\OpenCV_SFM-master\\OpenCV_SFM-master\\image\\word002.png";//ͼ��·��



void detect(Mat img);//��������


int main(int argc, char** argv)
{
	Mat textImageSrc = imread(IMAGEPATH);
	detect(textImageSrc);

	return 0;
}

Mat preprocess(Mat gray)
{
	//1.Sobel���ӣ�x�������ݶ�
	Mat sobel;
	Sobel(gray, sobel, CV_8U, 1, 0, 3);

	//2.��ֵ��
	Mat binary;
	threshold(sobel, binary, 0, 255, THRESH_OTSU + THRESH_BINARY);

	//3.���ͺ͸�ʴ�������趨
	Mat element1 = getStructuringElement(MORPH_RECT, Size(30, 9));
	//���Ƹ߶����ÿ��Կ��������е����ͳ̶ȣ�����3��4������������ǿ,��Ҳ�����©��
	Mat element2 = getStructuringElement(MORPH_RECT, Size(24, 4));

	//4.����һ�Σ�������ͻ��
	Mat dilate1;
	dilate(binary, dilate1, element2);

	//5.��ʴһ�Σ�ȥ��ϸ�ڣ�����ߵȡ�����ȥ��������ֱ����
	Mat erode1;
	erode(dilate1, erode1, element1);

	//6.�ٴ����ͣ�����������һЩ
	Mat dilate2;
	dilate(erode1, dilate2, element2);

	//7.�洢�м�ͼƬ
	imwrite("binary.jpg", binary);
	imwrite("dilate1.jpg", dilate1);
	imwrite("erode1.jpg", erode1);
	imwrite("dilate2.jpg", dilate2);

	return dilate2;
}


vector<RotatedRect> findTextRegion(Mat img)
{
	vector<RotatedRect> rects;
	//1.��������
	vector<vector<Point>> contours;
	vector<Vec4i> hierarchy;
	findContours(img, contours, hierarchy, RETR_CCOMP, CHAIN_APPROX_SIMPLE, Point(0, 0));

	//2.ɸѡ��Щ���С��
	for (int i = 0; i < contours.size(); i++)
	{
		//���㵱ǰ���������
		double area = contourArea(contours[i]);

		//���С��1000��ȫ��ɸѡ��
		if (area < 1000)
			continue;

		//�������ƣ����ý�С��approxPolyDP�����д��о�
		double epsilon = 0.001*arcLength(contours[i], true);
		Mat approx;
		approxPolyDP(contours[i], approx, epsilon, true);

		//�ҵ���С���Σ��þ��ο����з���
		RotatedRect rect = minAreaRect(contours[i]);

		//����ߺͿ�
		int m_width = rect.boundingRect().width;
		int m_height = rect.boundingRect().height;

		//ɸѡ��Щ̫ϸ�ľ��Σ����±��
		if (m_height > m_width * 1.2)
			continue;

		//����������rect��ӵ�rects������
		rects.push_back(rect);

	}
	return rects;
}

void detect(Mat img)
{
	//1.ת���ɻҶ�ͼ
	Mat gray;
	cvtColor(img, gray, CV_BGR2GRAY);

	//2.��̬ѧ�任��Ԥ�����õ����Բ��Ҿ��ε�����
	Mat dilation = preprocess(gray);

	//3.���Һ�ɸѡ��������
	vector<RotatedRect> rects = findTextRegion(dilation);

	//4.�����߻�����Щ�ҵ�������
	for each (RotatedRect rect in rects)
	{
		Point2f P[4];
		rect.points(P);
		for (int j = 0; j <= 3; j++)
		{
			line(img, P[j], P[(j + 1) % 4], Scalar(0, 255, 0), 2);
		}
	}

	//5.��ʾ��������ͼ��
	imshow("img", img);
	imwrite("imgDrawRect.jpg", img);

	waitKey(0);
}