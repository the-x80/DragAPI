printf("Creating DragAPI project.")
project("DragAPI")
language("C++")
kind("StaticLib")

targetdir(OutputDirectory)
objdir(ObjectDirectory .. "/%{prj.name}")

files
{
	"**.h",
	"**.cpp"
}

includedirs{
	"%{wks.location}/DragAPI_Core/include",
	"%{wks.location}/DragAPI_Graphical/include"
}
links{
	"DragAPI_Core",
	"DragAPI_Math",
	"DragAPI_Graphical",
	"DragAPI_Networking"
}