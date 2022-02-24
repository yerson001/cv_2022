#include <opencv2/opencv.hpp>
#include <iostream>
using namespace std;
using namespace cv;

int main()
{
    VideoCapture cap;

    cap.set(cv::CAP_PROP_FRAME_WIDTH, 400); // valueX = your wanted width
    cap.set(cv::CAP_PROP_FRAME_HEIGHT, 300); // valueY = your wanted heigth
    cap.open(0);

    CascadeClassifier face_cascade;
    face_cascade.load("/home/yrsn/Dev/cpp/CV/opencv/models/face.xml");

    while (waitKey(10) != 27)
    {
        Mat frame;
        cap >> frame;

        std::vector<Rect> faces;
        face_cascade.detectMultiScale(frame, faces, 1.1, 3,0, Size(20, 20));

        for(size_t i = 0; i < faces.size(); i++) {
            rectangle(frame, faces[i], Scalar(255, 255, 255), 1, 1, 0);
        }
        imshow("Webcam", frame);
    }
}