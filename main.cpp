#include <ftxui/component/component.hpp>
#include <ftxui/component/screen_interactive.hpp>
#include <ftxui/dom/elements.hpp>

using namespace ftxui;

int main() {
    auto screen = ScreenInteractive::TerminalOutput();

    int selected = 0;

    std::vector<std::string> menu = {
        "About",
        "Projects",
        "Skills",
        "Contact",
        "Resume"
    };

    auto menu_component = Menu(&menu, &selected);

    auto container = Container::Vertical({
        menu_component,
    });

    auto renderer = Renderer(container, [&] {

        std::string content;

        switch (selected) {
            case 0:
                content =
                    "Backend Engineer\n\n"
                    "Building Shixa, Optima and BugRank.\n"
                    "KIIT CSE Data Science.";
                break;

            case 1:
                content =
                    "Shixa\n"
                    "Coaching SaaS\n\n"
                    "Optima\n"
                    "Productivity App\n\n"
                    "BugRank\n"
                    "Debugging Platform";
                break;

            case 2:
                content =
                    "C++\n"
                    "Node.js\n"
                    "PostgreSQL\n"
                    "Docker\n"
                    "AWS\n"
                    "Flutter";
                break;

            case 3:
                content =
                    "GitHub:\n"
                    "github.com/subhrajyoti5\n\n"
                    "Email:\n"
                    "subhrajyotisahoo08@gmail.com";
                break;

            case 4:
                content =
                    "Resume Coming Soon";
                break;
        }

        return hbox({
            vbox({
                text(" SUBHRA ") | bold | center,
                separator(),
                menu_component->Render(),
            }) | border | size(WIDTH, EQUAL, 30),

            vbox({
                text("PORTFOLIO") | bold | center,
                separator(),
                paragraph(content),
            }) | flex | border,
        });
    });

    screen.Loop(renderer);
}