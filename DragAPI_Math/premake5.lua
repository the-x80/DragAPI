printf("Creating DragAPI_Math project.")
project("DragAPI_Math")
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