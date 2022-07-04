cmake_minimum_required(VERSION 3.16 FATAL_ERROR)

project(
	shitfest
	VERSION 0.0.1
	LANGUAGES CXX
)

get_directory_property(SF_NOT_MASTER PARENT_DIRECTORY)
if(NOT SF_NOT_MASTER)
	set(SF_MASTER_PROJECT TRUE)
else()
	set(SF_MASTER_PROJECT FALSE)
endif()

option(SF_BUILD_SERVER "Whether to build the server executable" ${SF_MASTER_PROJECT})
option(SF_BUILD_CLIENT "Whether to build the client executable" ${SF_MASTER_PROJECT})

if(SF_BUILD_SERVER)
	add_subdirectory(server)
endif()

if(SF_BUILD_CLIENT)
	add_subdirectory(client)
endif()
