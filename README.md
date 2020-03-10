# EEHMD_v2
2st version of the EEHMD database. It includes higher aquisition frequencies and improved motion-capture precision.

## Description

The Electromyography and Enhanced Hand Motion Description (EEHMD) database contains sEMG (surface electromyography) signals and motion capture of human hand. The sEMG signals are captured by a Myo armband. The motion acquisition is achieved with a Leap Motion stereoscopic camera. 

The EEHMD v2 currently have only the ROS code to create the database. It is coded for windows to take advantage of manufactutrer windows drivers. It includes the following improvement :

- The Leap Motion uses the 4.0.0 sdk. This new C library (and no C++) is faster, more robust and more precise than the previous version.
- The Myo uses the 0.9.0 SDK which provides raw 200Hz EMG data (50Hz in the EEHMD_v1).

## How to use it

### ros_eehmd

Once built, the ros_eehmd package proposes 3 nodes:

##### myo_subscriber_node
This node is an example of how to subscribe the Myo EMG data. It subscribes the **myo_raw** topic and writes the EMG vector in the command promp as it is sent by the topic.

##### myo_subscriber_node
This node is an example of how to subscribe the Leap Motion data. It subscribes the **Leapmotion_raw** topic and writes the coordinate of thumb metacarpal bone in the command promp.

##### joint_coordinates_publisher
This code subscribes the **leapmotion_raw** topic and publishes the corresponding joint coordinates in the **joint_coordinates_from_leap** topic. The header is copied for a future synchronization.

    ### ros_leapmotion

The ros_leapmotion package instructions can be found here : https://github.com/SimonKirchhofer-UCA/ROS_Myo_Windows

### ros_myo

The ros_myo package instructions can be found here : https://github.com/SimonKirchhofer-UCA/ROS-LeapMotion-Windows

