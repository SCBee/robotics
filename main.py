# Hand Tracking
import cv2
import time
from hand_tracker import handDetector

# Controller
import serial
from time import sleep

def main():
    # ----------- Setup Arduino Comms -----------
    mcuSerialPort = "COM8" # Change this to the serial port for your arduino
    mcuBaudRate = 9600 # Change this to your desired rate

    # Begin serial comms and wait for it to establish
    mcu = serial.Serial(mcuSerialPort, baudrate=mcuBaudRate)
    sleep(1)

    # ----------- Setup and run hand tracking -----------
    pTime = 0
    cTime = 0
    cap = cv2.VideoCapture(0)
    detector = handDetector()
    while True:
        success, img = cap.read()
        img = detector.findHands(img)
        lmList = detector.findPosition(img)
        if len(lmList) != 0:
            # Fist Closed
            if lmList[5][2] < lmList[8][2] and lmList[9][2] < lmList[12][2] and lmList[13][2] < lmList[16][2] and lmList[17][2] < lmList[20][2]:
                mcu.write(b'5')
            
            # Check each finger
            else:
                # Check Index Finger
                if lmList[5][2] < lmList[8][2]:
                    mcu.write(b'1')
                
                # Check Middle Finger
                if lmList[9][2] < lmList[12][2]:
                    mcu.write(b'2')

                # Check Ring Finger
                if lmList[13][2] < lmList[16][2]:
                    mcu.write(b'3')

                # Check Pinky Finger
                if lmList[17][2] < lmList[20][2]:
                    mcu.write(b'4')

        # Disable all fingers
        mcu.write(b'0')

        cTime = time.time()
        fps = 1 / (cTime - pTime)
        pTime = cTime

        cv2.putText(img, str(int(fps)), (10, 70), cv2.FONT_HERSHEY_PLAIN, 3,
                    (255, 0, 255), 3)

        cv2.imshow("Image", img)
        cv2.waitKey(1)


if __name__ == "__main__":
    main()