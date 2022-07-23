workspace("DragAPI")
configurations({"Debug", "Release"})
platforms({"x86", "x64"})
cppdialect "C++20"



OutputDirectory = "%{wks.location}/bin/%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"
ObjectDirectory = "%{wks.location}/bin-int/%{prj.name}/%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"



filter { "platforms:Win32" }
    system "Windows"
    systemversion "latest"
    architecture "x86"
    staticruntime "On"
    defines {
        "PLATFORM_WINDOWS", 
        "ARCHITECTURE_32"
    }

filter { "platforms:Win64" }
    system "Windows"
    systemversion "latest"
    architecture "x86_64"
    staticruntime "On"
    defines {
        "PLATFORM_WINDOWS", 
        "ARCHITECTURE_64"
    }

filter {"configurations:Debug"}
    defines {"_DEBUG"}
    symbols "On"

filter {"configurations:Release"}
    optimize "On"





libdirs{
	OutputDirectory
}

include "DragAPI_Core"
include "DragAPI_Graphical"
include "DragAPI_Networking"
include "DragAPI_Math"
include "DragAPI"