local libSFML = "../dependencies/SFML/build/lib"
local includeSFML = "../dependencies/SFML/include"

workspace "Acrilux"
	configurations { "Debug", "Release" }
	location "build"
	
project "Acrilux"
	location "build"
	kind "ConsoleApp"
	language "C++"
	targetdir "bin"
	
	files { "src/*.h", "src/headers/*.hpp", "src/*.cpp" }
	
	filter "configurations:Debug"
		defines { "DEBUG" }
		symbols "On"
		optimize "On"
		links { "sfml-system-d", "sfml-window-d", "sfml-graphics-d" }
		libdirs { libSFML }
		includedirs { includeSFML }
		targetsuffix "-d"
		
	filter "configurations:Release"
		defines { "NDEBUG" }
		flags { }
		linktimeoptimization "On"
		optimize "Full"
		links { "sfml-system", "sfml-window", "sfml-graphics" }
		libdirs { libSFML }
		includedirs { includeSFML }