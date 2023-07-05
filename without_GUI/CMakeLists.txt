cmake_minimum_required(VERSION 3.5)
project(YADRO_test_task)

# Указываем путь к исходным файлам проекта
set(SOURCES
    main.cpp
    ../QAM_lib/src/awgn.cpp
    ../QAM_lib/src/qamdemodulator.cpp
    ../QAM_lib/src/qammodulator.cpp
)

# Указываем путь к заголовочным файлам проекта
set(HEADERS
    ../QAM_lib/inc/awgn.h
    ../QAM_lib/inc/QAM.h
    ../QAM_lib/inc/qamdemodulator.h
    ../QAM_lib/inc/qammodulator.h
)

# Добавляем исполняемый файл проекта
add_executable(YourProjectName ${SOURCES} ${HEADERS})

# Указываем путь к заголовочным файлам библиотеки QAM_lib
target_include_directories(YourProjectName PRIVATE ../QAM_lib/inc)

# Указываем путь к исходным файлам библиотеки QAM_lib
add_subdirectory(../QAM_lib)

# Линкуем проект с библиотекой QAM_lib
target_link_libraries(YourProjectName QAM_lib)
