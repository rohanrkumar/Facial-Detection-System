#include <iostream>
#include<opencv2\imgcodecs.hpp>
#include<opencv2\objdetect\objdetect.hpp>
#include<opencv2\imgproc\imgproc.hpp>
#include<opencv2\highgui\highgui.hpp>
using namespace std;
using namespace cv;

void main() {
	//video cam
	VideoCapture video(0);
	CascadeClassifier faceDetection;
	Mat img;
	faceDetection.load("haarcascade_frontalface_default.xml");
	while (true) {
		// read images from from video cams
		video.read(img);
		vector<Rect> faces;
		faceDetection.detectMultiScale(img, faces, 1.3, 5);
		for (int i = 0;i < faces.size();i++) {
			rectangle(img, faces[i].tl(), faces[i].br(), Scalar(50, 50, 255), 3);
		}
		imshow("Frame", img);
		waitKey(20);
	}
}
/*void main() {
	string path = "photo.jpg";
	Mat img = imread(path);
	imshow("Frame", img);
	waitKey(0);
}*/

