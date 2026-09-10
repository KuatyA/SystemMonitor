cmake_minimum_required(VERSION 3.21)
project(sysmon LANGUAGES CXX)

include(FetchContent)
FetchContent_Declare(
    Slint
    GIT_REPOSITORY https://github.com/slint-ui/slint.git
    GIT_TAG release/1
    SOURCE_SUBDIR api/cpp
)
FetchContent_MakeAvailable(Slint)

add_executable(sysmon main.cpp
            Backend/Dynamic/dynamic_cpu.cpp 
            Backend/Dynamic/dynamic_gpu.cpp 
            Backend/Dynamic/dynamic_ram.cpp
            Backend/Dynamic/dynamic_system.cpp
            Backend/Dynamic/process_info.cpp
            
            Backend/Static/static_cpu.cpp
            Backend/Static/static_gpu.cpp
            Backend/Static/static_disk.cpp
            Backend/Static/static_ram.cpp
            Backend/Static/static_system.cpp)

slint_target_sources(sysmon UI/main_window.slint
                    UI/cpu_panel.slint
                    UI/gpu_panel.slint
                    UI/disk_panel.slint
                    UI/ram_panel.slint
                    UI/system_panel.slint
                    UI/process_panel.slint)

target_link_libraries(sysmon PRIVATE Slint::Slint)
