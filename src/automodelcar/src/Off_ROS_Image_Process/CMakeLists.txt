cmake_minimum_required(VERSION 2.8)

project( DisplayImage )
find_package( OpenCV REQUIRED )
include_directories( ${OpenCV_INCLUDE_DIRS} )
add_executable( DisplayImage DisplayImage.cpp )
target_link_libraries( DisplayImage ${OpenCV_LIBS} )

add_executable( LocMax_pw LocMax_pw.cpp )
target_link_libraries( LocMax_pw ${OpenCV_LIBS} )

add_executable( line_detection line_detection.cpp )
target_link_libraries( line_detection ${OpenCV_LIBS} )

