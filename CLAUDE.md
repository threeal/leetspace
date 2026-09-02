# CLAUDE.md

This file provides guidance to Claude Code (claude.ai/code) when working with code in this repository.

## Overview

LeetSpace is a personal archive of LeetCode solutions. Each problem lives in its own numbered directory (e.g. `0011`, `3272`) containing a `solution.cpp` and a `test.yaml` describing the function signature and test cases. There are two parallel problem formats, described below — know which one you're touching before editing its build/test plumbing.

## Problem formats

Despite the names, `old-problems/` is where new problems are currently added, and `problems/` is frozen. `problems/` was started alongside [threeal/leettest](https://github.com/threeal/leettest) as a proposed lighter-weight replacement format, but that effort stalled before it matched `old-problems/`'s feature set (notably, no C-solution support), so problem-adding reverted to `old-problems/`. Don't infer which format to use from the directory names — check for recent activity if unsure.

### `old-problems/` — actively developed

- Each `old-problems/<id>/` has a `solution.cpp`, a `CMakeLists.txt`, and a `test.yaml` using its own schema (`types.inputs`/`types.output`, `solutions` per language, `test_cases`).
- Some also have a `c/` subdirectory with a C solution (`solution.c`) plus `interface.c`/`interface.cpp` glue that exposes the C function to the generated C++ Catch2 test via `extern "C"`.
- These are built and tested locally through CMake + Catch2/CTest (see below). Add new problems here.

### `problems/` — frozen

- Each `problems/<id>/` contains only `solution.cpp` (a `class Solution { ... };` body, LeetCode-style) and `test.yaml`.
- `test.yaml` schema: a `cpp.function` block (`name`, `inputs` as `{type, value}` pairs, `output.type`) plus a `cases` list of `{name, inputs, output}`.
- No `CMakeLists.txt` per problem, and `problems/` is **not** added to the CMake build (the top-level `CMakeLists.txt` only adds `internal` and `old-problems`). These solutions are compiled and tested exclusively by the external `threeal/leettest-action` GitHub Action in CI (see `.github/workflows/ci.yaml`, job `test-solutions`), not by anything runnable locally in this repo.
- No new problems are being added here.

## Build & test (old-problems only)

Requires [Poetry](https://python-poetry.org/) to be installed — the CMake configure step runs `poetry install`, `isort`, and `black` on `internal/python` automatically.

```sh
cmake -B build -G Ninja      # configure
cmake --build build          # build
ctest --test-dir build       # run all tests
ctest --test-dir build -R '^2\.'     # run a single problem's test (by number; `^` avoids matching the number inside other problems' titles)
```

`problems/` (current-format) solutions aren't part of the CMake build, but can be compiled/tested locally with the [leettest](https://github.com/threeal/leettest) CLI (the same tool `leettest-action` runs in CI), via `pnpx`:

```sh
pnpx leettest                          # test all solution.cpp files matching **/solution.cpp
pnpx leettest problems/0011/solution.cpp   # test a single problem
```

## Formatting

- C/C++ style is Google-based with no column limit and no operand alignment (`.clang-format`).
- `cmake --build build --target fix-format` auto-fixes clang-format and cmake-format issues; `check-format` verifies without changing files.
- `lefthook` runs `clang-format -i` on staged `*.c`/`*.cpp` files as a pre-commit hook.

## Test generation (`internal/python`)

`internal/python/lib/generate_test_src` is a Poetry package (`generate_test_src` script) that reads an **old-problems-schema** `test.yaml` plus its `solution.cpp` and generates a Catch2 `test.cpp` and a wrapping `solution_cpp.cpp`. It's invoked automatically per problem by the `add_problem_test` CMake macro in `old-problems/CMakeLists.txt` — you should not need to run it directly. It does not understand the `problems/`-format `test.yaml` schema.

## README

`README.md` has a `## Problems` table linking every solved problem (by number) to its difficulty and solution file(s), covering both `problems/` and `old-problems/`. When adding a new solution, add a corresponding row.
