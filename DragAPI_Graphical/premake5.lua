printf("Creating DragAPI_Graphical project.")
project("DragAPI_Graphical")
	language("C++")
	kind("StaticLib")


	targetdir(OutputDirectory)
	objdir(ObjectDirectory .. "/%{prj.name}")

	filter "system:windows"
		defines {
			"PLATFORM_WINDOWS"
		}

	filter{}

	files
	{
		"**.h",
		"**.cpp"
	}

	includedirs{
		"%{wks.location}/DragAPI_Core/include",
		"%{wks.location}/vendor/glfw/include"
	}
	libdirs{
		OutputDirectory,
		OutputDirectory .. "/glfw/"
	}
	links{
		"DragAPI_Core",
		"GLFW",
		"opengl32.lib"
	}