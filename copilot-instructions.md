# Copilot Instructions

## Project Shape
- This repository contains a static frontend at the repo root plus a C++17 backend under `backend/`.
- The frontend is plain HTML, CSS, and JavaScript. Keep changes compatible with that stack unless the user explicitly asks for a framework.
- The backend uses CMake, `vcpkg`, and `cpp-httplib`. Keep backend changes aligned with that build setup.
- Deployment uses Docker, Nginx, and monitoring services defined in the repo. Preserve that structure when making infrastructure-related edits.

## Frontend Guidance
- Prefer small, direct edits to `index.html`, `css/style.css`, `css/normalize.css`, and `js/main.js`.
- Keep markup semantic and accessible.
- Avoid introducing frontend tooling, bundlers, or framework assumptions unless the user asks for them.
- Preserve the existing static-site deployment model and file layout.

## Backend Guidance
- Keep backend code in `backend/src/main.cpp` and build changes in `backend/CMakeLists.txt` unless a new file is clearly justified.
- Preserve the existing HTTP routes and behavior for `/api/health`, `/api/contact`, and `/metrics` unless the task explicitly changes them.
- Maintain compatibility with C++17 and `httplib`.
- Keep CORS and metrics behavior consistent with the existing server unless the request is to change them.

## Deployment And Ops
- Treat `Dockerfile`, `backend/Dockerfile`, `docker-compose.yml`, `nginx/`, and `monitoring/` as operational surfaces.
- When editing deployment config, keep the static frontend, backend service, and monitoring stack working together.
- Do not assume `nginx/nginx.conf` contains production config unless you inspect it first.

## Editing Preferences
- Make the smallest change that solves the task.
- Preserve existing naming, formatting, and directory conventions.
- Do not remove or rewrite unrelated code.
- Avoid inventing scripts or workflows that are not already present in the repository.

## Validation Guidance
- Prefer narrow validation that matches the touched area.
- For backend changes, prefer building the backend target or checking the affected CMake files.
- For frontend changes, prefer local inspection and minimal static checks over adding new tooling.
- If a command or test does not exist in this repo, say so instead of assuming it does.