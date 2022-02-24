#include <iostream>
#include <opencv2/opencv.hpp>
#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/highgui/highgui.hpp"

using namespace std;
using namespace cv;

void changeColorMat(Mat &matIn, unsigned char* data, bool isChannelByChannel)
{
    int h = matIn.size[0];
    int w = matIn.size[1];

    uchar *p = data;

	if (isChannelByChannel)
	{
		for (int i = 0; i < h*w; i++)
		{
			*p++ = 0;
		}

		for (int i = 0; i < h*w; i++)
		{
			*p++ = 255;
		}

		for (int i = 0; i < h*w; i++)
		{
			*p++ = 0;
		}
	}
	else
	{
		for (int i = 0; i < h*w; i++)
		{
			*p++ = 0; // Blue / Azul
			*p++ = 255; // Green / Verde
			*p++ = 0; // Red / Rojo
		}
	}


}

bool saveImage( cv::Mat inImage, std::string refImgText = "",int idImg = 0)
{
    std::string imgName = "img_"+ refImgText + std::to_string(idImg)+".jpg";
    return imwrite( imgName.c_str(), inImage );
}

void MatType( Mat inputMat )
{
    int inttype = inputMat.type();

    string r, a;
    uchar depth = inttype & CV_MAT_DEPTH_MASK;
    uchar chans = 1 + (inttype >> CV_CN_SHIFT);
    switch ( depth ) {
        case CV_8U:  r = "8U";   a = "Mat.at<uchar>(y,x)"; break;
        case CV_8S:  r = "8S";   a = "Mat.at<schar>(y,x)"; break;
        case CV_16U: r = "16U";  a = "Mat.at<ushort>(y,x)"; break;
        case CV_16S: r = "16S";  a = "Mat.at<short>(y,x)"; break;
        case CV_32S: r = "32S";  a = "Mat.at<int>(y,x)"; break;
        case CV_32F: r = "32F";  a = "Mat.at<float>(y,x)"; break;
        case CV_64F: r = "64F";  a = "Mat.at<double>(y,x)"; break;
        default:     r = "User"; a = "Mat.at<UKNOWN>(y,x)"; break;
    }
    r += "C";
    r += (chans+'0');
    cout << "Mat is of type " << r << " and should be accessed with " << a << endl;
}

int main(int argc, char **argv) {

	unsigned char* data = NULL;
	unsigned char* dataRGB = NULL;
	unsigned char* dataGray = NULL;

	int wImg = 640, hImg = 480;

	data = new unsigned char[wImg * hImg * 3];
	dataRGB = new unsigned char[wImg * hImg * 3];

	dataGray = new unsigned char[wImg * hImg];
	unsigned char *p = data;

    for (int i = 0; i < wImg*hImg; i++)
    {
		*p++ = 50;
	}

	cv::Mat image, imageRGB, imageGray;

	image = cv::Mat::zeros(hImg, wImg, CV_8UC3);
	imageRGB = cv::Mat::zeros(hImg, wImg, CV_8UC3);

	imageGray = cv::Mat::zeros(hImg, wImg, CV_8UC1);




	//fill color in buffer data

	changeColorMat(image, data, true);
	changeColorMat(imageRGB, dataRGB, false);

	image.data = data;
	imageRGB.data = dataRGB;
	imageGray.data = dataGray;

    while(1)
    {
		cv::imshow("Image", image);
		cv::imshow("ImageRGB", imageRGB);

		cv::imshow("ImageGray", imageGray);


		// Press  ESC on keyboard to exit
		char c = (char)waitKey(1);
		if (c == 27)
			break;
	}

	return 0;
}


