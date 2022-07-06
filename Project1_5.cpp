#include <opencv2/core.hpp> 
#include <opencv2/dnn.hpp>
#include <opencv2/videoio.hpp> 
#include <opencv2/highgui.hpp> 
#include <opencv2/imgproc.hpp> 
#include <iostream> 
#include <time.h> 
#include <ctime>
#include <string>

using namespace std;

int main() 
{ 
    cv::VideoCapture cap; 
    
    // Kullanicidan sure ve dosya adi aliyoruz.
    string dosyaadi;
    int kullanici_sure;

    cout<< "\n -> Kayit edilecek dosyanin adini giriniz (Bosluk ve turkce karakter kullanmadan ve mp4 uzantili olarak !) : ";
    getline(cin >> ws, dosyaadi);

    cout << "\n -> Kayit alinacak video suresini giriniz (Saniye cinsinden) : ";
    cin >> kullanici_sure;

    cap.open(0, cv::CAP_ANY);
    // videonun kayit edilmesi icin gerekli parametreler ayarlaniyor.
    cv::VideoWriter writer; 
    writer.open(dosyaadi, cv::VideoWriter::fourcc('H','2','6','4'), int(cap.get(cv::CAP_PROP_FPS)), cv::Size((int)cap.get(cv::CAP_PROP_FRAME_WIDTH),(int) cap.get(cv::CAP_PROP_FRAME_HEIGHT)));
    
    // video kayit suresi tutmak icin video basladıgı anda bir sayaç tutuyoruz.
    clock_t starting_time = clock();
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

            
        // string'e dönüştür
        char* cevrilmis = ctime(&su_anki_saat);
        std::cout<<"Cevrilmis saat : "<<cevrilmis<<std::endl;

        cv::putText(img, "DATE & TIME : " + cevrilmis, cv::Point(left, top), 1, 2, cv::Scalar(color, 255, 255), 2, false);
        cv::imshow("DisplayWindow", img); 
        writer.write(img);
        
        // Burada ne kadar sure gectigi hesaplanıyor ve if kosulu saglandigi durumda kayit sona eriyor.
        clock_t elapsed_time = clock() - starting_time;

        if(elapsed_time >= kullanici_sure)
        {
            break;
        }
        
    } 

    cout<<"\n\n VIDEO KAYIT ISLEMI BITTI ";
    writer.release();
    cv::destroyAllWindows();
    return 0;
}
