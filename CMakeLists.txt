cmake_minimum_required(VERSION 3.24)
project(connect4)

set(CMAKE_CXX_STANDARD 14)

include_directories(core)

add_executable(connect4
        core/c4/c4_judge.cpp
        core/c4/c4_winning.cpp
        core/c4/connect4.cpp
        core/c4/connect4_core.cpp
        core/c4/recording_core.cpp
        core/c4/serialize.cpp
        core/c4/storage.cpp
        core/c4/user_core.cpp
        core/com/convert.cpp
        core/com/file_operator.cpp
        core/com/log.cpp
        core/interface/c4_application.cpp
        core/interface/c4_interface.cpp
        core/interface/c4_interface_color.cpp
        core/c4_interface.hpp
        core/common.hpp
        core/connect4.hpp
        core/storage.hpp
        main.cpp)
