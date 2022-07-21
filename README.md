<h1 align="center">Sensor System</h1>

This project was given as a final exam for "Sensor Systems" at Singidunum University. The goal of this course was to teach students about how sensors work and how retrieved images can be processed to gain useful information that can be used to control other parts of a system.

The project was split into two parts:

### Arduino Project

The task of this project was to use an ultrasonic sensor to read the distance from an object and, depending on distance speed up or slow down an electrical motor. This motor is part of an optical encoder which is used to calculate rotary speed of a disc attached to the motor. After reading the data, the speed (m/s) was printed out through the serial port.

### Image Processing Project

The task of this project was to use Python to create a gaussian blur filter that can be applied to an image. Besides creating the filter, we were also tasked to show the image in color, grayscale, as well as compute a histogram and CDF. This task had to be done in a Jupyter Notebook file.

## 🧰 Languages & Tools

<a href="https://code.visualstudio.com/"><img src="https://cdn.jsdelivr.net/gh/devicons/devicon/icons/vscode/vscode-original.svg" width="30px" alt="VSCode" title="Visual Studio Code"></a>
<a href="https://www.arduino.cc/"><img src="https://cdn.jsdelivr.net/gh/devicons/devicon/icons/arduino/arduino-original.svg" width="30px" alt="Arduino" title="Arduino"></a>
<a href="https://jupyter.org/"><img src="https://cdn.jsdelivr.net/gh/devicons/devicon/icons/jupyter/jupyter-original.svg" width="30px" alt="Jupyter Notebook" title="Jupyter Notebook"></a>
<a href="#"><img src="https://cdn.jsdelivr.net/gh/devicons/devicon/icons/cplusplus/cplusplus-original.svg" width="30px" alt="C++" title="C++ Programming Language"></a>
<a href="https://www.python.org/"><img src="https://cdn.jsdelivr.net/gh/devicons/devicon/icons/python/python-original.svg" width="30px" alt="Python" title="Python Programming Language"></a>

## ⚡ Getting Started - Arduino

### 🛠 Requirements:

- Arduino Uno Rev3
- HC-SR04 Ultrasonic sensor
- L293D H-Bridge
- Motor with optical encoder
- 12V Power Supply

### 📖 Guide:

1. Follow the schematic bellow to connect your components:

    ![Schematic](./.github/images/schematic.svg "Schematic")
2. Download ```ArduinoProject.ino``` file from the repository
3. Download [Arduino IDE](https://www.arduino.cc/en/software/)
4. Flash the code onto the Arduino
5. Enjoy 🙂

## ⚡ Getting Started - Jupyter

### 🛠 Requirements:

- [Python](https://www.python.org/downloads/)
- [Jupyter Notebook](https://jupyter.org/install)

### 📖 Guide:

1. Download the repository
2. Download and install Python
3. Download and install Jupyter Notebook
4. Execute ```> pip3 install numpy``` to install Numpy on your system
5. Execute ```> pip3 install matplotlib``` to install MatPlotLib on your system
6. Execute ```> jupyter notebook``` to run Jupyter
7. Open ```Python Image Processing.ipynb``` using Jupyter
8. Enjoy 🙂

## ⚖ License
This repository is not under any license. Normal copyright laws apply!