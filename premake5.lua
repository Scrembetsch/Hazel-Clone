workspace "Lebakas"
    architecture 'x64'

    configurations
    {
        "Debug",
        "Release"
    }

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

project "Lebakas"
    location "Lebakas"
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

    postbuildcommands
    {
        ("{COPY} %{cfg.buildtarget.relpath} ../bin/" .. outputdir .. "/Sandbox")
    }

    filter "system:windows"
        cppdialect "C++17"
        staticruntime "On"
        systemversion "10.0"

        defines
        {
            "LEBAKAS_BUILD_DLL",
            "LEBAKAS_PLATFORM_WINDOWS"
        }

    filter "system:linux"
        cppdialect "C++17"
        staticruntime "On"

        defines
        {
            "LEBAKAS_PLATFORM_UNIX"
        }

        buildoptions 
        {
            "-fPIC"
        }

    filter "configurations:Debug"
        defines "LEBAKAS_DEBUG"
        symbols "On"

    filter "configurations:Release"
        defines "LEBAKAS_RELEASE"
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
        "Lebakas/vendor/spdlog/include",
        "Lebakas/src"
    }

    links
    {
        "Lebakas"
    }

    filter "system:windows"
        cppdialect "C++17"
        staticruntime "On"
        systemversion "10.0"

        defines
        {
            "LEBAKAS_PLATFORM_WINDOWS"
        }

    filter "system:linux"
        cppdialect "C++17"
        staticruntime "On"

        defines
        {
            "LEBAKAS_PLATFORM_UNIX"
        }

    filter "configurations:Debug"
        defines "LEBAKAS_DEBUG"
        symbols "On"

    filter "configurations:Release"
        defines "LEBAKAS_RELEASE"
        optimize "On"
