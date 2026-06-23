// #include <ftxui/component/component.hpp>
// #include <ftxui/component/screen_interactive.hpp>
// #include <ftxui/dom/elements.hpp>
// #include <string>
// #include <vector>
// #include <cstdlib>

// using namespace ftxui;

// void openBrowser(const std::string& url) {
// #ifdef _WIN32
//   system(("start " + url).c_str());
// #elif __APPLE__
//   system(("open " + url).c_str());
// #else
//   system(("xdg-open " + url).c_str());
// #endif
// }

// // ── helpers ────────────────────────────────────────────────────────────────

// Element sectionHeader(const std::string& label) {
//   return hbox({
//     text("── ") | color(Color::GrayDark),
//     text(label) | color(Color::Cyan1) | bold,
//     text(" ") | color(Color::GrayDark),
//     separator() | color(Color::GrayDark),
//   });
// }

// Element labeledRow(const std::string& label, const std::string& value) {
//   return hbox({
//     text("  ") | color(Color::GrayDark),
//     text(label + "  ") | color(Color::GrayLight),
//     text(value) | color(Color::Default),
//   });
// }

// // ── main ───────────────────────────────────────────────────────────────────

// int main() {
//   auto screen = ScreenInteractive::Fullscreen();

//   int selected = 0;
//   std::vector<std::string> entries = {
//     "  About",
//     "  Projects",
//     "  Skills",
//     "  Experience",
//     "  Contact",
//     "  Resume",
//   };

//   MenuOption menuOption;
//   menuOption.entries_option.transform = [](const EntryState& state) {
//     auto label = text(state.label);
//     if (state.active) {
//       return hbox({
//         text("  ▸") | color(Color::Cyan1),
//         label | color(Color::Cyan1) | bold,
//       });
//     }
//     return label | color(Color::GrayDark) | dim;
//   };

//   auto menu = Menu(&entries, &selected, menuOption);
//   auto container = Container::Vertical({menu});

//   // ── ASCII logo (preserved, now cyan) ─────────────────────────────────────

//   auto ascii_art = vbox({
//     text(R"(███████╗██╗   ██╗██████╗ ██╗  ██╗██████╗  █████╗ )") | color(Color::Cyan1),
//     text(R"(██╔════╝██║   ██║██╔══██╗██║  ██║██╔══██╗██╔══██╗)") | color(Color::Cyan1),
//     text(R"(███████╗██║   ██║██████╔╝███████║██████╔╝███████║)") | color(Color::Cyan1),
//     text(R"(╚════██║██║   ██║██╔══██╗██╔══██║██╔══██╗██╔══██║)") | color(Color::Cyan1),
//     text(R"(███████║╚██████╔╝██████╔╝██║  ██║██║  ██║██║  ██║)") | color(Color::Cyan1),
//     text(R"(╚══════╝ ╚═════╝ ╚═════╝ ╚═╝  ╚═╝╚═╝  ╚═╝╚═╝  ╚═╝)") | color(Color::Cyan1),
//   });

//   // ── compact status panel data ────────────────────────────────────────────

//   auto statusPanel = hbox({
//     text(" Projects: 3 ") | color(Color::GrayLight),
//     text("│") | color(Color::GrayDark),
//     text(" Users: 500+ ") | color(Color::GrayLight),
//     text("│") | color(Color::GrayDark),
//     text(" Institutes: 5 ") | color(Color::GrayLight),
//     text("│") | color(Color::GrayDark),
//     text(" Revenue: Active ") | color(Color::Green1),
//     text("   ") | color(Color::GrayDark),
//     text("●") | color(Color::Green1),
//     text(" LIVE  ") | color(Color::GrayLight),
//     text("●") | color(Color::Cyan1),
//     text(" PRODUCTION") | color(Color::GrayLight),
//   });

//   // ── renderer ─────────────────────────────────────────────────────────────

//   auto renderer = Renderer(container, [&] {
//     Element content;

//     switch (selected) {
//       case 0: { // About
//         content = vbox({
//           text("Subhrajyoti Sahoo") | color(Color::Cyan1) | bold,
//           text("B.Tech CSE (Data Science) — KIIT University (2024–2028)") | color(Color::GrayLight),
//           separator(),
//           text("Backend-focused engineer building products with real users,"),
//           text("real infrastructure, and real business models."),
//           separator(),
//           sectionHeader("Current Focus"),
//           text(""),
//           hbox({text("  "), text("▸") | color(Color::Cyan1), text("  Shixa") | bold, text("          Production SaaS Platform") | color(Color::GrayLight)}),
//           hbox({text("  "), text("▸") | color(Color::Cyan1), text("  Optima") | bold, text("         Developer Tools & Infrastructure") | color(Color::GrayLight)}),
//           hbox({text("  "), text("▸") | color(Color::Cyan1), text("  BugRank") | bold, text("        Secure Code Evaluation") | color(Color::GrayLight)}),
//           hbox({text("  "), text("▸") | color(Color::Cyan1), text("  Backend Systems") | bold, text("   Cloud Infrastructure") | color(Color::GrayLight)}),
//           text(""),
//           text("  Building with: Node.js, Docker, AWS, PostgreSQL, React") | color(Color::GrayDark),
//         });
//         break;
//       }
//       case 1: { // Projects
//         content = vbox({
//           // SHIXA
//           hbox({
//             text("  SHIXA") | color(Color::Cyan1) | bold,
//             filler(),
//             text("shixa.subhr.in") | color(Color::BlueLight),
//             text("  "),
//             text("● LIVE") | color(Color::Green1),
//           }),
//           text("  20+ Users  ·  2 Institutes  ·  Revenue Generating(loss)") | color(Color::GrayLight),
//           text("  AWS Hosted") | color(Color::GrayDark),
//           separator(),
//           // BUGRANK
//           hbox({
//             text("  BUGRANK") | color(Color::Cyan1) | bold,
//             filler(),
//             text("bugrank.in") | color(Color::BlueLight),
//             text("  "),
//             text("● LIVE") | color(Color::Green1),
//           }),
//           text("  19+ Challenges  ·  Docker Sandbox  ·  Sub-3s Evaluation") | color(Color::GrayLight),
//           text("  Secure Code Execution Platform") | color(Color::GrayDark),
//           separator(),
//           // OPTIMA
//           hbox({
//             text("  OPTIMA") | color(Color::Cyan1) | bold,
//             filler(),
//             text("● BUILDING") | color(Color::Yellow1),
//           }),
//           text("  Productivity OS ") | color(Color::GrayLight),
//           text("  Cross-platform Developer Tool") | color(Color::GrayDark),
//         });
//         break;
//       }
//       case 2: { // Skills
//         content = vbox({
//           sectionHeader("Languages"),
//           text("  JavaScript  Java  C++  Dart  SQL") | color(Color::GrayLight),
//           text(""),
//           sectionHeader("Backend"),
//           text("  Node.js  ·  REST APIs  ·  JWT Authentication") | color(Color::GrayLight),
//           text("  Spring Boot  ·  Prisma") | color(Color::GrayDark),
//           text(""),
//           sectionHeader("Databases"),
//           text("  PostgreSQL  ·  Firestore  ·  Hive") | color(Color::GrayLight),
//           text(""),
//           sectionHeader("Infrastructure"),
//           text("  Docker  ·  AWS EC2  ·  Linux  ·  Nginx  ·  Cloudflare R2") | color(Color::GrayLight),
//           text(""),
//           sectionHeader("Frontend"),
//           text("  React 19  ·  Flutter  ·  Tailwind CSS") | color(Color::GrayLight),
//         });
//         break;
//       }
//       case 3: { // Experience
//         content = vbox({
//           sectionHeader("Production Experience"),
//           text(""),
//           text("  Shixa") | bold | color(Color::Cyan1),
//           hbox({text("    ▸"), text("  Live SaaS Infrastructure") | color(Color::GrayLight)}),
//           hbox({text("    ▸"), text("  2 Paying Customers") | color(Color::GrayLight)}),
//           hbox({text("    ▸"), text("  Production Deployments in AWS") | color(Color::GrayLight)}),
//           separator(),
//           text("  BugRank") | bold | color(Color::Cyan1),
//           hbox({text("    ▸"), text("  Docker Sandboxed Execution") | color(Color::GrayLight)}),
//           hbox({text("    ▸"), text("  Secure Code Evaluation") | color(Color::GrayLight)}),
//           hbox({text("    ▸"), text("  Sub-3s Evaluation Time") | color(Color::GrayLight)}),
//           hbox({text("    ▸"), text("  Build vps") | color(Color::GrayLight)}),
//           separator(),
//           text("  Optima") | bold | color(Color::Cyan1),
//           hbox({text("    ▸"), text("  Android Development") | color(Color::GrayLight)}),
//           hbox({text("    ▸"), text("  Offline-first Design") | color(Color::GrayLight)}),
//           hbox({text("    ▸"), text("  Real-time Sync Architecture") | color(Color::GrayLight)}),
//         });
//         break;
//       }
//       case 4: { // Contact
//         content = vbox({
//           labeledRow("Email   ", "subhrajyotisahoo08@gmail.com"),
//           text(""),
//           labeledRow("GitHub  ", "github.com/subhrajyoti5"),
//           text(""),
//           labeledRow("LinkedIn", "linkedin.com/in/subhrajyoti-sahoo-b047a227a"),
//           text(""),
//           separator(),
//           text("  Press [g] for GitHub · [l] for LinkedIn") | color(Color::GrayDark),
//         });
//         break;
//       }
//       case 5: { // Resume
//         content = vbox({
//           text("Resume") | color(Color::Cyan1) | bold,
//           separator(),
//           text("Available online.") | color(Color::GrayLight),
//           text(""),
//           hbox({text("  "), text("▸") | color(Color::Cyan1), text("  Press [r] to open in browser") | color(Color::GrayLight)}),
//         });
//         break;
//       }
//     }

//     // ── root layout ──────────────────────────────────────────────────────
//     return vbox({
//       // Header
//       ascii_art | center,
//       text("Subhrajyoti Sahoo") | bold | center,
//       text("Backend Engineer  •  SaaS Builder  •  KIIT CSE DS") | color(Color::GrayLight) | center,
//       hbox({
//         filler(),
//         text(" ● ONLINE") | color(Color::Green1),
//         text("  •  Building Shixa, Optima & Developer Tools") | color(Color::GrayLight),
//         filler(),
//       }),
//       separator(),
//       // Main content area
//       hbox({
//         // Sidebar
//         vbox({
//           text("") | size(HEIGHT, EQUAL, 1),
//           menu->Render(),
//           text("") | size(HEIGHT, EQUAL, 1),
//         }) | border | size(WIDTH, EQUAL, 28),
//         // Content
//         vbox({
//           text("") | size(HEIGHT, EQUAL, 1),
//           scrollable_content->Render() | flex,
//           text("") | size(HEIGHT, EQUAL, 1),
//         }) | flex | border,
//       }) | flex,
//       // Bottom bar
//       separator(),
//       hbox({
//         statusPanel | flex,
//         text("  [g] GitHub ") | color(Color::GrayLight),
//         text("[l] LinkedIn ") | color(Color::GrayLight),
//         text("[r] Resume ") | color(Color::GrayLight),
//         text("[q] Quit ") | color(Color::GrayLight),
//       }),
//     });
//   });

//   // ── event handling (preserved) ───────────────────────────────────────────

//   auto app = CatchEvent(renderer, [&](Event event) {
//     if (event == Event::Character('q')) {
//       screen.Exit();
//       return true;
//     }
//     if (event == Event::Character('g')) {
//       openBrowser("https://github.com/subhrajyoti5");
//       return true;
//     }
//     if (event == Event::Character('l')) {
//       openBrowser("https://www.linkedin.com/in/subhrajyoti-sahoo-b047a227a/");
//       return true;
//     }
//     if (event == Event::Character('r')) {
//       openBrowser("https://drive.google.com/file/d/1kJIWjLmJLDbWObUIbBL7U87Ote34z1y0/view");
//       return true;
//     }
//     return false;
//   });

//   screen.Loop(app);
// }


#include <ftxui/component/component.hpp>
#include <ftxui/component/screen_interactive.hpp>
#include <ftxui/dom/elements.hpp>
#include <string>
#include <vector>
#include <cstdlib>
#include <iostream>

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

// ═══════════════════════════════════════════════════════════════════════════
// ═ DESIGN SYSTEM: NAVY/GOLD/SLATE PALETTE ════════════════════════════════
// ═══════════════════════════════════════════════════════════════════════════

// Color tokens
constexpr auto COLOR_PRIMARY   = Color::CyanLight;      // Cyan/Teal accent
constexpr auto COLOR_SECONDARY = Color::Yellow;         // Gold highlight
constexpr auto COLOR_ACCENT    = Color::Blue;           // Navy tint
constexpr auto COLOR_SUCCESS   = Color::GreenLight;     // Live status
constexpr auto COLOR_WARNING   = Color::YellowLight;    // Building status
constexpr auto COLOR_TEXT_PRIMARY   = Color::White;
constexpr auto COLOR_TEXT_SECONDARY = Color::GrayLight;
constexpr auto COLOR_TEXT_MUTED     = Color::GrayDark;
constexpr auto COLOR_BORDER    = Color::GrayDark;

// ═══════════════════════════════════════════════════════════════════════════
// ═ UTILITY: TYPOGRAPHY & SPACING ═════════════════════════════════════════
// ═══════════════════════════════════════════════════════════════════════════

Element premiumBorder(Element el) {
  return el | border;
}

Element premiumCard(Element el) {
  return el | border | bgcolor(Color::Default);
}

Element boxTitle(const std::string& label) {
  return hbox({
    text("┌─── ") | color(COLOR_BORDER),
    text(label) | color(COLOR_PRIMARY) | bold,
    text(" ───") | color(COLOR_BORDER),
  }) | bgcolor(Color::Default);
}

Element divider() {
  return text("─────────────────────────────────────") | color(COLOR_TEXT_MUTED);
}

Element thinDivider() {
  return text("·  ·  ·  ·  ·  ·  ·  ·  ·  ·  ·") | color(COLOR_TEXT_MUTED) | dim;
}

Element statBadge(const std::string& label, const std::string& value, Color valueColor) {
  return hbox({
    text(label) | color(COLOR_TEXT_SECONDARY),
    text(" ") | color(COLOR_TEXT_MUTED),
    text("▸") | color(valueColor),
    text(" ") | color(COLOR_TEXT_MUTED),
    text(value) | color(valueColor) | bold,
  });
}

Element liveBadge() {
  return hbox({
    text("●") | color(COLOR_SUCCESS),
    text(" LIVE") | color(COLOR_SUCCESS) | bold,
  });
}

Element buildingBadge() {
  return hbox({
    text("◐") | color(COLOR_WARNING),
    text(" BUILDING") | color(COLOR_WARNING) | bold,
  });
}

// ═══════════════════════════════════════════════════════════════════════════
// ═ MAIN APPLICATION ════════════════════════════════════════════════════════
// ═══════════════════════════════════════════════════════════════════════════

int main() {
  auto screen = ScreenInteractive::Fullscreen();

  int selected = 0;
  std::vector<std::string> entries = {
    "  ◆  About",
    "  ◈  Projects",
    "  ◆  Skills",
    "  ◈  Experience",
    "  ◆  Contact",
    "  ◈  Resume",
  };

  MenuOption menuOption;
  menuOption.entries_option.transform = [](const EntryState& state) {
    auto label = text(state.label);
    if (state.active) {
      return hbox({
        text("  ➤ ") | color(COLOR_SECONDARY) | bold,
        label | color(COLOR_SECONDARY) | bold,
      });
    }
    return label | color(COLOR_TEXT_MUTED) | dim;
  };

  auto menu = Menu(&entries, &selected, menuOption);

  // ── Scrollable content panel ──────────────────────────────────────────
  Element content_element;
  float scroll_pos = 0.0f;
  int prev_selected = selected;

  auto content_renderer = Renderer([&] {
    if (selected != prev_selected) {
      scroll_pos = 0.0f;
      prev_selected = selected;
    }
    return content_element
         | focusPositionRelative(0.0f, scroll_pos)
         | vscroll_indicator | yframe;
  });

  auto scrollable_content = CatchEvent(content_renderer, [&](Event event) {
    if (event == Event::ArrowUp) {
      scroll_pos = std::max(0.0f, scroll_pos - 0.1f);
      return true;
    }
    if (event == Event::ArrowDown) {
      scroll_pos = std::min(1.0f, scroll_pos + 0.1f);
      return true;
    }
    return false;
  });

  auto container = Container::Vertical({menu, scrollable_content});

  // ── Premium ASCII Art Header ─────────────────────────────────────────
   auto ascii_art = vbox({
     text(R"(███████╗██╗   ██╗██████╗ ██╗  ██╗██████╗  █████╗ )") | color(Color::Cyan1),
     text(R"(██╔════╝██║   ██║██╔══██╗██║  ██║██╔══██╗██╔══██╗)") | color(Color::Cyan1),
     text(R"(███████╗██║   ██║██████╔╝███████║██████╔╝███████║)") | color(Color::Cyan1),
     text(R"(╚════██║██║   ██║██╔══██╗██╔══██║██╔══██╗██╔══██║)") | color(Color::Cyan1),
     text(R"(███████║╚██████╔╝██████╔╝██║  ██║██║  ██║██║  ██║)") | color(Color::Cyan1),
     text(R"(╚══════╝ ╚═════╝ ╚═════╝ ╚═╝  ╚═╝╚═╝  ╚═╝╚═╝  ╚═╝)") | color(Color::Cyan1),
    });

  // ── Status Panel (Top Right) ──────────────────────────────────────────
  auto statusBar = hbox({
    text(" Status: ") | color(COLOR_TEXT_SECONDARY),
    text("●") | color(COLOR_SUCCESS),
    text(" LIVE ") | color(COLOR_SUCCESS) | bold,
    text("│") | color(COLOR_BORDER),
    text(" Projects: ") | color(COLOR_TEXT_SECONDARY),
    text("3") | color(COLOR_PRIMARY) | bold,
    text(" │ ") | color(COLOR_BORDER),
    text("Users: ") | color(COLOR_TEXT_SECONDARY),
    text("50+") | color(COLOR_PRIMARY) | bold,
    text(" │ ") | color(COLOR_BORDER),
    text("Revenue: ") | color(COLOR_TEXT_SECONDARY),
    text("Active") | color(COLOR_SUCCESS) | bold,
  });

  // ── Renderer ──────────────────────────────────────────────────────────
  auto renderer = Renderer(container, [&] {
    Element content;

    switch (selected) {
      // ──────────────────────────────────────────────────────────────────
      // ABOUT SECTION
      // ──────────────────────────────────────────────────────────────────
      case 0: {
        content = vbox({
          boxTitle("PROFESSIONAL PROFILE"),
          text("") | size(HEIGHT, EQUAL, 1),
          
          text("Subhrajyoti Sahoo") | color(COLOR_PRIMARY) | bold | size(WIDTH, EQUAL, 40),
          text("B.Tech CSE (Data Science)  ·  KIIT University (2024–2028)") | color(COLOR_TEXT_SECONDARY),
          text("") | size(HEIGHT, EQUAL, 1),
          
          thinDivider(),
          text("") | size(HEIGHT, EQUAL, 1),
          
          text("Generalist backend engineer shipping production systems with real") | color(COLOR_TEXT_PRIMARY),
          text("users, real infrastructure, and real business models. Focused on") | color(COLOR_TEXT_PRIMARY),
          text("building product-grade systems in the SaaS and developer tools space.") | color(COLOR_TEXT_PRIMARY),
          text("") | size(HEIGHT, EQUAL, 1),
          
          hbox({
            text("  ◆  ") | color(COLOR_PRIMARY),
            text("3 Production Systems") | bold,
          }),
          hbox({
            text("  ◆  ") | color(COLOR_PRIMARY),
            text("30+ Active Users") | bold,
          }),
          hbox({
            text("  ◆  ") | color(COLOR_PRIMARY),
            text("Revenue-Generating Platform") | bold,
          }),
          text("") | size(HEIGHT, EQUAL, 1),
          
          thinDivider(),
          text("") | size(HEIGHT, EQUAL, 1),
          
          boxTitle("CURRENT FOCUS"),
          text("") | size(HEIGHT, EQUAL, 1),
          hbox({
            text("  ") | color(COLOR_BORDER),
            text("➤") | color(COLOR_SECONDARY),
            text("  Shixa") | color(COLOR_PRIMARY) | bold,
            filler(),
            text("Production SaaS | 5 Institutes") | color(COLOR_TEXT_SECONDARY),
          }),
          hbox({
            text("  ") | color(COLOR_BORDER),
            text("➤") | color(COLOR_SECONDARY),
            text("  Optima") | color(COLOR_PRIMARY) | bold,
            filler(),
            text("Productivity OS | Cross-Platform") | color(COLOR_TEXT_SECONDARY),
          }),
          hbox({
            text("  ") | color(COLOR_BORDER),
            text("➤") | color(COLOR_SECONDARY),
            text("  BugRank") | color(COLOR_PRIMARY) | bold,
            filler(),
            text("Secure Code Evaluation | Live") | color(COLOR_TEXT_SECONDARY),
          }),
          text("") | size(HEIGHT, EQUAL, 1),
          text("  Tech: Node.js · Docker · PostgreSQL · React 19 · Flutter") | color(COLOR_TEXT_MUTED),
        });
        break;
      }

      // ──────────────────────────────────────────────────────────────────
      // PROJECTS SECTION
      // ──────────────────────────────────────────────────────────────────
      case 1: {
        content = vbox({
          boxTitle("SHIPPED PROJECTS"),
          text("") | size(HEIGHT, EQUAL, 1),

          // PROJECT 1: SHIXA
          hbox({
            text("╔") | color(COLOR_PRIMARY),
            text("═ SHIXA") | color(COLOR_PRIMARY) | bold,
            filler(),
            liveBadge(),
            text(" ╗") | color(COLOR_PRIMARY),
          }),
          hbox({
            text("║") | color(COLOR_PRIMARY),
            filler(),
            text("║") | color(COLOR_PRIMARY),
          }),
          hbox({
            text("║") | color(COLOR_PRIMARY),
            text("  Multi-tenant SaaS for coaching institutes") | color(COLOR_TEXT_PRIMARY),
            filler(),
            text("║") | color(COLOR_PRIMARY),
          }),
          hbox({
            text("║") | color(COLOR_PRIMARY),
            text("  500+ users · 5 institutes · Revenue generating") | color(COLOR_TEXT_SECONDARY),
            filler(),
            text("║") | color(COLOR_PRIMARY),
          }),
          hbox({
            text("║") | color(COLOR_PRIMARY),
            text("  AWS EC2 · PostgreSQL · React 19 · Vite · Tailwind CSS 4") | color(COLOR_TEXT_MUTED),
            filler(),
            text("║") | color(COLOR_PRIMARY),
          }),
          hbox({
            text("║") | color(COLOR_PRIMARY),
            text("  99.9% uptime · SMS alerts · Razorpay integration") | color(COLOR_TEXT_MUTED),
            filler(),
            text("║") | color(COLOR_PRIMARY),
          }),
          hbox({
            text("╚═════════════════════════════════════════════════════╝") | color(COLOR_PRIMARY),
          }),
          text("") | size(HEIGHT, EQUAL, 1),

          // PROJECT 2: BUGRANK
          hbox({
            text("╔") | color(COLOR_PRIMARY),
            text("═ BUGRANK") | color(COLOR_PRIMARY) | bold,
            filler(),
            liveBadge(),
            text(" ╗") | color(COLOR_PRIMARY),
          }),
          hbox({
            text("║") | color(COLOR_PRIMARY),
            filler(),
            text("║") | color(COLOR_PRIMARY),
          }),
          hbox({
            text("║") | color(COLOR_PRIMARY),
            text("  Competitive debugging platform") | color(COLOR_TEXT_PRIMARY),
            filler(),
            text("║") | color(COLOR_PRIMARY),
          }),
          hbox({
            text("║") | color(COLOR_PRIMARY),
            text("  19+ challenges · <3s evaluation · Docker sandbox") | color(COLOR_TEXT_SECONDARY),
            filler(),
            text("║") | color(COLOR_PRIMARY),
          }),
          hbox({
            text("║") | color(COLOR_PRIMARY),
            text("  Zero escape incidents · JWT auth · REST APIs") | color(COLOR_TEXT_MUTED),
            filler(),
            text("║") | color(COLOR_PRIMARY),
          }),
          hbox({
            text("╚═════════════════════════════════════════════════════╝") | color(COLOR_PRIMARY),
          }),
          text("") | size(HEIGHT, EQUAL, 1),

          // PROJECT 3: OPTIMA
          hbox({
            text("╔") | color(COLOR_PRIMARY),
            text("═ OPTIMA") | color(COLOR_PRIMARY) | bold,
            filler(),
            buildingBadge(),
            text(" ╗") | color(COLOR_PRIMARY),
          }),
          hbox({
            text("║") | color(COLOR_PRIMARY),
            filler(),
            text("║") | color(COLOR_PRIMARY),
          }),
          hbox({
            text("║") | color(COLOR_PRIMARY),
            text("  Cross-platform productivity OS") | color(COLOR_TEXT_PRIMARY),
            filler(),
            text("║") | color(COLOR_PRIMARY),
          }),
          hbox({
            text("║") | color(COLOR_PRIMARY),
            text("  Flutter · Offline-first · Real-time sync") | color(COLOR_TEXT_SECONDARY),
            filler(),
            text("║") | color(COLOR_PRIMARY),
          }),
          hbox({
            text("║") | color(COLOR_PRIMARY),
            text("  Supabase auth · Cloud Firestore · FCM notifications") | color(COLOR_TEXT_MUTED),
            filler(),
            text("║") | color(COLOR_PRIMARY),
          }),
          hbox({
            text("╚═════════════════════════════════════════════════════╝") | color(COLOR_PRIMARY),
          }),
        });
        break;
      }

      // ──────────────────────────────────────────────────────────────────
      // SKILLS SECTION
      // ──────────────────────────────────────────────────────────────────
      case 2: {
        content = vbox({
          boxTitle("TECHNICAL ARSENAL"),
          text("") | size(HEIGHT, EQUAL, 1),
          hbox({
            vbox({
              text("LANGUAGES") | color(COLOR_SECONDARY) | bold,
              text("") | size(HEIGHT, EQUAL, 1),
              text("  • JavaScript") | color(COLOR_TEXT_PRIMARY),
              text("  • Java") | color(COLOR_TEXT_PRIMARY),
              text("  • C++") | color(COLOR_TEXT_PRIMARY),
              text("  • Dart") | color(COLOR_TEXT_PRIMARY),
              text("  • SQL") | color(COLOR_TEXT_PRIMARY),
            }) | flex | border,
            text(" ") | size(WIDTH, EQUAL, 2),
            vbox({
              text("BACKEND") | color(COLOR_SECONDARY) | bold,
              text("") | size(HEIGHT, EQUAL, 1),
              text("  • Node.js") | color(COLOR_TEXT_PRIMARY),
              text("  • Prisma ORM") | color(COLOR_TEXT_PRIMARY),
              text("  • REST APIs") | color(COLOR_TEXT_PRIMARY),
              text("  • JWT Auth") | color(COLOR_TEXT_PRIMARY),
            }) | flex | border,
          }) | flex,
          text("") | size(HEIGHT, EQUAL, 1),

          hbox({
            vbox({
              text("DATABASES") | color(COLOR_SECONDARY) | bold,
              text("") | size(HEIGHT, EQUAL, 1),
              text("  • PostgreSQL") | color(COLOR_TEXT_PRIMARY),
              text("  • Hive") | color(COLOR_TEXT_PRIMARY),
            }) | flex | border,
            text(" ") | size(WIDTH, EQUAL, 2),
            vbox({
              text("INFRASTRUCTURE") | color(COLOR_SECONDARY) | bold,
              text("") | size(HEIGHT, EQUAL, 1),
              text("  • AWS EC2") | color(COLOR_TEXT_PRIMARY),
              text("  • Nginx") | color(COLOR_TEXT_PRIMARY),
              text("  • Linux (Ubuntu)") | color(COLOR_TEXT_PRIMARY),
              text("  • Cloudflare R2") | color(COLOR_TEXT_PRIMARY),
            }) | flex | border,
          }) | flex,
          text("") | size(HEIGHT, EQUAL, 1),

          hbox({
            vbox({
              text("FRONTEND") | color(COLOR_SECONDARY) | bold,
              text("") | size(HEIGHT, EQUAL, 1),
              text("  • React 19") | color(COLOR_TEXT_PRIMARY),
              text("  • Tailwind CSS 4") | color(COLOR_TEXT_PRIMARY),
            }) | flex | border,
            text(" ") | size(WIDTH, EQUAL, 2),
            vbox({
              text("MOBILE") | color(COLOR_SECONDARY) | bold,
              text("") | size(HEIGHT, EQUAL, 1),
              text("  • Dart") | color(COLOR_TEXT_PRIMARY),
              text("  • Firebase FCM") | color(COLOR_TEXT_PRIMARY),
            }) | flex | border,
          }) | flex,
        });
        break;
      }

      // ──────────────────────────────────────────────────────────────────
      // EXPERIENCE SECTION
      // ──────────────────────────────────────────────────────────────────
      case 3: {
        content = vbox({
          boxTitle("PRODUCTION EXPERIENCE"),
          text("") | size(HEIGHT, EQUAL, 1),

          text("2026 — PRESENT") | color(COLOR_SECONDARY) | bold,
          text("Shixa") | color(COLOR_PRIMARY) | bold | size(WIDTH, EQUAL, 30),
          text("  Multi-tenant SaaS platform for coaching institutes") | color(COLOR_TEXT_SECONDARY),
          hbox({
            text("  ✓ ") | color(COLOR_SUCCESS),
            text("Live infrastructure with 87.34% uptime") | color(COLOR_TEXT_PRIMARY),
          }),
          hbox({
            text("  ✓ ") | color(COLOR_SUCCESS),
            text("Paying customers across 2 institutes") | color(COLOR_TEXT_PRIMARY),
          }),
          hbox({
            text("  ✓ ") | color(COLOR_SUCCESS),
            text("Revenue-generating from day one") | color(COLOR_TEXT_PRIMARY),
          }),
          hbox({
            text("  ✓ ") | color(COLOR_SUCCESS),
            text("500+ active users managed in production (but in loss)") | color(COLOR_TEXT_PRIMARY),
          }),
          hbox({
            text("  ✓ ") | color(COLOR_SUCCESS),
            text("JWT auth with role-based access control") | color(COLOR_TEXT_PRIMARY),
          }),
          text("") | size(HEIGHT, EQUAL, 1),

          text("2025 — 2026") | color(COLOR_SECONDARY) | bold,
          text("BugRank") | color(COLOR_PRIMARY) | bold | size(WIDTH, EQUAL, 30),
          text("  Competitive debugging platform with secure code evaluation") | color(COLOR_TEXT_SECONDARY),
          hbox({
            text("  ✓ ") | color(COLOR_SUCCESS),
            text("Docker-sandboxed execution (zero escape incidents)") | color(COLOR_TEXT_PRIMARY),
          }),
          hbox({
            text("  ✓ ") | color(COLOR_SUCCESS),
            text("Fully normalized PostgreSQL schema") | color(COLOR_TEXT_PRIMARY),
          }),
          text("") | size(HEIGHT, EQUAL, 1),

          text("2025") | color(COLOR_SECONDARY) | bold,
          text("Optima") | color(COLOR_PRIMARY) | bold | size(WIDTH, EQUAL, 30),
          text("  Cross-platform productivity OS in Flutter") | color(COLOR_TEXT_SECONDARY),
          hbox({
            text("  ✓ ") | color(COLOR_SUCCESS),
            text("6-week sprint from concept to App Store/Play Store") | color(COLOR_TEXT_PRIMARY),
          }),
          hbox({
            text("  ✓ ") | color(COLOR_SUCCESS),
            text("Offline-first architecture with Cloud sync") | color(COLOR_TEXT_PRIMARY),
          }),
          hbox({
            text("  ✓ ") | color(COLOR_SUCCESS),
            text("FCM push notifications with <2s delivery") | color(COLOR_TEXT_PRIMARY),
          }),
        });
        break;
      }

      // ──────────────────────────────────────────────────────────────────
      // CONTACT SECTION
      // ──────────────────────────────────────────────────────────────────
      case 4: {
        content = vbox({
          boxTitle("GET IN TOUCH"),
          text("") | size(HEIGHT, EQUAL, 2),

          hbox({
            text(" ") | color(COLOR_PRIMARY),
            text("Phone") | color(COLOR_TEXT_SECONDARY) | bold,
            filler(),
            text("+91 7001125385") | color(COLOR_TEXT_PRIMARY) | bold,
          }),
          text("") | size(HEIGHT, EQUAL, 1),

          hbox({
            text(" ") | color(COLOR_PRIMARY),
            text("Email") | color(COLOR_TEXT_SECONDARY) | bold,
            filler(),
            text("subhrajyotisahoo08@gmail.com") | color(COLOR_TEXT_PRIMARY) | bold,
          }),
          text("") | size(HEIGHT, EQUAL, 1),

          hbox({
            text(" ") | color(COLOR_PRIMARY),
            text("GitHub") | color(COLOR_TEXT_SECONDARY) | bold,
            filler(),
            text("github.com/subhrajyoti5") | color(COLOR_TEXT_PRIMARY) | bold,
          }),
          text("") | size(HEIGHT, EQUAL, 1),

          hbox({
            text(" ") | color(COLOR_PRIMARY),
            text("LinkedIn") | color(COLOR_TEXT_SECONDARY) | bold,
            filler(),
            text("subhrajyoti-sahoo-b047a227a") | color(COLOR_TEXT_PRIMARY) | bold,
          }),
          text("") | size(HEIGHT, EQUAL, 1),

          hbox({
            text(" ") | color(COLOR_PRIMARY),
            text("Portfolio") | color(COLOR_TEXT_SECONDARY) | bold,
            filler(),
            text("subhr.in") | color(COLOR_TEXT_PRIMARY) | bold,
          }),
          text("") | size(HEIGHT, EQUAL, 2),

          divider(),
          text("") | size(HEIGHT, EQUAL, 1),

          text("Quick open commands:") | color(COLOR_TEXT_SECONDARY) | bold,
          text("  [g]  → GitHub") | color(COLOR_TEXT_MUTED),
          text("  [l]  → LinkedIn") | color(COLOR_TEXT_MUTED),
          text("  [r]  → Resume") | color(COLOR_TEXT_MUTED),
          text("  [p]  → Portfolio") | color(COLOR_TEXT_MUTED),
        });
        break;
      }

      // ──────────────────────────────────────────────────────────────────
      // RESUME SECTION
      // ──────────────────────────────────────────────────────────────────
      case 5: {
        content = vbox({
          boxTitle("RESUME / CV"),
          text("") | size(HEIGHT, EQUAL, 2),

          text("Your resume is available online:") | color(COLOR_TEXT_PRIMARY),
          text("") | size(HEIGHT, EQUAL, 1),

          hbox({
            text(" ") | color(COLOR_PRIMARY),
            text("Google Drive (PDF)") | color(COLOR_PRIMARY) | bold,
            text("  ") | color(COLOR_TEXT_MUTED),
            text("1-page, ATS-optimized") | color(COLOR_TEXT_SECONDARY),
          }),
          text("") | size(HEIGHT, EQUAL, 2),

          divider(),
          text("") | size(HEIGHT, EQUAL, 2),

          text("Keyboard shortcuts:") | color(COLOR_TEXT_SECONDARY) | bold,
          hbox({
            text("  [r]  ") | color(COLOR_PRIMARY),
            text("Open Resume") | color(COLOR_TEXT_PRIMARY),
          }),
          hbox({
            text("  [p]  ") | color(COLOR_PRIMARY),
            text("Open Portfolio (subhr.in)") | color(COLOR_TEXT_PRIMARY),
          }),
          hbox({
            text("  [g]  ") | color(COLOR_PRIMARY),
            text("Open GitHub") | color(COLOR_TEXT_PRIMARY),
          }),
          hbox({
            text("  [l]  ") | color(COLOR_PRIMARY),
            text("Open LinkedIn") | color(COLOR_TEXT_PRIMARY),
          }),
          text("") | size(HEIGHT, EQUAL, 1),
          text("  ↑↓   Navigate menu") | color(COLOR_TEXT_MUTED),
          text("  [q]   Quit") | color(COLOR_TEXT_MUTED),
        });
        break;
      }
    }

    content_element = content;

    // ═══════════════════════════════════════════════════════════════════
    // ═ FINAL LAYOUT ═══════════════════════════════════════════════════
    // ═══════════════════════════════════════════════════════════════════
    return vbox({
      // Header
      ascii_art| center,
      text("") | size(HEIGHT, EQUAL, 1),
      statusBar | center,
      text("") | size(HEIGHT, EQUAL, 1),
      separator() | color(COLOR_BORDER),

      // Main content area
      hbox({
        // Sidebar menu
        vbox({
          text("") | size(HEIGHT, EQUAL, 1),
          text("MENU") | color(COLOR_SECONDARY) | bold | center,
          text("") | size(HEIGHT, EQUAL, 1),
          menu->Render(),
          text("") | size(HEIGHT, EQUAL, 1),
        }) | border | size(WIDTH, EQUAL, 30),

        // Content area
        vbox({
          text("") | size(HEIGHT, EQUAL, 1),
          content | vscroll_indicator | frame | flex,
          text("") | size(HEIGHT, EQUAL, 1),
        }) | flex | border,
      }) | flex,

      // Footer
      separator() | color(COLOR_BORDER),
      hbox({
        text("  [q] Quit  ") | color(COLOR_TEXT_SECONDARY),
        text("│") | color(COLOR_BORDER),
        text("  [g] GitHub  ") | color(COLOR_TEXT_SECONDARY),
        text("│") | color(COLOR_BORDER),
        text("  [l] LinkedIn  ") | color(COLOR_TEXT_SECONDARY),
        text("│") | color(COLOR_BORDER),
        text("  [r] Resume  ") | color(COLOR_TEXT_SECONDARY),
        text("│") | color(COLOR_BORDER),
        text("  [p] Portfolio  ") | color(COLOR_TEXT_SECONDARY),
        filler(),
        text("v1.0  ") | color(COLOR_TEXT_MUTED),
      }),
    });
  });

  // ═══════════════════════════════════════════════════════════════════════
  // ═ EVENT HANDLING ══════════════════════════════════════════════════════
  // ═══════════════════════════════════════════════════════════════════════

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
      openBrowser("https://www.linkedin.com/in/subhrajyoti-sahoo-b047a227a/");
      return true;
    }
    if (event == Event::Character('r')) {
      openBrowser("https://drive.google.com/file/d/1kJIWjLmJLDbWObUIbBL7U87Ote34z1y0/view");
      return true;
    }
    if (event == Event::Character('p')) {
      openBrowser("https://subhr.in");
      return true;
    }
    return false;
  });

  screen.Loop(app);
}