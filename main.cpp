#include <iostream>
#include <Manus.h>
#include <fstream>


// Helper function to format raw sensor data to CSV
std::string toString_allFingerDataCSV(double *sensorsArray) {



    // Value sensors for each fingers Low, High
    const std::string pinkyValue = std::to_string(sensorsArray[0]) + "," + std::to_string(sensorsArray[1]);
    const std::string thumbValue = std::to_string(sensorsArray[2]) + "," + std::to_string(sensorsArray[3]);
    const std::string indexValue = std::to_string(sensorsArray[4]) + "," + std::to_string(sensorsArray[5]);
    const std::string middleValue = std::to_string(sensorsArray[6]) + "," + std::to_string(sensorsArray[7]);
    const std::string ringValue = std::to_string(sensorsArray[8]) + "," + std::to_string(sensorsArray[9]);

    return thumbValue + "," + indexValue + "," + middleValue + "," + ringValue + "," + pinkyValue;

}

int main() {

// Initializing session of MANUS-VR
    manus_session_t session = nullptr;


    uint32_t *idDONGLE, count;
    manus_hand_t leftHandData{}, rightHandData{};
    ManusInit(&session);
    ManusGetDongleIDs(session, idDONGLE, count);


    if (session != nullptr) {

        ManusGetHand(session, GLOVE_LEFT, &leftHandData);
//         ManusGetHand(session, GLOVE_RIGHT, &rightHandData);

        // Defining the saving file
        std::ofstream leftRecordSensorCSV;
        leftRecordSensorCSV.open("leftRecordSensor.csv");

        std::ofstream rightRecordSensorCSV;
        rightRecordSensorCSV.open("rightRecordSensor.csv");

        //TODO find a better way to control the stopping of the recording actually waiting for killSIg
        while (true) {

            //std::cout << " Getting raw data from gloves" << std::endl;
            std::cout << std::to_string(leftHandData.raw.finger_sensor[0]) << std::endl;
            leftRecordSensorCSV << toString_allFingerDataCSV(leftHandData.raw.finger_sensor) + "\n";
//            rightRecordSensorCSV << toString_allFingerDataCSV(rightHandData.raw.finger_sensor) + "\n";
        }

        leftRecordSensorCSV.close();
        rightRecordSensorCSV.close();
    } else {
        std::cout << " Unable to Connected to Manus-VR gloves" << std::endl;
        ManusExit(session);
        return 0;
    }



    return 0;
}