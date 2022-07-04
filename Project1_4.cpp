#include <opencv2/core.hpp> 
#include <opencv2/dnn.hpp>
#include <opencv2/videoio.hpp> 
#include <opencv2/highgui.hpp> 
#include <opencv2/imgproc.hpp> 
#include <iostream> 
#include <time.h> 
#include <ctime>

int main() 
{ 
    cv::VideoCapture cap; 
 
    cap.open("SimpleObjectTrackingCamera.mp4", cv::CAP_ANY); 

  
    // Video ciktisinin kaydedilmesi icin kayit formati ve ayarlamalari belirliyoruz.  
  
    std::string outputFile = "CPP_OUTPUT_SimpleObjectTrackingCamera.mp4";
    cv::VideoWriter writer; 
	  writer.open(outputFile, cv::VideoWriter::fourcc('H','2','6','4'), int(cap.get(cv::CAP_PROP_FPS)), cv::Size((int)cap.get(cv::CAP_PROP_FRAME_WIDTH),(int) cap.get(cv::CAP_PROP_FRAME_HEIGHT)));

    for (;;) 
    { 
        if (!cap.isOpened()) 
        { 
            std::cout << "Video Capture Fail" << std::endl; 
            break; 
        } 
        cv::Mat img; 
        cap >> img; 
        
        time_t su_anki_saat = time(NULL);

            
        // saat ve tarih degerini alip stringe cevirerek ekrana yazdiriyoruz.
        char* cevrilmis = ctime(&su_anki_saat);
        std::cout<<"Cevrilmis saat : "<<cevrilmis<<std::endl;

        cv::putText(img, "DATE & TIME : " + cevrilmis, cv::Point(left, top), 1, 2, cv::Scalar(color, 255, 255), 2, false);

        cv::imshow("DisplayWindow", img); 

        writer.write(img);
        int k = cv::waitKey(5) & 0xFF;
        if(k == 27)
        {
            break;
        }
        
    } 
    writer.release();
    cv::destroyAllWindows();
    return 0;
}
