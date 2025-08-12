cmake_minimum_required(VERSION 3.10)
project(PlagiarismDetector)

set(CMAKE_CXX_STANDARD 17)

include_directories(include)

add_executable(plagiarism-detector
    src/main.cpp
    src/file_reader.cpp
    src/text_processor.cpp
    src/similarity.cpp
)
