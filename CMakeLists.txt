cmake_minimum_required(VERSION 3.16)
project(communicationApp)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/bin)
add_executable(communicationApp ./src/main.cpp ./src/emojis.cpp ./src/network_client.cpp ./src/network_server.cpp ./src/communication_object_factory.cpp)
