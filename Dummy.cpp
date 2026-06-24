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