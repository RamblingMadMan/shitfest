cmake_minimum_required(VERSION 3.16 FATAL_ERROR)

project(
	shitfest
	VERSION 0.0.1
	LANGUAGES CXX
)

include(FetchContent)

get_directory_property(SF_NOT_MASTER PARENT_DIRECTORY)
if(NOT SF_NOT_MASTER)
	set(SF_MASTER_PROJECT TRUE)
else()
	set(SF_MASTER_PROJECT FALSE)
endif()

option(SF_BUILD_SERVER "Whether to build the server executable" ${SF_MASTER_PROJECT})
option(SF_BUILD_CLIENT "Whether to build the client executable" ${SF_MASTER_PROJECT})

FetchContent_Declare(
	fmtlib_content
	GIT_REPOSITORY https://github.com/fmtlib/fmt.git
	GIT_TAG 8e47cfd1cdfa9cb29cbb5ae037124cd71425a1fe # latest at time of writing
)

FetchContent_Declare(
	robin_hood_hashing_content
	GIT_REPOSITORY https://github.com/martinus/robin-hood-hashing.git
	GIT_TAG bd2f7194ae5a52337a9dcaf06edd87338ed1d754
)

FetchContent_MakeAvailable(fmtlib_content robin_hood_hashing_content)

set(SF_INCLUDE_DIR ${CMAKE_CURRENT_LIST_DIR}/include)

set(
	SF_HEADERS
	${SF_INCLUDE_DIR}/sf/message.hpp
	${SF_INCLUDE_DIR}/sf/identity.hpp
	${SF_INCLUDE_DIR}/sf/user.hpp
	${SF_INCLUDE_DIR}/sf/cluster.hpp
)

add_subdirectory(lib)

if(SF_BUILD_SERVER)
	add_subdirectory(server)
endif()

if(SF_BUILD_CLIENT)
	add_subdirectory(client)
endif()
