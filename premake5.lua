workspace("DragAPI")
configurations({"Debug", "Release"})
platforms({"x86", "x64"})
cppdialect "C++20"



OutputDirectory = "%{wks.location}/bin/%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"
ObjectDirectory = "%{wks.location}/bin-int/%{prj.name}/%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"


libdirs{
	OutputDirectory
}
    


filter { 
    "platforms:Win32",
    "configurations:Debug"                
    }
    system "Windows"
    systemversion "latest"
    architecture "x86"
    staticruntime "On"
    symbols "On"
    defines {
        "PLATFORM_WINDOWS", 
        "ARCHITECTURE_32",
        "_DEBUG"
    }

filter {   
    "platforms:Win64",
    "configurations:Debug"
}
    system "Windows"
    systemversion "latest"
    architecture "x86_64"
    staticruntime "On"
    symbols "On"
    defines {
        "PLATFORM_WINDOWS", 
        "ARCHITECTURE_64",
        "_DEBUG"
    }

filter {   
    "platforms:Win32",
    "configurations:Release"
}
    system "Windows"
    systemversion "latest"
    architecture "x86"
    staticruntime "On"
    optimize "On"
    defines {
        "PLATFORM_WINDOWS", 
        "ARCHITECTURE_32"
    }

filter {   
    "platforms:Win64",
    "configurations:Release"
}
    system "Windows"
    systemversion "latest"
    architecture "x86_64"
    staticruntime "On"
    optimize "On"
    defines {
        "PLATFORM_WINDOWS", 
        "ARCHITECTURE_64"
    }




filter "system:windows"
    defines {
        "PLATFORM_WINDOWS"
    }




include "DragAPI_Core"
include "vendor/glfw"
include "DragAPI_Graphical"
include "DragAPI_Networking"
include "DragAPI_Math"
include "DragAPI"