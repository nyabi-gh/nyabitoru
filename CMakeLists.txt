cmake_minimum_required(VERSION 4.3)
project(nyabitoru)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

if (APPLE)
    find_package(OpenCV 5 REQUIRED)
else ()
    find_package(OpenCV 4 REQUIRED)
endif ()

find_package(onnxruntime CONFIG REQUIRED)

add_executable(nyabitoru src/main.cpp)

target_include_directories(nyabitoru PRIVATE
        include
        ${OpenCV_INCLUDE_DIRS}
)

if (MSVC)
    target_compile_options(nyabitoru PRIVATE /utf-8)
endif ()

if (WIN32)
    add_custom_command(TARGET nyabitoru POST_BUILD
            COMMAND ${CMAKE_COMMAND} -E copy_if_different
            $<TARGET_RUNTIME_DLLS:nyabitoru>
            $<TARGET_FILE_DIR:nyabitoru>
            COMMAND_EXPAND_LISTS
    )
endif ()

target_link_libraries(nyabitoru PRIVATE
        ${OpenCV_LIBS}
        onnxruntime::onnxruntime
)