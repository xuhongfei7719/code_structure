#include <opencv2/opencv.hpp>
#include <opencv2/xfeatures2d.hpp>
//#include <opencv2/>

using namespace std;
using namespace cv;

int main()
{
	cv::Mat imageL = cv::imread("D:\\configuration\\opencv\\sources\\samples\\data\\aloeL.jpg");
	cv::Mat imageR = cv::imread("D:\\configuration\\opencv\\sources\\samples\\data\\aloeR.jpg");
	/*imshow("1", imageL);
	imshow("2", imageR);
	waitKey();
	return 0;*/



	//��ȡ�����㷽��
	//SIFT
	cv::Ptr<cv::xfeatures2d::SIFT> sift = cv::xfeatures2d::SIFT::create();
	//ORB
	//cv::Ptr<cv::ORB> orb = cv::ORB::create();
	//SURF
	//cv::Ptr<cv::xfeatures2d::SURF> surf = cv::xfeatures2d::SURF::create();

	//������
	std::vector<cv::KeyPoint> keyPointL, keyPointR;
	//������ȡ������
	sift->detect(imageL, keyPointL);
	sift->detect(imageR, keyPointR);

	//��������
	cv::Mat keyPointImageL;
	cv::Mat keyPointImageR;
	drawKeypoints(imageL, keyPointL, keyPointImageL, cv::Scalar::all(-1), cv::DrawMatchesFlags::DRAW_RICH_KEYPOINTS);
	drawKeypoints(imageR, keyPointR, keyPointImageR, cv::Scalar::all(-1), cv::DrawMatchesFlags::DRAW_RICH_KEYPOINTS);

	//��ʾ����
	cv::namedWindow("KeyPoints of imageL");
	cv::namedWindow("KeyPoints of imageR");

	//��ʾ������
	cv::imshow("KeyPoints of imageL", keyPointImageL);
	cv::imshow("KeyPoints of imageR", keyPointImageR);

	//������ƥ��
	cv::Mat despL, despR;
	//��ȡ�����㲢��������������
	sift->detectAndCompute(imageL, cv::Mat(), keyPointL, despL);
	sift->detectAndCompute(imageR, cv::Mat(), keyPointR, despR);

	//Struct for DMatch: query descriptor index, train descriptor index, train image index and distance between descriptors.
	//int queryIdx �C>�ǲ���ͼ����������������� descriptor �����±꣬ͬʱҲ����������Ӧ�����㣨keypoint)���±ꡣ
	//int trainIdx �C> ������ͼ������������������±꣬ͬ��Ҳ����Ӧ����������±ꡣ
	//int imgIdx �C>�������Ƕ���ͼ��Ļ����á�
	//float distance �C>������һ��ƥ�������������������������������ŷ�Ͼ��룬��ֵԽСҲ��˵������������Խ����
	std::vector<cv::DMatch> matches;

	//������� flannBased ���� ��ô despͨ��orb�ĵ������Ͳ�ͬ��Ҫ��ת������
	if (despL.type() != CV_32F || despR.type() != CV_32F)
	{
		despL.convertTo(despL, CV_32F);
		despR.convertTo(despR, CV_32F);
	}

	cv::Ptr<cv::DescriptorMatcher> matcher = cv::DescriptorMatcher::create("FlannBased");
	matcher->match(despL, despR, matches);

	//�����������������ֵ 
	double maxDist = 0;
	for (int i = 0; i < despL.rows; i++)
	{
		double dist = matches[i].distance;
		if (dist > maxDist)
			maxDist = dist;
	}

	//��ѡ�õ�ƥ���
	std::vector< cv::DMatch > good_matches;
	for (int i = 0; i < despL.rows; i++)
	{
		if (matches[i].distance < 0.5 * maxDist)
		{
			good_matches.push_back(matches[i]);
		}
	}



	cv::Mat imageOutput;
	cv::drawMatches(imageL, keyPointL, imageR, keyPointR, good_matches, imageOutput);

	cv::namedWindow("picture of matching");
	cv::imshow("picture of matching", imageOutput);
	cv::waitKey(0);
	return 0;
}
