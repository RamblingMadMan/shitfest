add_executable(sf-gui main.cpp)

target_compile_features(sf-gui PUBLIC cxx_std_17)

target_link_libraries(sf-gui PUBLIC shitfest)
