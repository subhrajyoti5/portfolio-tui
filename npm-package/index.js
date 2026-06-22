#!/usr/bin/env node

const os = require("os");
const path = require("path");
const { spawn } = require("child_process");

let binary;

switch (os.platform()) {
  case "win32":
    binary = path.join(__dirname, "bin", "windows", "subhra.exe");
    break;

  case "linux":
    binary = path.join(__dirname, "bin", "linux", "subhra");
    break;

  case "darwin":
    binary = path.join(__dirname, "bin", "macos", "subhra");
    break;

  default:
    console.error("Unsupported platform");
    process.exit(1);
}

spawn(binary, [], {
  stdio: "inherit"
});