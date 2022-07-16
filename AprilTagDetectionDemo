using namespace std;
#include <iostream>
#include <cstring>
#include <vector>
#include <list>
#include <sys/time.h>
#ifndef _APPLE_
#define EXPOSURE_CONTROL
#endif
#ifdef EXPOSURE_CONTROL
#include <libv4l2.h>
#include <linux/videodev2.h>
#include <fcntl.h>
#include <errno.h>
#endif
#include "opencv2/opencv.hpp"
#include "AprilTags/TagDetector.h"
#include "AprilTags/Tag16h5.h"
#include "AprilTags/Tag25h7.h"
#include "AprilTags/Tag25h9.h"
#include "AprilTags/Tag36h9.h"
#include "AprilTags/Tag36h11.h"
#include <unistd.h>

cv::VideoCapture m_cap = cv::VideoCapture("/home/hediyeorhan/apriltags/example/detection.mp4");

AprilTags::TagDetector* m_tagDetector = new AprilTags::TagDetector(AprilTags::tagCodes36h11);
//AprilTags::TagCodes m_tagCodes;

//m_tagCodes = AprilTags::tagCodes36h11;
//m_tagDetector = new AprilTags::TagDetector(AprilTags::tagCodes36h11);


void processImage(cv::Mat& image, cv::Mat& image_gray)
{
    cv::cvtColor(image, image_gray, cv::COLOR_BGR2GRAY);
    vector<AprilTags::TagDetection> detections = m_tagDetector->extractTags(image_gray);

    cout << detections.size() << " tags detected:" << endl;
    for (int i=0; i<detections.size(); i++)
    {
        detections[i].draw(image);
    }

    imshow("AprilTagDetector", image);
}


int main(int argc, char* argv[])
{

    cv::Mat image;
    cv::Mat image_gray;

    while (true)
    {
        m_cap >> image;

        processImage(image, image_gray);

        if (cv::waitKey(1) >= 0) break;
    }

    return 0;
}
