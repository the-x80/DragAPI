printf("Creating DragAPI_Core project.")
project("DragAPI_Core")
language("C++")
kind("StaticLib")

targetdir(OutputDirectory)
objdir(ObjectDirectory .. "/%{prj.name}")

files
{
	"**.h",
	"**.cpp"
}