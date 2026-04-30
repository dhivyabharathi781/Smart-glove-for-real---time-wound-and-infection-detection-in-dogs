# Smart Glove for Real-Time Wound and Infection Detection in Dogs

## 1. Project Overview
This project presents a wearable smart glove system designed for the early detection of wound infections in dogs. The system integrates biomedical sensors, embedded hardware, IoT connectivity, and machine learning techniques to monitor physiological and visual changes in wounds and provide timely alerts.

## 2. Hardware Components
The system is developed using the following components:

- ESP32 DevKit V1 microcontroller  
- MLX90614 infrared temperature sensor  
- DHT11 humidity sensor  
- TCS34725 color sensor  
- ESP32-CAM module  
- RGB LED indicator  

## 3. Software Environment
The project is implemented using the following software tools:

- Arduino IDE for embedded programming  
- Python for data processing and model integration  
- Google Colab for machine learning model training  
- MIT App Inventor for mobile application development  
- ThingSpeak platform for IoT data visualization  

## 4. Machine Learning Model
A lightweight deep learning model is used to classify wound conditions.

- Model Architecture: MobileNet  
- Training Accuracy: 74% – 80%  
- Validation Accuracy: 74% – 78%  
- Testing Accuracy: 74% – 76%  

### Model Access
Due to file size limitations, the trained model is hosted externally:

https://drive.google.com/file/d/1gdoHeldspGoSNQA_51xbIMuPSmILnVHk/view?usp=sharing

## 5. Dataset Description
The dataset consists of labeled images of infected and non-infected wound conditions used for training and evaluation of the model.

### Dataset Access
https://drive.google.com/drive/folders/1KoIp2rmVNcU8DFtjMRPPeS3x7PB0zV4r?usp=sharing

## 6. Mobile Application
A mobile application has been developed to display real-time sensor readings and infection status. The application enables remote monitoring through IoT integration and provides alert notifications based on system output.

## 7. System Integration (IoT + AI)
The system combines IoT sensors and a machine learning model for wound monitoring and infection detection.

- ESP32-CAM captures wound images for analysis  
- ESP32 sends sensor data (temperature, humidity, color) to cloud  
- MobileNet model classifies wound condition from images  
- Final decision is based on both sensor readings and image output


## 8. System Output
The system generates the following outputs:
- Real-time sensor monitoring  
- Infection detection classification  
- Visual indication using RGB LED  
- ESP32-CAM image capture results  

## 9. Project Structure
Smart-Glove-Project/ │ ├── Arduino_Code/ ├── Python_Code/ ├── ML_Model/ ├── Mobile_App/ ├── Dataset/ ├── Results/ ├── Report/ ├── Presentation/ └── README.md

---

## 10. Limitations
- Dataset size is limited and contains visually similar samples  
- Real-time testing on clinical animal cases is limited  
- Model performance can be improved with larger and more diverse datasets  

## 11. Future Enhancements
- Expansion of dataset with real clinical wound images  
- Implementation of advanced deep learning architectures  
- Integration of additional biomedical sensors  
- Extension to multi-animal health monitoring systems  
- Enhancement of mobile application interface and alert system
- 
## 12. Ethical Consideration
All experimental procedures were carried out on a privately owned animal with prior owner consent. The system is non-invasive and designed to ensure animal safety and comfort throughout the study.

## 13. Acknowledgement
The authors express sincere gratitude to the project guide and institution for their continuous support, guidance, and encouragement throughout the development of this work.

## 14. References
- Arduino Official Documentation  
- TensorFlow and Keras Documentation  
- Research papers on MobileNet architecture  
- IEEE publications on IoT-based healthcare systems  

## 15. License
This project is developed for academic and educational purposes only.

## 16. Author
Dhivyabharathi S  

## 17. Conclusion
The proposed system demonstrates an effective integration of IoT and machine learning for early detection of wound infections in dogs. The solution is cost-effective, scalable, and suitable for real-time animal healthcare monitoring applications.
