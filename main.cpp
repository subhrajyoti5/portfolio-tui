#include <ftxui/component/component.hpp>
#include <ftxui/component/screen_interactive.hpp>
#include <ftxui/dom/elements.hpp>
#include <string>
#include <vector>
#include <cstdlib>

using namespace ftxui;

void openBrowser(const std::string& url) {
#ifdef _WIN32
  system(("start " + url).c_str());
#elif __APPLE__
  system(("open " + url).c_str());
#else
  system(("xdg-open " + url).c_str());
#endif
}

int main() {
  auto screen = ScreenInteractive::Fullscreen();

  int selected = 0;
  std::vector<std::string> entries = {
    " About",
    " Projects",
    " Skills",
    " Experience",
    " Contact",
    " Resume"
  };

  auto menu = Menu(&entries, &selected);
  auto container = Container::Vertical({menu});

  auto renderer = Renderer(container, [&] {
    Element content;
    switch (selected) {
      case 0:
        content = vbox({
          text("Name: Subhrajyoti Sahoo"),
          text("Role: Backend Engineer"),
          text("University: KIIT University"),
          text("Focus: Backend Systems, Distributed Systems, Cloud Infrastructure"),
          separator(),
          text("Current Projects:"),
          text("  Shixa"),
          text("  Optima"),
          text("  BugRank"),
        });
        break;
      case 1:
        content = vbox({
          text("Shixa") | color(Color::Green1) | bold,
          text("  Coaching SaaS Platform"),
          text("  Features: Student Management, Fee Tracking, Attendance, Tests"),
          text("  Stack: React, PostgreSQL, AWS, Node.js"),
          separator(),
          text("Optima") | color(Color::Green1) | bold,
          text("  Productivity Operating System"),
          text("  Features: Tasks, Habits, Focus Sessions, Analytics"),
          text("  Stack: Flutter, Spring Boot, PostgreSQL"),
          separator(),
          text("BugRank") | color(Color::Green1) | bold,
          text("  Debugging Platform"),
          text("  Features: Coding Challenges, Containerized Execution, Leaderboards"),
          text("  Stack: Docker, Linux, PostgreSQL"),
        });
        break;
      case 2:
        content = vbox({
          text("Backend"),
          text("  Node.js, Java, Spring Boot"),
          separator(),
          text("Database"),
          text("  PostgreSQL, Prisma"),
          separator(),
          text("Cloud"),
          text("  AWS, Docker, Linux"),
          separator(),
          text("Frontend"),
          text("  Flutter, React"),
        });
        break;
      case 3:
        content = vbox({
          text("No professional experience listed yet."),
          text("Currently building Shixa, Optima, BugRank."),
        });
        break;
      case 4:
        content = vbox({
          text("GitHub: github.com/subhrajyoti5") | color(Color::Yellow1),
          text("LinkedIn: linkedin.com") | color(Color::Yellow1),
          text("Email: subhrajyotisahoo08@gmail.com") | color(Color::Yellow1),
        });
        break;
      case 5:
        content = vbox({
          text("Resume available online."),
          text("Press [r] to open."),
        });
        break;
    }

    return vbox({
      // Header
      text(" SUBHRA ") | bold | color(Color::Magenta1),
      text(" Backend Engineer ") | color(Color::Magenta1),
      separator(),
      // Main
      hbox({
        // Sidebar
        vbox({
          text(" SUBHRA ") | bold | center,
          separator(),
          menu->Render(),
        }) | border | size(WIDTH, EQUAL, 30),
        // Content
        vbox({
          text("PORTFOLIO") | bold | center,
          separator(),
          content,
        }) | flex | border,
      }),
      // Footer
      hbox({
        text(" [g] GitHub ") | color(Color::GrayDark),
        text(" [l] LinkedIn ") | color(Color::GrayDark),
        text(" [r] Resume ") | color(Color::GrayDark),
        text(" [q] Quit ") | color(Color::GrayDark),
      }),
    });
  });

  auto app = CatchEvent(renderer, [&](Event event) {
    if (event == Event::Character('q')) {
      screen.Exit();
      return true;
    }
    if (event == Event::Character('g')) {
      openBrowser("https://github.com/subhrajyoti5");
      return true;
    }
    if (event == Event::Character('l')) {
      openBrowser("https://linkedin.com");
      return true;
    }
    if (event == Event::Character('r')) {
      openBrowser("https://resume.url");
      return true;
    }
    return false;
  });

  screen.Loop(app);
}