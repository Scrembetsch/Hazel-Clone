workspace "Hazel"
    architecture 'x64'

    configurations
    {
        "Debug",
        "Release"
    }

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

project "Hazel"
    location "Hazel"
    kind "SharedLib"
    language "C++"

    targetdir ("bin/" .. outputdir .. "/%{prj.name}")
    objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

    files
    {
        "%{prj.name}/src/**.h",
        "%{prj.name}/src/**.cpp"
    }

    includedirs
    {
        "%{prj.name}/vendor/spdlog/include"
    }

    filter "system:windows"
        cppdialect "C++17"
        staticruntime "On"
        systemversion "10.0"

        defines
        {
            "HAZEL_BUILD_DLL",
            "HAZEL_PLATFORM_WINDOWS"
        }

        postbuildcommands
        {
            ("{COPY} %{cfg.buildtarget.relpath} ../bin/" .. outputdir .. "/Sandbox")
        }

    filter "system:unix"
        cppdialect "C++17"
        staticruntime "On"

        defines
        {
            "HAZEL_BUILD_DLL",
            "HAZEL_PLATFORM_UNIX"
        }

        postbuildcommands
        {
            ("{COPY} %{cfg.buildtarget.relpath} ../bin/" .. outputdir .. "/Sandbox")
        }

    filter "configurations:Debug"
        defines "HAZEL_DEBUG"
        symbols "On"

    filter "configurations:Release"
        defines "HAZEL_RELEASE"
        optimize "On"

project "Sandbox"
    location "Sandbox"
    kind "ConsoleApp"
    language "C++"

    targetdir ("bin/" .. outputdir .. "/%{prj.name}")
    objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

    files
    {
        "%{prj.name}/src/**.h",
        "%{prj.name}/src/**.cpp"
    }

    includedirs
    {
        "Hazel/vendor/spdlog/include",
        "Hazel/src"
    }

    links
    {
        "Hazel"
    }

    filter "system:windows"
        cppdialect "C++17"
        staticruntime "On"
        systemversion "10.0"

        defines
        {
            "HAZEL_PLATFORM_WINDOWS"
        }

    filter "system:unix"
        cppdialect "C++17"
        staticruntime "On"

        defines
        {
            "HAZEL_PLATFORM_UNIX"
        }

    filter "configurations:Debug"
        defines "HAZEL_DEBUG"
        symbols "On"

    filter "configurations:Release"
        defines "HAZEL_RELEASE"
        optimize "On"
