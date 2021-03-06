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
