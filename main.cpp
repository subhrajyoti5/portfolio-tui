#include <ftxui/component/component.hpp>
#include <ftxui/component/screen_interactive.hpp>
#include <ftxui/dom/elements.hpp>

using namespace ftxui;

int main() {
    auto screen = ScreenInteractive::TerminalOutput();

    auto component = Renderer([] {
        return vbox({
            text("SUBHRAJYOTI SAHOO") | bold,
            separator(),
            text("Backend Engineer"),
            text("Building Shixa, Optima, BugRank"),
        }) | border;
    });

    screen.Loop(component);
    return 0;
}