add_executable(testHello testHello.cpp)
add_test(NAME test-hello COMMAND testHello)

add_library(Catch INTERFACE)
target_include_directories(Catch INTERFACE ${CMAKE_CURRENT_LIST_DIR})
TARGET_COMPILE_FEATURES(Catch INTERFACE cxx_noexcept)

add_executable(testCatch testCatch.cpp)
target_link_Libraries(testCatch Catch)
add_test(NAME test-catch COMMAND testCatch)

add_executable(testTransformChar testTransformChar.cpp)
target_link_libraries(testTransformChar MPAGSCipher Catch)
add_test(NAME test-TransformChar COMMAND testTransformChar)

add_executable(testCommandLine testCommandLine.cpp)
target_link_libraries(testCommandLine MPAGSCipher Catch)
add_test(NAME test-CommandLine COMMAND testCommandLine)