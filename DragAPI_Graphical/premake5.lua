printf("Creating DragAPI_Graphical project.\n")
project("DragAPI_Graphical")
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
	"%{wks.location}/DragAPI_Core/include"
}
links{
	"DragAPI_Core"
}