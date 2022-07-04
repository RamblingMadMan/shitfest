find_package(Threads REQUIRED)
find_package(Boost REQUIRED COMPONENTS system thread)

add_library(
	shitfest SHARED
	${SF_HEADERS}
	message.cpp
)

target_link_libraries(shitfest PUBLIC Threads::Threads Boost::system Boost::thread fmt robin_hood)

target_include_directories(shitfest PUBLIC ${SF_INCLUDE_DIR})

target_compile_features(shitfest PUBLIC cxx_std_17)
