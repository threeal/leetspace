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

Only after a problem's C++ solution has merged — the C++ PR is often left open for days before that merge happens, and the C follow-up, if it happens at all, comes some time after the merge, not right after opening the C++ PR. The user will say when to start; don't propose it unprompted.

1. **Open the GitHub issue first**, before any scaffolding or code. Title it `Solve problem <id>. <Name> in C`. The body is much shorter than the C++ issue's: a sentence naming the problem (with its LeetCode link) plus a pointer to the C++ PR being followed (e.g. "the same approach as the C++ solution in #1234"), and, only if something already looks like it'll need to change, a short note on what.

2. **Scaffold the placeholder** in `old-problems/<id>/`, all in one commit titled `add support to test problem <id> in C`. The user supplies the C-style function signature to implement (LeetCode's C conventions — raw pointers/sizes, an output-size out-param, etc.) rather than Claude inventing one:
   - `CMakeLists.txt` — add the C build line before what's already there, and link it after:
     ```cmake
     add_c_solution(c_solution c/interface.cpp c/solution.c)

     get_dir_name(id)
     add_problem_test(test-${id} test.yaml)
     target_link_libraries(test-${id} PRIVATE ${c_solution})
     ```
   - `c/solution.c` — a placeholder implementing the given signature, with the same unused-parameter/return-value discipline as the C++ placeholder (fold every parameter into the return expression, return a validly-typed value — cast if needed).
   - `c/interface.cpp` — an `extern "C" { ... }` block re-declaring the C signature verbatim, plus a `solution_c` function whose parameter and return types match the C++ `Solution` method's (from `test.yaml`'s `types:` block). Its body just adapts between the two: unpacking C++ containers into raw pointers/sizes to call the C function, and re-wrapping a raw C return back into the C++ type if needed. Check an existing `c/interface.cpp` with a matching type shape for the exact conversion pattern.
   - `test.yaml` — add a blank `c:` key under `solutions:`, ordered before `cpp:` (no `function:` sub-key — the interface always exposes the fixed name `solution_c`).
   - `README.md`'s existing row for the problem — add `[C](./old-problems/<id>/c/solution.c)` before the `[C++]` link.

3. **Push and open the PR as a draft.** Branch `solve-problem-<id>-in-c`, PR title matching the issue title, body following the same "This pull request resolves #<issue>..." shape as the C++ PRs, naming the C++ PR being followed.

4. **Implement the solution — the user's step, same boundary as C++.** Following the C++ approach isn't always a straight port: C has no hash maps, sets, or other STL containers, so some C solutions hand-roll the equivalent structure or restructure the approach entirely to avoid needing one (see existing `old-problems/*/c/solution.c` files for examples) — don't assume the C version has to mirror the C++ logic line for line. Failing LeetCode submissions add `test_case_<N>` commits the same way as the C++ flow; once accepted, the final `c/solution.c` is committed as `solve problem <id> in C by using <technique>`, and the PR is marked ready for review.

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
