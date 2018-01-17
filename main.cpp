#include <iostream>
#include <Manus.h>


std::string toString_allFingerDataCSV(double *sensorsArray){

    // Value sensors for each fingers
    const std::string pinkyValue = std::to_string(sensorsArray[0]) + "," + std::to_string(sensorsArray[1]);
    const std::string thumbValue = std::to_string(sensorsArray[2]) + "," + std::to_string(sensorsArray[3]);
    const std::string indexValue = std::to_string(sensorsArray[4]) + "," + std::to_string(sensorsArray[5]);
    const std::string middleValue = std::to_string(sensorsArray[6]) + "," + std::to_string(sensorsArray[7]);
    const std::string ringValue = std::to_string(sensorsArray[8]) + "," + std::to_string(sensorsArray[9]);

    return thumbValue + "," + indexValue + "," + middleValue + "," + ringValue + "," + pinkyValue;




}

int main() {

    manus_session_t session;
    ManusInit(&session);

    int idFingerLow = 2;
    int idFingerHigh = 3;
    uint32_t *idDONGLE, count;
    manus_hand_t leftData;

    ManusGetDongleIDs(session, idDONGLE, count);

    std::cout << "Connected to Manus-VR DONGLE-ID " << idDONGLE << std::endl;
    std::cout << "Left GLove connected " << ManusIsConnected(session, GLOVE_LEFT) << std::endl;


    while (true) {
        ManusGetHand(session, GLOVE_LEFT, &leftData);

            std::cout << " Finger sensor number " << idFingerLow << " Value : " << leftData.raw.finger_sensor[idFingerLow] << std::endl;
            std::cout << " Finger sensor number " << idFingerHigh << " Value : " << leftData.raw.finger_sensor[idFingerHigh] << std::endl;
            std::cout << "\n" << std::endl;


    }



ManusExit(session);

return 0;
}