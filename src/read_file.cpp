#include <opencv2/opencv.hpp>
#include <iostream>

using namespace cv;
using namespace std;

string path = "/home/yrsn/Dev/cpp/CV/opencv/img/Formas.bmp";
string path_v = "/home/yrsn/Dev/cpp/CV/opencv/video/road.mp4";

void ReadImg(){
    Mat image = imread(path,IMREAD_COLOR);
    imshow("output",image);
    waitKey();
    	// let's downscale the image using new  width and height
	int down_width = 300;
	int down_height = 200;
	Mat resized_down;
	//resize down
	resize(image, resized_down, Size(down_width, down_height), INTER_LINEAR);
	// let's upscale the image using new  width and height
	int up_width = 600;
	int up_height = 400;
	Mat resized_up;
	//resize up
	resize(image, resized_up, Size(up_width, up_height), INTER_LINEAR);
	// Display Images and press any key to continue
	imshow("Resized Down by defining height and width", resized_down);
	waitKey();
	imshow("Resized Up image by defining height and width", resized_up);
	waitKey();
}



void ReadVideo() {
    VideoCapture cap(path_v);
    Mat img;

    while(true){
        cap.read(img);
        imshow("newwindows",img);
        waitKey(20);
    }
}

void ReadWevCam(){
    VideoCapture cap(0);
    Mat img;

    while (true){
        cap.read(img);
        imshow("video",img);
        waitKey(0);
    }

}

int main()
{
    ReadImg();
    //ReadVideo();
    //ReadWevCam();

    destroyAllWindows();
    return 0;
}