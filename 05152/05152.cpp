#include <iostream>
#include <opencv2/opencv.hpp>
using namespace cv;
using namespace std;
int equalizeMain()
{
	cv::Mat srcMat = imread("D:\\360downloads\\20.jpg", 0);
	cv::Mat dstMat;

	if (srcMat.empty()) {
		cout << "fail" << endl;
		return -1;
	}

	
	
	
	
	// 8位单通道
	//同样尺寸同样类型
	if (srcMat.type() == CV_8UC1) {
		equalizeHist(srcMat, dstMat);
	}
	else if (srcMat.type() == CV_8UC3) {
		Mat channel[3];
		Mat out[3];
		split(srcMat, channel);

		for (int i = 0; i < 3; i++) {
			equalizeHist(channel[i], out[i]);
		}

		merge(out, 3, dstMat);

	}


	//绘制直方图
	float srcHist[256];
	float dstHist[256];

	cv::Mat srcHistMat;
	cv::Mat dstHistMat;
	imshow("srcMat", srcMat);
	imshow("dstMat", dstMat);

	waitKey(0);

	destroyAllWindows();

	return 0;

}
int main()
{
	//计时
	double start = static_cast<double>(cvGetTickCount());
	//直方图
	equalizeMain();
	//结束计时
	double time = ((double)cvGetTickCount() - start) / cvGetTickFrequency();
	//显示时间
	cout << "processing time:" << time / 1000 << "ms" << endl;
	//任意键结束程序
	system("pause");
	return 0;
}