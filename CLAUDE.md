# CLAUDE.md

This file provides guidance to Claude Code (claude.ai/code) when working with code in this repository.

## Overview

LeetSpace is a personal archive of LeetCode solutions, and a training ground for competitive programming — solving problems is the point, so Claude never writes the actual solution logic (see "Solving a new problem" below). Each problem lives in its own numbered directory (e.g. `0011`, `3272`) containing a `solution.cpp` and a `test.yaml` describing the function signature and test cases. There are two parallel problem formats, described below — know which one you're touching before editing its build/test plumbing.

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

## Solving a new problem

The default for a new problem: it goes in `old-problems/`, solved in C++. A C solution for the same problem may be added later, but that's a separate, later effort (see "Adding a C solution" below) — don't scaffold or solve in C unless asked.

LeetCode blocks direct fetches of its problem pages (WebFetch gets HTTP 403), and web search / mirror sites don't reliably reproduce the exact constraints, examples, or hints — so the user pastes the problem's URL, statement, constraints, examples, and difficulty directly instead of Claude looking it up.

1. **Open the GitHub issue first**, before any scaffolding or code. Title it `Solve problem <id>. <Name>`. The body must link the LeetCode problem URL and give a brief comment on what the problem is and, if there's already an idea, a likely approach (skip the approach entirely if there isn't one yet). Don't restate what the LeetCode page already shows (full statement, constraints, examples) — anyone reading the issue is expected to follow the link for that.

2. **Scaffold the placeholder** in `old-problems/<id>/`, all in one commit titled `add test for problem <id>. <Name>`:
   - `CMakeLists.txt` — always just:
     ```cmake
     get_dir_name(id)
     add_problem_test(test-${id} test.yaml)
     ```
   - `test.yaml` — `old-problems/`-schema, with the example test cases from the LeetCode page under `test_cases`, named `example_1`, `example_2`, etc.
   - `solution.cpp` — a `class Solution` with the real method signature but no real logic yet. It still has to build clean under `add_check_warning(TREAT_WARNINGS_AS_ERRORS)` (from [CheckWarning.cmake](https://github.com/threeal/CheckWarning.cmake/tree/v3.2.0)), so:
     - include only the headers the signature actually needs (e.g. `<vector>`, `<string>`)
     - never leave a parameter unused — fold every parameter into the return expression instead (e.g. sum their `.size()`s, or return the one parameter there is)
     - return a validly-typed value (cast if needed) — it doesn't need to be a real answer, just something that compiles
   - a new row in `README.md`'s `## Problems` table for the problem, linking `./old-problems/<id>/solution.cpp` (see "README" below).

3. **Push and open the PR as a draft.** Branch `solve-problem-<id>`, PR title matching the issue title, body `This pull request resolves #<issue> by adding a C++ solution for [<id>. <Name>](<leetcode-url>).` plus a short paragraph on the approach if one's already known.

4. **Implement the solution — this step is the user's, not Claude's.** The point of this repo is training on competitive programming, so Claude does not write the solution logic. Claude's role resumes at committing what the user produces:
   - If a LeetCode submission fails on a test case, add that case to `test.yaml` as `test_case_<N>` (`<N>` is the test case number LeetCode reports, not a sequential count) in its own commit, `add test case <N> in problem <id>`, before the next attempt.
   - Once LeetCode accepts the solution, commit the final `solution.cpp` as `solve problem <id> in C++ by using <technique>`, push, and mark the PR ready for review (undraft it).

## Adding a C solution

Only after a problem's C++ solution has merged, and typically much later — a separate issue (`Solve problem <id>. <Name> in C`) and PR (branch `solve-problem-<id>-in-c`) follow the same shape as above: a scaffold commit (`add support to test problem <id> in C`) adding `c/solution.c` (placeholder, same unused-parameter/return-value rules as C++), `c/interface.cpp` (`extern "C"` glue calling into it), `test.yaml`'s `solutions.c:` entry, and `CMakeLists.txt`'s `add_c_solution`/`target_link_libraries` lines, then a solve commit (`solve problem <id> in C by using <technique>`) touching only `c/solution.c`. Don't start this unless asked.

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
