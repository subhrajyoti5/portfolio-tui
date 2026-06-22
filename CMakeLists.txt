cmake_minimum_required(VERSION 3.14)
project(subhra_tui)

set(CMAKE_CXX_STANDARD 17)

include(FetchContent)

FetchContent_Declare(
  ftxui
  GIT_REPOSITORY https://github.com/ArthurSonzogni/FTXUI.git
  GIT_TAG v6.1.9
)

FetchContent_MakeAvailable(ftxui)

add_executable(subhra main.cpp)

target_link_libraries(
  subhra
  PRIVATE ftxui::screen
          ftxui::dom
          ftxui::component
)