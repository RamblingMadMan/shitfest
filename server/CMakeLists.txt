add_executable(sf-srv main.cpp)

target_compile_features(sf-srv PUBLIC cxx_std_17)

target_link_libraries(sf-srv PUBLIC shitfest)

set_target_properties(sf-srv PROPERTIES CXX_STANDARD 17)
