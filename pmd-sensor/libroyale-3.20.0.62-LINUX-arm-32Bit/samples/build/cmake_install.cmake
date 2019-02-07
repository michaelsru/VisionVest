# Install script for directory: /home/pi/Documents/VisionVest/pmd-sensor/libroyale-3.20.0.62-LINUX-arm-32Bit/samples

# Set the install prefix
if(NOT DEFINED CMAKE_INSTALL_PREFIX)
  set(CMAKE_INSTALL_PREFIX "/usr/local")
endif()
string(REGEX REPLACE "/$" "" CMAKE_INSTALL_PREFIX "${CMAKE_INSTALL_PREFIX}")

# Set the install configuration name.
if(NOT DEFINED CMAKE_INSTALL_CONFIG_NAME)
  if(BUILD_TYPE)
    string(REGEX REPLACE "^[^A-Za-z0-9_]+" ""
           CMAKE_INSTALL_CONFIG_NAME "${BUILD_TYPE}")
  else()
    set(CMAKE_INSTALL_CONFIG_NAME "")
  endif()
  message(STATUS "Install configuration: \"${CMAKE_INSTALL_CONFIG_NAME}\"")
endif()

# Set the component getting installed.
if(NOT CMAKE_INSTALL_COMPONENT)
  if(COMPONENT)
    message(STATUS "Install component: \"${COMPONENT}\"")
    set(CMAKE_INSTALL_COMPONENT "${COMPONENT}")
  else()
    set(CMAKE_INSTALL_COMPONENT)
  endif()
endif()

# Install shared libraries without execute permission?
if(NOT DEFINED CMAKE_INSTALL_SO_NO_EXE)
  set(CMAKE_INSTALL_SO_NO_EXE "1")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for each subdirectory.
  include("/home/pi/Documents/VisionVest/pmd-sensor/libroyale-3.20.0.62-LINUX-arm-32Bit/samples/build/cpp/sampleCameraInfo/cmake_install.cmake")
  include("/home/pi/Documents/VisionVest/pmd-sensor/libroyale-3.20.0.62-LINUX-arm-32Bit/samples/build/cpp/sampleRetrieveData/cmake_install.cmake")
  include("/home/pi/Documents/VisionVest/pmd-sensor/libroyale-3.20.0.62-LINUX-arm-32Bit/samples/build/cpp/sampleOpenCV/cmake_install.cmake")
  include("/home/pi/Documents/VisionVest/pmd-sensor/libroyale-3.20.0.62-LINUX-arm-32Bit/samples/build/cpp/sampleSlave/cmake_install.cmake")
  include("/home/pi/Documents/VisionVest/pmd-sensor/libroyale-3.20.0.62-LINUX-arm-32Bit/samples/build/cpp/sampleExportPLY/cmake_install.cmake")
  include("/home/pi/Documents/VisionVest/pmd-sensor/libroyale-3.20.0.62-LINUX-arm-32Bit/samples/build/cpp/sampleOpenNI2Driver/cmake_install.cmake")
  include("/home/pi/Documents/VisionVest/pmd-sensor/libroyale-3.20.0.62-LINUX-arm-32Bit/samples/build/cpp/sampleProcessingParameters/cmake_install.cmake")
  include("/home/pi/Documents/VisionVest/pmd-sensor/libroyale-3.20.0.62-LINUX-arm-32Bit/samples/build/cpp/sampleRawData/cmake_install.cmake")
  include("/home/pi/Documents/VisionVest/pmd-sensor/libroyale-3.20.0.62-LINUX-arm-32Bit/samples/build/cpp/sampleRecordRRF/cmake_install.cmake")
  include("/home/pi/Documents/VisionVest/pmd-sensor/libroyale-3.20.0.62-LINUX-arm-32Bit/samples/build/c/sampleCAPI/cmake_install.cmake")

endif()

if(CMAKE_INSTALL_COMPONENT)
  set(CMAKE_INSTALL_MANIFEST "install_manifest_${CMAKE_INSTALL_COMPONENT}.txt")
else()
  set(CMAKE_INSTALL_MANIFEST "install_manifest.txt")
endif()

string(REPLACE ";" "\n" CMAKE_INSTALL_MANIFEST_CONTENT
       "${CMAKE_INSTALL_MANIFEST_FILES}")
file(WRITE "/home/pi/Documents/VisionVest/pmd-sensor/libroyale-3.20.0.62-LINUX-arm-32Bit/samples/build/${CMAKE_INSTALL_MANIFEST}"
     "${CMAKE_INSTALL_MANIFEST_CONTENT}")
