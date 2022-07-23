printf("Creating DragAPI_Networking project.")
project("DragAPI_Networking")
language("C++")
kind("StaticLib")
links("DragAPI_Core")

targetdir(OutputDirectory)
objdir(ObjectDirectory .. "/%{prj.name}")

files
{
	"**.h",
	"**.cpp"
}

includedirs{
	"%{wks.location}/DragAPI_Core/include"
}
links{
	"DragAPI_Core"
}