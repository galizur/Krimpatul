-- premake 5

workspace "Krimpatul"
architecture "x86_64"
startproject "Krimpatul"

configurations
{
   "Debug",
   "Release"
}

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

IncludeDir = {}
IncludeDir["nana"] = "Krimpatul/vendor/nana/include"

include "Krimpatul/vendor/nana"

group "A. Project"
project "Krimpatul"
location "Krimpatul"
kind "ConsoleApp"
language "C++"
cppdialect "C++17"
staticruntime "on"

targetdir ("bin/" .. outputdir .. "/%{prj.name}")
objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

pchheader "krpch.hpp"
pchsource "Krimpatul/src/krphc.cpp"

files
{
   "%{prj.name}/src/**.hpp",
   "%{prj.name}/src/**.h",
   "%{prj.name}/src/**.cpp"
}

includedirs
{
   "%{prj.name}/src",
   "%{IncludeDir.nana}",
   "/usr/include/freetype2"
}

links
{
   "nana",
   "X11",
   "pthread",
   "rt",
   "Xft",
   "png",
   "asound",
   "fontconfig"
}

filter "system:windows"
systemversion "latest"

defines
{
   "KR_PLATFORM_WINDOWS"
}

filter "system:linux"

defines
{
   "KR_PLATFORM_LINUX"
}

links
{
}

toolset "clang"

filter "configurations:Debug"
defines "KR_DEBUG"
runtime "Debug"
symbols "On"

filter "Configurations:Release"
defines "KR_RELEASE"
runtime "Release"
optimize "On"
group ""
