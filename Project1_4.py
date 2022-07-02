import cv2
import numpy as np
import datetime


# Frame'leri okunacak olan videoyuyu opencv kütüphanesi ile açıyoruz.
cap = cv2.VideoCapture("NvidiaJetsonNanoRobot.mp4") 

# Üzerinde işlem yapılan frame'ler tekrar kayıt edileceği için kayıt edilecek videonun pencere boyutları ve hızı ayarlanmaktadır.
frameRate = cap.get(cv2.CAP_PROP_FPS)
writer_width = int(cap.get(cv2.CAP_PROP_FRAME_WIDTH))
writer_height = int(cap.get(cv2.CAP_PROP_FRAME_HEIGHT))

# Kayıt edilecek video formatı ve yeni videonun ismi belirtilmektedir.
writer = None
(W,H) = (None, None)
fourcc = cv2.VideoWriter_fourcc(*'H264')
writer = cv2.VideoWriter("NvidiaJetsonNanoRobotOUTPUT.mp4", fourcc, frameRate, (writer_width, writer_height), True)

# Video'nun sonuna kadar framelerin okunması icin sonsuz dongu icinde tek tek frameleri okuyoruz.
while True:
  # frameleri okuma asamasi
    (_, img) = cap.read()
    img_width = img.shape[1] 
    img_height = img.shape[0]
                                   
        
    # Okunan framelere tarih ve saat bilgisi datetime modulü ile alınmakta ve opencv fonksiyonları ile yazılmaktadır.
    cv2.putText(img, "DATE : " + str(datetime.datetime.now().date()), (10, 30), cv2.FONT_HERSHEY_SIMPLEX, 1, (0, 0, 0), 3)
    cv2.putText(img, "TIME : " + str(datetime.datetime.now().time()), (10, 80), cv2.FONT_HERSHEY_SIMPLEX, 1, (0, 0, 0), 3)
    
    # Okunan ve üzerinde işlem yapılan videoyuyu bilgisayar ekranında işlem bitene kadar izlemek için  imshow fonksiyonu kullanılıyor ve write ile video kayıt ediliyor.
    cv2.imshow("OUTPUT", img)
    writer.write(img)
			
    # Bu kısım framelerin tamamı bitmeden kapatmak istersek ESC tuşu ile videoyuyu kapatmak için yazılmıştır.
    k = cv2.waitKey(5) & 0xFF
    if k == 27:
        break

# Tum islemler bittikten sonra tum pencelerin duzgun bir sekilde kapanmasini saglamaktadir.
writer.release()
cv2.destroyAllWindows()
