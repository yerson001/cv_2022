cmake_minimum_required(VERSION 3.5)

set(CMAKE_CXX_STANDARD 14)

PROJECT(opencv_cpp_basics)

find_package( OpenCV REQUIRED ) #find_package( OpenCV 4 REQUIRED )

include_directories( ${OpenCV_INCLUDE_DIRS})

MACRO(add_example name)
  ADD_EXECUTABLE(${name} src/${name}.cpp)
  TARGET_LINK_LIBRARIES(${name} ${OpenCV_LIBS})
ENDMACRO()

#add_example(hello_cv)
#add_example(basic_cv)
add_example(read_file)
#add_example(face_detect)
