cmake_minimum_required(VERSION 3.18.1)
set(CMAKE_VERBOSE_MAKEFILE on)

project(gtypes)

include("../../../hltypes/android-studio/generic/CMakeLists.txt")

file(
	GLOB_RECURSE CppSrc
	"../../src/*.c"
	"../../src/*.cpp"
)

add_library(gtypes STATIC ${CppSrc})

include_directories(AFTER "../../include/gtypes")

add_definitions(
	-DGTYPES_EXPORTS
)

target_link_libraries(
	gtypes
)
